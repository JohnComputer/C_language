#include "slot.h"
#include <mysql.h>

void slot_play(int(*slot)[10], int gamecnt,int bet, char* id, char* pass, MYSQL* connection) {
	int i, j, k, z, temp = 0;						//for ������ ���� ������ temp = ���� �̵� �ӽ� ���� ����
	int disp_gamecnt_x = 10, disp_gamecnt_y = 1;	// ���� ���� ��ǥ
	int disp_bet_x = 45, disp_bet_y = 1;			// ���� ��ǥ
	int disp_credit_x = 80, disp_credit_y = 1;		// ũ���� ��ǥ
	int disp_winlose_x = 80, disp_winlose_y = 14;	// ���ð�� ��ǥ
	int x, y, slow, credit = 0,play_bet;			// ȭ��� �귿 ���� ��ġ ��ǥ/ Sleep�ӵ� ���� ���� / ������ ���ΰ� / ���� ��

	MYSQL_RES* sql_result = NULL;	// sql ��ɹ� ��� ���� 
	MYSQL_ROW row = NULL;			// ��ɹ� ����ÿ� ��ȯ�Ǵ� ���� ��.
	char query[100] = { 0 };		// ��ɹ� ���� ����
	int query_stat = 0;				// ��ɹ� ���� ���� ��.

	for (z = 0; z < gamecnt; z++) {		// slot �ʱ�ȭ
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 10; j++) {
				slot[i][j] = 0;
			}
		}
		slot_input_value(slot);	//slot�� ���� ���� �־��ش�.
		slow = 100;				// �߿�!! slot�� �귿 �ӵ��� �ٲ� �ֱ� ���ؼ� Sleep �Լ��� ���� �������� �� ����ֱ� ���� ����
		play_bet = bet;			// ���� �� �ҷ�����. �⺻ ���� 10
		sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);
		query_stat = mysql_query(connection, query);
		sql_result = mysql_store_result(connection);	// �����Ͱ˻��� ������ ������ ȣ�� ������ ��� �ΰ�
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
				//for������ �̿��Ͽ� �迭���� ���� ��ĭ�� ��ܼ� �������ش�.
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
				// ������ [3][10] �������� �迭�� ���ڸ� �о��־ ����� �迭�� [i][2]������ ���� �̾��ش�.
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
		// mysql_store_result() �Լ� �Ŀ� mysql_fetch_row()�Լ��� ���̻� �˻��� �ο찡 ������ NULL ���� ��, �˻��� �ȵǸ� NULL�� ���
		if (sql_result->row_count == 0) {		// �˻��Ǿ��� �Ҵ� �� ���� ������� row sql_result���� row_count�� 0 ���ΰ� Ȯ�� 
			printf("������ ���� ����");
		}
		Sleep(2000);
	}
}