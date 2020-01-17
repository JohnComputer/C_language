#include "taisai.h"

void taisai_main(int* id, int*  pass, MYSQL* connection) {
	int i = 0, gostop = 0;	 // i = for구문 / gostop = 배팅종료
	char game = NULL;		// 배팅게임 종류 변수
	int cnt = 0, rec_dice[10][4] = { 0 };		// 게임 판수 / 주사위들 과거 값 저장.
	int dice[3] = { 0 }, bet = 0, gamenum = 0;		// dice = 주사위 값, bet = 배팅 임시저장값, gamenum = 게임의 세부종류
	int x = 0, y = 43, onoff[8] = { 0 }, end = 1;	// x,y = 게임 관련 질문 좌표 / onoff = 게임종류별 실행여부 / end = 게임종료 
	int betsum = 0;

	MYSQL_RES* sql_result = NULL;	// sql 명령문 결과 저장 
	MYSQL_ROW row = NULL;			// 명령문 실행시에 반환되는 행의 값.
	char query[100] = { 0 };		// 명령문 저장 변수
	int query_stat = 0;				// 명령문 실행 상태 값.

	while (end != 0) {				//게임 종료 질문 값 확인.
		DICE playgame = { 0 };		// 배팅 초기화
		for (i = 0; i < 8; i++) {
			if (i < 3)
				dice[i] = 0;
			onoff[i] = 0;

		}
		while (1) {
			system("cls");
			taisai_reshow(rec_dice, playgame, 1);
			gotoxy(x, y);
			printf("어떤게임에 배팅하겠습니까? (a~h) : ");
			scanf(" %c", &game);
			printf("게임에 번호를 입력해 주세요. | a:2 | b:2 | c:6 | d:1 | e:6 | f:18 | g:15 | h:3 |");
			scanf("%d", &gamenum);
			printf("얼마를 배팅하겠습니까?? : ");
			scanf("%d", &bet);
			// 게임 선택 후 배팅 금액 지정
			switch (game)						// 게임 번호를 입력받고 배팅값을 넣음.
			{
			case 'a':
				if (gamenum > 2)
					break;
				playgame.Abigsmall[gamenum - 1] += bet;
				onoff[0] = 1;
				break;
			case 'b':
				if (gamenum > 2)
					break;
				playgame.Bevenodd[gamenum - 1] += bet;
				onoff[1] = 1;
				break;
			case 'c':
				if (gamenum > 6)
					break;
				playgame.Cpairdice[gamenum - 1] += bet;
				onoff[2] = 1;
				break;
			case 'd':
				playgame.Danytriple += bet;
				onoff[3] = 1;
				break;
			case 'e':
				if (gamenum > 6)
					break;
				playgame.Eseltriple[gamenum - 1] += bet;
				onoff[4] = 1;
				break;
			case 'f':
				if (gamenum > 18)
					break;
				playgame.Ftotal[gamenum - 1] += bet;
				onoff[5] = 1;
				break;
			case 'g':
				if (gamenum > 15)
					break;
				playgame.Gdomino[gamenum - 1] += bet;
				onoff[6] = 1;
				break;
			case 'h':
				if (gamenum > 6)
					break;
				playgame.Hsingle[gamenum - 1] += bet;
				onoff[7] = 1;
				break;
			default:
				printf("게임번호를 다시 확인하여 주세요.");
				break;
			}
			system("cls");
			taisai_reshow(rec_dice, playgame, 1);
			gotoxy(x, y);
			printf("배팅을 그만하시겠습니까?? 0.그만");
			gotoxy(x, y+1);
			printf("계속하려면 아무거나 입력하시오. : ");
			scanf("%d", &gostop);
			if (gostop == 0)
				break;
		}
		system("cls");
		taisai_reshow_board();
		taisai_show(dice,rec_dice,cnt);						// 주사위를 굴려준다
		taisai_reshow(rec_dice, playgame, 0);		// 0을 주어 보드판을 빼고 게임 화면을 보여준다.
		cnt++;
		betsum = taisai_calc(dice, onoff, playgame);		// 게임의 값들을 계산한다.
		puts(""); // 띄어쓰기
		sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);
		query_stat = mysql_query(connection, query);
		sql_result = mysql_store_result(connection);	// 데이터검색에 성공한 쿼리에 호출 실패의 경우 널값

		while ((row = mysql_fetch_row(sql_result))) {
			gotoxy(20, 15);
			printf("ID : %s   COIN : %d\n", row[0],atoi(row[2]));
			// 중요!!!!!!!!!!!!!!!!!!!!! atoi를 통하여 ascii to interger 문자열 형태를 숫자로 바꿔 주어야 %d로 출력도 가능하고 int로 사용가능!!
			betsum += atoi(row[2]);
			_getch();
			break;
		}
		sprintf(query, "UPDATE member SET coin = %d where id = '%s' AND pass = '%s'", betsum, id, pass);
		query_stat = mysql_query(connection, query);
		gotoxy(20, 16);
		printf("배팅금액 DB저장 완료\n");

		// mysql_store_result() 함수 후에 mysql_fetch_row()함수는 더이상 검색한 로우가 없으면 NULL 리턴 즉, 검색이 안되면 NULL값 출력
		if (sql_result->row_count == 0) {		// 검색되어져 할당 된 것이 없을경우 row sql_result안의 row_count가 0 값인거 확인 
			printf("데이터 갱신 실패");
		}
		gotoxy(25, 3);
		printf("게임을 종료하시겠습니까?? 0.종료");
		scanf("%d", &end);
	}
	system("mode con cols=105 lines=25");
}