#include "casino.h"
// ------------------------------- main --------------------------------------------------------
int main() {
	int x = 34, y = 14; // 화살표 좌표 입력
	int sel, rankcnt;		// getch로 입력받은 아스키코드 저장 / rank 저장

	MYSQL* connection = NULL, conn; // sql 연결 상태 / 연결 설정 변수
	MYSQL_RES* sql_result = NULL;	// sql 명령문 결과 저장 
	MYSQL_ROW row = NULL;			// 명령문 실행시에 반환되는 행의 값.

	char id[15] = { 0 };			// 입력받는 ID
	char pass[15] = { 0 };			// 입력받는 PASSWD
	int coin, login = 0;			// 가입시 필요한 코인 변수 / login 상태 변수
	int getcoin = 0;				//임시저장 코인
	int recoin;						// 충전 코인

	char query[100] = { 0 };		// query 명령문
	int query_stat = 0;				// 명령문 실행 상태 값.

	mysql_init(&conn); 
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	//mysql 접속 데이터베이스 연결 (connection 확인)

	if (connection == NULL) {	// 접속 실패시 에러 메세지
		printf("connect error!\n");
		exit(1);
	}

	system("mode con cols=105 lines=30"); //시작시에 화면 크기 지정

	srand((unsigned)time(NULL));	// srand로 난수표에 seed 값 지정 처음 실행시에 한번만 해주면 됨.

	while (1) {
		query_stat = 0;

		while (1) {
			system("cls");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("    /$$$$$$ /$$   /$$  /$$$$$$         /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$     \n");
			printf("   |_  $$_/| $$$ | $$ /$$__  $$       /$$__  $$ /$$__  $$ /$$__  $$|_  $$_/| $$$ | $$ /$$__  $$    \n");
			printf("     | $$  | $$$$| $$| $$  ' $$      | $$  '__/| $$  ' $$| $$  '__/  | $$  | $$$$| $$| $$  ' $$    \n");
			printf("     | $$  | $$ $$ $$| $$  | $$      | $$      | $$$$$$$$|  $$$$$$   | $$  | $$ $$ $$| $$  | $$    \n");
			printf("     | $$  | $$  $$$$| $$  | $$      | $$      | $$__  $$ '____  $$  | $$  | $$  $$$$| $$  | $$    \n");
			printf("     | $$  | $$'  $$$| $$  | $$      | $$    $$| $$  | $$ /$$  ' $$  | $$  | $$'  $$$| $$  | $$    \n");
			printf("    /$$$$$$| $$ '  $$|  $$$$$$/      |  $$$$$$/| $$  | $$|  $$$$$$/ /$$$$$$| $$ '  $$|  $$$$$$/    \n");
			printf("   |______/|__/  '__/ '______/        '______/ |__/  |__/ '______/ |______/|__/  '__/ '______/     \n");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("                                     1. 로그인                                                      \n");
			printf("                                     2. 회원가입                                                     \n");
			printf("                                     3. BLACK JACK                                                 \n");
			printf("                                     4. TAI SAI (SIC BO)                                           \n");
			printf("                                     5. SLOT 777                                                   \n");
			printf("                                     6. 코인 충전                                                   \n");
			printf("                                     7. 순위표                                                     \n");
			printf("                                     8. 게임종료                                                    \n");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("                                                                                   Make by INO     \n");
			printf("                                                                                 Design by INO     \n");
			printf("                                                                           bizbyinho@gmail.com     \n");


			gotoxy(x, y);
			printf("▶");
			if (_kbhit()) {	// 키 입력 받으면 실행
				sel = _getch();	// 입력 받은키 sel에 저장
				// 방향키는 처음에 224 를 주고 그 다음 한번더 아스키코드를 받기때문에 다른키와 구별을 위해 224를 준다.
				//밑에 y 값이 메뉴좌표값 초과하지 못하도록 하는 if문
				if (sel == 224) {
					sel = _getch();
					if (sel == UPKEY)
						y--;
					if (sel == DOWNKEY)
						y++;
				}
				if (sel == ENTER)
					break;
				if (y == 13)
					y++;
				if (y == 22)
					y--;
			}
			Sleep(100);
		}
		switch (y) {
		case LOGIN:
			system("cls");
			printf("\t< 로그인 >\n\n");
			printf("아이디 : ");
			scanf(" %s", id);			// 아이디와 패스워드 공백 입력 버퍼 처리 띄워써서 받는다.

			printf("패스워드 : ");
			scanf(" %s", pass);


			sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass); // MYSQL 조회 명령문 저장
			query_stat = mysql_query(connection, query);	// MYSQL 명령문 실행
			sql_result = mysql_store_result(connection);	// 데이터검색에 성공한 쿼리에 호출 실패의 경우 널값

			while ((row = mysql_fetch_row(sql_result))) {
				printf("로그인 성공\n");
				printf("ID : %s PASSWORD: %s COIN : %d\n", row[0], row[1], atoi(row[2])); 
				login = 1;	// 로그인 확인 변수.
				// 중요!!!!!!!!!!!!!!!!!!!!! atoi를 통하여 ascii to interger 문자열 형태를 숫자로 바꿔 주어야 %d로 출력도 가능하고 int로 사용가능!!
				break;
			}
			// mysql_store_result() 함수 후에 mysql_fetch_row()함수는 더이상 검색한 로우가 없으면 NULL 리턴 즉, 검색이 안되면 NULL값 출력
			if (sql_result->row_count == 0) {		// 검색되어져 할당 된 것이 없을경우 row sql_result안의 row_count가 0 값인거 확인 
				printf("로그인실패");
			}
			mysql_free_result(sql_result); // 결과셋에 할당된 메모리 제거
			_getch();
			break;

		case REGISTER:
			system("cls");
			// 아이디와 패스워드 공백 입력 버퍼 처리 띄워써서 받는다.
			printf("가입할 아이디를 입력하여 주세요. : ");
			scanf(" %s", id);

			printf("가입할 패스워드를 입력하여 주세요 : ");
			scanf(" %s", pass);

			printf("COIN을 넣어주세요. : \n");
			scanf("%d", &coin);

			sprintf(query, "insert into member values" "('%s', '%s', '%d')", id, pass, coin);	// MYSQL 데이터 입력 명령문 저장
			query_stat = mysql_query(connection, query);										// MYSQL 데이터 입력 명령문 실행

			if (query_stat != 0) {
				fprintf(stderr, "쿼리에러 : %s", mysql_error(&conn));
				_getch();
				break;
			}

			printf("가입성공");
			_getch();
			break;
		case BLACKJACK:
			if (login == 1) {		// 로그인 확인 후 실행 로그인 되어있지 않을경우 그자리에 프린트 문 출력.
				system("mode con cols=75 lines=30");
				blackjack_intro(id,pass,connection);
				break;
			}
			printf("로그인 먼저 부탁드립니다.");
			_getch();
			break;
		case TAISAI:
			if (login == 1) {		// 로그인 확인 후 실행 로그인 되어있지 않을경우 그자리에 프린트 문 출력.
				system("mode con cols=90 lines=30");
				taisai_intro(id, pass, connection);
				break;
			}
			printf("로그인 먼저 부탁드립니다.");
			_getch();
			break;
		case SLOT:
			if (login == 1) {		// 로그인 확인 후 실행 로그인 되어있지 않을경우 그자리에 프린트 문 출력.
				system("mode con cols=50 lines=30");
				slot_intro(id, pass, connection);
				break;
			}
			printf("로그인 먼저 부탁드립니다.");
			_getch();
			break;
		case COIN:
			system("cls");
			printf("\t코인을 충전합니다\n");
			printf("충전할 아이디 : ");
			scanf(" %s", id);

			printf("패스워드 : ");
			scanf(" %s", pass);

			sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);	// MYSQL 조회 명령문 저장
			query_stat = mysql_query(connection, query);	// MYSQL 명령문 실행
			sql_result = mysql_store_result(connection);	// 데이터검색에 성공한 쿼리에 호출 실패의 경우 널값

			while ((row = mysql_fetch_row(sql_result))) {
				printf("현재 잔액 코인 : %d\n",atoi(row[2])); 
				// atoi를 통하여 ascii to interger 문자열 형태를 숫자로 바꿔 주어야 %d로 출력도 가능하고 int로 사용가능!!
				getcoin = atoi(row[2]);
			}
			// mysql_store_result() 함수 후에 mysql_fetch_row()함수는 더이상 검색한 로우가 없으면 NULL 리턴 즉, 검색이 안되면 NULL값 출력
			if (sql_result->row_count == 0) {		// 검색되어져 할당 된 것이 없을경우 row sql_result안의 row_count가 0 값인거 확인 
				printf("로그인실패");
				_getch();
				break;
			}
			// 로그인 확인 후 완료 후 아래에서 저장.
			printf("충전하고자 하는 코인을 입력하세요. : ");
			scanf("%d", &recoin);
			getcoin += recoin;			// 현재 코인과 충전 받기로 한 코인 합
			sprintf(query, "UPDATE member SET coin = %d where id = '%s' AND pass = '%s'",getcoin, id, pass);// MYSQL 수정 명령문 저장
			query_stat = mysql_query(connection, query);		// MYSQL 수정 명령문 실행
			printf("코인 : %5d  충전완료 ", recoin);
			_getch();
			break;
		case RANKING:
			system("cls");
			rankcnt = 0;
			sprintf(query, "select * from member ORDER BY 3 DESC");	// MYSQL 순위 명령문 저장
			query_stat = mysql_query(connection, query);			// MYSQL 순위 명령문 실행
			sql_result = mysql_store_result(connection);   // 데이터검색에 성공한 쿼리에 호출 실패의 경우 널값
			printf(".-----------------------------------------------.\n");
			printf("     랭킹                  ID       코인     \n");
			while ((row = mysql_fetch_row(sql_result))) {
				rankcnt++;
				printf("\t%d\t%14s\t%10d\n", rankcnt, row[0], atoi(row[2]));
				//atoi를 통하여 ascii to interger 문자열 형태를 숫자로 바꿔 주어야 %d로 출력도 가능하고 int로 사용가능!!
			}
			// mysql_store_result() 함수 후에 mysql_fetch_row()함수는 더이상 검색한 로우가 없으면 NULL 리턴 즉, 검색이 안되면 NULL값 출력
			printf("'-----------------------------------------------'\n");
			mysql_free_result(sql_result); // 결과셋에 할당된 메모리 제거
			_getch();
			break;
		case END:
			mysql_close(connection); // 연결 해제!!
			return 0;
		}
	}
}