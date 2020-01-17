#include "slot.h"
#include <mysql.h>

void slot_play(int(*slot)[10], int gamecnt,int bet, char* id, char* pass, MYSQL* connection) {
	int i, j, k, z, temp = 0;						//for 구문을 위한 변수들 temp = 값의 이동 임시 저장 변수
	int disp_gamecnt_x = 10, disp_gamecnt_y = 1;	// 게임 디스플 좌표
	int disp_bet_x = 45, disp_bet_y = 1;			// 베팅 좌표
	int disp_credit_x = 80, disp_credit_y = 1;		// 크레딧 좌표
	int disp_winlose_x = 80, disp_winlose_y = 14;	// 배팅결과 좌표
	int x, y, slow, credit = 0,play_bet;			// 화면상 룰렛 순서 위치 좌표/ Sleep속도 조절 변수 / 보유한 코인값 / 배팅 값

	MYSQL_RES* sql_result = NULL;	// sql 명령문 결과 저장 
	MYSQL_ROW row = NULL;			// 명령문 실행시에 반환되는 행의 값.
	char query[100] = { 0 };		// 명령문 저장 변수
	int query_stat = 0;				// 명령문 실행 상태 값.

	for (z = 0; z < gamecnt; z++) {		// slot 초기화
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 10; j++) {
				slot[i][j] = 0;
			}
		}
		slot_input_value(slot);	//slot에 값을 집어 넣어준다.
		slow = 100;				// 중요!! slot의 룰렛 속도를 바꿔 주기 위해서 Sleep 함수에 점점 느려지는 값 집어넣기 위한 변수
		play_bet = bet;			// 배팅 값 불러오기. 기본 새팅 10
		sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);
		query_stat = mysql_query(connection, query);
		sql_result = mysql_store_result(connection);	// 데이터검색에 성공한 쿼리에 호출 실패의 경우 널값
		while ((row = mysql_fetch_row(sql_result))) {
			credit = atoi(row[2]);
			break;
		}
		for (k = 0; k < 20; k++) {
			system("cls");
			slot_disp_board();
			gotoxy(disp_gamecnt_x, disp_gamecnt_y);
			printf("%d", gamecnt - z);
			gotoxy(disp_bet_x, disp_bet_y);
			printf("%d", play_bet);
			gotoxy(disp_credit_x, disp_credit_y);
			printf("%d", credit);
			for (i = 0; i < 3; i++) {		
				//for구문을 이용하여 배열들의 값을 한칸씩 당겨서 변경해준다.
				temp = slot[i][0];
				slot[i][0] = slot[i][1];
				slot[i][1] = slot[i][2];
				slot[i][2] = slot[i][3];
				slot[i][3] = slot[i][4];
				slot[i][4] = slot[i][5];
				slot[i][5] = slot[i][6];
				slot[i][6] = slot[i][7];
				slot[i][7] = slot[i][8];
				slot[i][8] = slot[i][9];
				slot[i][9] = temp;
			}
			for (i = 0; i < 3; i++) {	
				// 위에서 [3][10] 사이즈의 배열의 숫자를 밀어주어서 출력은 배열의 [i][2]까지의 값을 뽑아준다.
				if (i == 0)
					x = 12;
				if (i == 1)
					x = 31;
				if (i == 2)
					x = 50;
				y = 4;
				for (j = 2; j >= 0; j--) {
					switch (slot[i][j]) {
					case 1:
						Aform(x, y);
						break;
					case 2:
						Kform(x, y);
						break;
					case 3:
						Sform(x, y);
						break;
					case 4:
						SEVENform(x, y);
						break;
					default:
						break;
					}
					y += 5;
				}
			}
			slow += 20;
			Sleep(slow);
		}
		play_bet = slot_calc(slot, play_bet);
		if (play_bet > 0) {
			gotoxy(disp_winlose_x, disp_winlose_y);
			printf("win  %d", play_bet);
		}
		else {
			gotoxy(disp_winlose_x, disp_winlose_y);
			printf("lose  %d", play_bet);
		}
		play_bet += credit;
		sprintf(query, "UPDATE member SET coin = %d where id = '%s' AND pass = '%s'", play_bet, id, pass);
		query_stat = mysql_query(connection, query);
		// mysql_store_result() 함수 후에 mysql_fetch_row()함수는 더이상 검색한 로우가 없으면 NULL 리턴 즉, 검색이 안되면 NULL값 출력
		if (sql_result->row_count == 0) {		// 검색되어져 할당 된 것이 없을경우 row sql_result안의 row_count가 0 값인거 확인 
			printf("데이터 갱신 실패");
		}
		Sleep(2000);
	}
}