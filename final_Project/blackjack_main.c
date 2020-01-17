#include "blackjack.h"
//--------------------------------------- 블랙잭 게임의 메인 함수 역할 -----------------------------------------------------------------
void blackjack_main(int* id, int* pass, MYSQL* connection) {
	int i = 0, j = 0;				// for 구문
	int playerNum = 0, betsum = 0;			// 플레이어의 숫자
	int bet[3] = { 0 };	// 플레이어 수 만큼의 배팅 금액 
	int blackjack_card[3][52];		// 카드 덱
	int stopcard = 0;				// 플레이어 종료 변수
	char YN = NULL;					// 카드 히팅 변수
	int playing[4][8];
	// 0은 딜러 1~3 은 플레이어로 가정하자 카드는 8장까지 받을 수 있다. <- 추후 화면사이즈 고려 수정
	int cnt[4] = { 0 }, sum[4] = { 0 }, player_stopcard[3] = { 0 }, die[4] = { 0 };
	// cnt = 받은 카드의 수, sum = 점수 합계, player_stopcard = 카드 히팅 확인 변수, die ( 0 = 초과, 1 = blackjack)

	MYSQL_RES* sql_result = NULL;	// sql 명령문 결과 저장 
	MYSQL_ROW row = NULL;			// 명령문 실행시에 반환되는 행의 값.
	char query[100] = { 0 };		// 명령문 저장 변수
	int query_stat = 0;				// 명령문 실행 상태 값.

	int disp_x = 48, disp_y = 5;					// 게임 진행과정 등 출력 위치
	int player_x[3] = { 7, 47, 87 }, player_y = 15; // 플레이어 화면 출력
	int dealer_x = 40, dealer_y = 7;				// 딜러 화면 출력

	card_suffle(blackjack_card);						// 먼저 카드에 값을 넣어준다.
	blackjack_get_player(&playerNum, player_x, player_y);		// 참가테이블이 몇개인지 지정한다.
	blackjack_disp_board();									// 보드를 출력한다.
	Sleep(500);
	blackjack_betting(&playerNum, bet, player_x, player_y);		// 각각의 자리에 배팅금액을 입력받는다.

	for (i = 0; i <= playerNum; i++) {
		for (j = 0; j < 2; j++) {
			insert_deck(i, j, cnt, playing, blackjack_card);			// 참가자들에게 2장의 카드를 먼저 준다.
			if (i == 0) {
				if (j == 0) {
					show_card(dealer_x, dealer_y, playing[i][j]);	// 딜러의 경우 첫시작에 한장의 카드만 오픈한다.
					Sleep(500);
				}
				else {
					back_card(dealer_x + 9, dealer_y);
					Sleep(500);
				}
			}
			else {
				show_card(player_x[i - 1] + (j * 9), player_y, playing[i][j]); // 참가자의 카드는 오픈한다.
				Sleep(500);
			}
		}
	}
	// 카드값을 출력해준다.
	for (i = 1; i <= playerNum; i++) {
		blackjack_calc(playing, i, cnt[i], sum, die, &stopcard, player_stopcard);
		gotoxy(player_x[i - 1], player_y + 9);
		printf("player %d 카드값 : %d", i, sum[i]);
		Sleep(500);
	}
	// 각 테이블에 있는 카드에 카드를 더 받을 것인지 묻는다.
	stopcard = 3 - playerNum;		// 플레이어가 몇명인지에 따라서 3-n 을 하여 stopcard 값을 맞춰준다.
	for (j = 2; stopcard != 3; j++) {
		for (i = 1; i <= playerNum; i++) {
			if (player_stopcard[i - 1] != 1) {
				blackjack_reshow(playerNum, cnt, playing, sum, bet, die, 0);
				gotoxy(disp_x, disp_y);
				printf("player %d 카드를 받겠습니까?(Y/N) : ", i);
				scanf(" %c", &YN);
				if (YN == 'y' || YN == 'Y') {
					insert_deck(i, j, cnt, playing, blackjack_card);			// 카드를 히트하게 되면 바로 보여지면서 계산이 된다.
					show_card(105,3, playing[i][j]);							// A일경우 계산전 오른쪽 상단에 카드를 먼저 보여줌 
					blackjack_calc(playing, i, cnt[i], sum, die, &stopcard, player_stopcard);
				}
				else if (YN == 'n' || YN == 'N') {
					stopcard++;
					player_stopcard[i - 1] = 1;
				}
				else {
					gotoxy(disp_x, disp_y - 1);
					printf("숫자를 확인해주세요... ");
					_getch();
					i--;
				}
			}
		}
	}
	blackjack_reshow(playerNum, cnt, playing, sum, bet, die, 1);			// 모든 히팅이 끝나면 다시 화면에 보여지고 계산을 진행한다.
	blackjack_calc(playing, 0, cnt[0], sum, die, &stopcard, player_stopcard);
	_getch();
	j = 1;
	while (die[0] != 1) {		// 딜러의 경우 합이 16이하면 드로우 - 16초과이면 카드를 스탑한다.
		j++;
		gotoxy(disp_x, disp_y);
		printf("딜러의 합 : %d", sum[0]);
		_getch();
		if (sum[0] <= 16) {
			gotoxy(disp_x, disp_y + 1);
			printf("카드를 드로우합니다.");
			_getch();
			insert_deck(0, j, cnt, playing, blackjack_card);
			blackjack_calc(playing, 0, cnt[0], sum, die, &stopcard, player_stopcard);
		}
		else {
			die[0] = 1; //임시 종료 DB연동시 돈주고 받는 부분
			break;
		}
		_getch();
		blackjack_reshow(playerNum, cnt, playing, sum, bet, die, 1);
	}

	betsum = blackjack_finish(sum, die, bet);		// 게임이 끝나고 전체 배팅결과 금액 정산 후 betsum 변수에 결과값 저장.
	system("cls");

	printf(" '--------------------------------------'\n");
	for (i = 1; i <= playerNum; i++) {
		if (bet[i - 1] < 0) {
			printf(" |  lose   %d 플레이 배팅정산 :  %5d'  |\n", i, bet[i - 1]);
		}else{
			printf(" |   win   %d 플레이 배팅정산 :  %5d'  |\n", i, bet[i - 1]);
		}
	}
	printf(" |--------------------------------------|\n");
	printf(" |        총 배팅정산 금액 :  %5d'    |\n",betsum);
	printf(" '--------------------------------------'\n");

	sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);	// MYSQL 조회 명령문 저장 id,pass는 로그인시 입력한값 받아옴.
	query_stat = mysql_query(connection, query);	// MYSQL 명령문 실행, connection으로 연결 상태와 위에 저장한  query문 대입.
	sql_result = mysql_store_result(connection);	// 데이터검색에 성공한 쿼리에 호출 실패의 경우 널값

	while ((row = mysql_fetch_row(sql_result))) {	// 명령문의 실행 결과 행 반환.
		printf("ID : %s \t COIN : %d\n", row[0], atoi(row[2]));
		// atoi를 통하여 ascii to interger 문자열 형태를 숫자로 바꿔 주어야 %d로 출력도 가능하고 int로 사용가능!!
		betsum += atoi(row[2]);
		break;
	}

	printf("정산금액 : %d\n", betsum);
	sprintf(query, "UPDATE member SET coin = %d where id = '%s' AND pass = '%s'", betsum, id, pass);	// DB저장 명령문 저장.
	query_stat = mysql_query(connection, query);	// DB저장 명령문 실행.
	printf("배팅금액 DB저장 완료\n");

	// mysql_store_result() 함수 후에 mysql_fetch_row()함수는 더이상 검색한 로우가 없으면 NULL 리턴 즉, 검색이 안되면 NULL값 출력
	if (sql_result->row_count == 0) {		// 검색되어져 할당 된 것이 없을경우 row sql_result안의 row_count가 0 값인거 확인 
		printf("데이터 갱신 실패");
	}
	_getch();
}