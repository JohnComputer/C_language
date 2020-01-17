#include "slot.h"
#include <mysql.h>

#define LEFTKEY 75		//���⼱ ���� ������ ��ư �� ASCII �ڵ� ��.
#define RIGHTKEY 77
#define ENTER 13

void slot_main(char* id, char* pass, MYSQL* connection) // id , pass �α��ν� �Է��� ���̵�� ����� ����
{
	system("mode con cols=120 lines=40");

	int slot[3][10] = { 0 };		// �߿�! slot�� 10/4 , 10/3, 10/2 �� Ȯ�� ���� �������� �ִ´�.
	int sel, x = BUTTON_UP, y = 23, gamecnt = 0, i = 0, j = 0;	// ���� / x = ��ư��ǥ ���ʰ� / y = ��ư ��ǥ / ���� ī��Ʈ / for����
	int disp_bet_x = 45, disp_bet_y = 1;		// �� ��ǥ
	int disp_credit_x = 80, disp_credit_y = 1;	// ũ���� ��ǥ
	int bet = 10, credit = 0;					// �� �ʱⰪ / ũ���� �ʱ�ȭ

	MYSQL_RES* sql_result = NULL;	// sql ��ɹ� ��� ���� 
	MYSQL_ROW row = NULL;			// ��ɹ� ����ÿ� ��ȯ�Ǵ� ���� ��.
	char query[100] = { 0 };		// ��ɹ� ���� ����
	int query_stat = 0;				// ��ɹ� ���� ���� ��.

	//x = BUTTON_UP;
	//bet = 10;

	while (1) {
		gamecnt = 0;
		y = 23;
		sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);
		query_stat = mysql_query(connection, query);
		sql_result = mysql_store_result(connection);	// �����Ͱ˻��� ������ ������ ȣ�� ������ ��� �ΰ�
		while ((row = mysql_fetch_row(sql_result))) {
			credit = atoi(row[2]);	//atoi�� ����ȯ.
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
			printf("��");
			if (_kbhit()) {
				sel = _getch();
				// ����Ű�� ó���� 224 �� �ְ� �� ���� �ѹ��� �ƽ�Ű�ڵ带 �ޱ⶧���� �ٸ�Ű�� ������ ���� 224�� �ش�.
				//�ؿ� y ���� �޴���ǥ�� �ʰ����� ���ϵ��� �ϴ� if��
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
		case BUTTON_UP:		// ���� �� 10 �� ����
			bet += 10;
			break;
		case BUTTON_DOWN:	// ���� �� 10 �� ����
			bet -= 10;
			break;
		case BUTTON_TEN:	// ���� Ƚ�� 10,50,100 �ڵ� ����
			gamecnt = 10;
			break;
		case BUTTON_FIFTY:
			gamecnt = 50;
			break;
		case BUTTON_HUNDRED:
			gamecnt = 100;
			break;
		case BUTTON_START:	// ���Ǿ� �귿����
			gamecnt = 1;
			break;
		}
		if (gamecnt != 0) {
			slot_play(slot, gamecnt, bet, id, pass, connection);
		}
	}
}