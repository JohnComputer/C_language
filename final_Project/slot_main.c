#include "slot.h"
#include <mysql.h>

#define LEFTKEY 75		//여기선 왼쪽 오른쪽 버튼 들어감 ASCII 코드 값.
#define RIGHTKEY 77
#define ENTER 13

void slot_main(char* id, char* pass, MYSQL* connection) // id , pass 로그인시 입력한 아이디와 비번을 받음
{
	system("mode con cols=120 lines=40");

	int slot[3][10] = { 0 };		// 중요! slot에 10/4 , 10/3, 10/2 등 확률 값을 랜덤으로 넣는다.
	int sel, x = BUTTON_UP, y = 23, gamecnt = 0, i = 0, j = 0;	// 선택 / x = 버튼좌표 최초값 / y = 버튼 좌표 / 게임 카운트 / for구문
	int disp_bet_x = 45, disp_bet_y = 1;		// 벳 좌표
	int disp_credit_x = 80, disp_credit_y = 1;	// 크레딧 좌표
	int bet = 10, credit = 0;					// 벳 초기값 / 크레딧 초기화

	MYSQL_RES* sql_result = NULL;	// sql 명령문 결과 저장 
	MYSQL_ROW row = NULL;			// 명령문 실행시에 반환되는 행의 값.
	char query[100] = { 0 };		// 명령문 저장 변수
	int query_stat = 0;				// 명령문 실행 상태 값.

	//x = BUTTON_UP;
	//bet = 10;

	while (1) {
		gamecnt = 0;
		y = 23;
		sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);
		query_stat = mysql_query(connection, query);
		sql_result = mysql_store_result(connection);	// 데이터검색에 성공한 쿼리에 호출 실패의 경우 널값
		while ((row = mysql_fetch_row(sql_result))) {
			credit = atoi(row[2]);	//atoi로 형변환.
			break;
		}
		while (1) {
			system("cls");
			slot_disp_board();
			gotoxy(disp_bet_x, disp_bet_y);
			printf("%d", bet);
			gotoxy(disp_credit_x, disp_credit_y);
			printf("%d", credit);
			gotoxy(x, y);
			printf("▲");
			if (_kbhit()) {
				sel = _getch();
				// 방향키는 처음에 224 를 주고 그 다음 한번더 아스키코드를 받기때문에 다른키와 구별을 위해 224를 준다.
				//밑에 y 값이 메뉴좌표값 초과하지 못하도록 하는 if문
				if (sel == 224) {
					sel = _getch();
					if (sel == RIGHTKEY) {
						if (x == BUTTON_UP)
							x = BUTTON_DOWN;
						else if (x == BUTTON_DOWN)
							x = BUTTON_TEN;
						else if (x == BUTTON_TEN)
							x = BUTTON_FIFTY;
						else if (x == BUTTON_FIFTY)
							x = BUTTON_HUNDRED;
						else if (x == BUTTON_HUNDRED)
							x = BUTTON_START;
					}
					if (sel == LEFTKEY) {
						if (x == BUTTON_DOWN)
							x = BUTTON_UP;
						else if (x == BUTTON_TEN)
							x = BUTTON_DOWN;
						else if (x == BUTTON_FIFTY)
							x = BUTTON_TEN;
						else if (x == BUTTON_HUNDRED)
							x = BUTTON_FIFTY;
						else if (x == BUTTON_START)
							x = BUTTON_HUNDRED;
					}
				}
				if (sel == ENTER)
					break;
			}
			Sleep(100);
		}
		switch (x) {
		case BUTTON_UP:		// 배팅 값 10 씩 증가
			bet += 10;
			break;
		case BUTTON_DOWN:	// 배팅 값 10 씩 감소
			bet -= 10;
			break;
		case BUTTON_TEN:	// 게임 횟수 10,50,100 자동 게임
			gamecnt = 10;
			break;
		case BUTTON_FIFTY:
			gamecnt = 50;
			break;
		case BUTTON_HUNDRED:
			gamecnt = 100;
			break;
		case BUTTON_START:	// 한판씩 룰렛돌림
			gamecnt = 1;
			break;
		}
		if (gamecnt != 0) {
			slot_play(slot, gamecnt, bet, id, pass, connection);
		}
	}
}