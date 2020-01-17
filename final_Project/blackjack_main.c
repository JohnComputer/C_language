#include "blackjack.h"
//--------------------------------------- ���� ������ ���� �Լ� ���� -----------------------------------------------------------------
void blackjack_main(int* id, int* pass, MYSQL* connection) {
	int i = 0, j = 0;				// for ����
	int playerNum = 0, betsum = 0;			// �÷��̾��� ����
	int bet[3] = { 0 };	// �÷��̾� �� ��ŭ�� ���� �ݾ� 
	int blackjack_card[3][52];		// ī�� ��
	int stopcard = 0;				// �÷��̾� ���� ����
	char YN = NULL;					// ī�� ���� ����
	int playing[4][8];
	// 0�� ���� 1~3 �� �÷��̾�� �������� ī��� 8����� ���� �� �ִ�. <- ���� ȭ������� ��� ����
	int cnt[4] = { 0 }, sum[4] = { 0 }, player_stopcard[3] = { 0 }, die[4] = { 0 };
	// cnt = ���� ī���� ��, sum = ���� �հ�, player_stopcard = ī�� ���� Ȯ�� ����, die ( 0 = �ʰ�, 1 = blackjack)

	MYSQL_RES* sql_result = NULL;	// sql ��ɹ� ��� ���� 
	MYSQL_ROW row = NULL;			// ��ɹ� ����ÿ� ��ȯ�Ǵ� ���� ��.
	char query[100] = { 0 };		// ��ɹ� ���� ����
	int query_stat = 0;				// ��ɹ� ���� ���� ��.

	int disp_x = 48, disp_y = 5;					// ���� ������� �� ��� ��ġ
	int player_x[3] = { 7, 47, 87 }, player_y = 15; // �÷��̾� ȭ�� ���
	int dealer_x = 40, dealer_y = 7;				// ���� ȭ�� ���

	card_suffle(blackjack_card);						// ���� ī�忡 ���� �־��ش�.
	blackjack_get_player(&playerNum, player_x, player_y);		// �������̺��� ����� �����Ѵ�.
	blackjack_disp_board();									// ���带 ����Ѵ�.
	Sleep(500);
	blackjack_betting(&playerNum, bet, player_x, player_y);		// ������ �ڸ��� ���ñݾ��� �Է¹޴´�.

	for (i = 0; i <= playerNum; i++) {
		for (j = 0; j < 2; j++) {
			insert_deck(i, j, cnt, playing, blackjack_card);			// �����ڵ鿡�� 2���� ī�带 ���� �ش�.
			if (i == 0) {
				if (j == 0) {
					show_card(dealer_x, dealer_y, playing[i][j]);	// ������ ��� ù���ۿ� ������ ī�常 �����Ѵ�.
					Sleep(500);
				}
				else {
					back_card(dealer_x + 9, dealer_y);
					Sleep(500);
				}
			}
			else {
				show_card(player_x[i - 1] + (j * 9), player_y, playing[i][j]); // �������� ī��� �����Ѵ�.
				Sleep(500);
			}
		}
	}
	// ī�尪�� ������ش�.
	for (i = 1; i <= playerNum; i++) {
		blackjack_calc(playing, i, cnt[i], sum, die, &stopcard, player_stopcard);
		gotoxy(player_x[i - 1], player_y + 9);
		printf("player %d ī�尪 : %d", i, sum[i]);
		Sleep(500);
	}
	// �� ���̺� �ִ� ī�忡 ī�带 �� ���� ������ ���´�.
	stopcard = 3 - playerNum;		// �÷��̾ ��������� ���� 3-n �� �Ͽ� stopcard ���� �����ش�.
	for (j = 2; stopcard != 3; j++) {
		for (i = 1; i <= playerNum; i++) {
			if (player_stopcard[i - 1] != 1) {
				blackjack_reshow(playerNum, cnt, playing, sum, bet, die, 0);
				gotoxy(disp_x, disp_y);
				printf("player %d ī�带 �ްڽ��ϱ�?(Y/N) : ", i);
				scanf(" %c", &YN);
				if (YN == 'y' || YN == 'Y') {
					insert_deck(i, j, cnt, playing, blackjack_card);			// ī�带 ��Ʈ�ϰ� �Ǹ� �ٷ� �������鼭 ����� �ȴ�.
					show_card(105,3, playing[i][j]);							// A�ϰ�� ����� ������ ��ܿ� ī�带 ���� ������ 
					blackjack_calc(playing, i, cnt[i], sum, die, &stopcard, player_stopcard);
				}
				else if (YN == 'n' || YN == 'N') {
					stopcard++;
					player_stopcard[i - 1] = 1;
				}
				else {
					gotoxy(disp_x, disp_y - 1);
					printf("���ڸ� Ȯ�����ּ���... ");
					_getch();
					i--;
				}
			}
		}
	}
	blackjack_reshow(playerNum, cnt, playing, sum, bet, die, 1);			// ��� ������ ������ �ٽ� ȭ�鿡 �������� ����� �����Ѵ�.
	blackjack_calc(playing, 0, cnt[0], sum, die, &stopcard, player_stopcard);
	_getch();
	j = 1;
	while (die[0] != 1) {		// ������ ��� ���� 16���ϸ� ��ο� - 16�ʰ��̸� ī�带 ��ž�Ѵ�.
		j++;
		gotoxy(disp_x, disp_y);
		printf("������ �� : %d", sum[0]);
		_getch();
		if (sum[0] <= 16) {
			gotoxy(disp_x, disp_y + 1);
			printf("ī�带 ��ο��մϴ�.");
			_getch();
			insert_deck(0, j, cnt, playing, blackjack_card);
			blackjack_calc(playing, 0, cnt[0], sum, die, &stopcard, player_stopcard);
		}
		else {
			die[0] = 1; //�ӽ� ���� DB������ ���ְ� �޴� �κ�
			break;
		}
		_getch();
		blackjack_reshow(playerNum, cnt, playing, sum, bet, die, 1);
	}

	betsum = blackjack_finish(sum, die, bet);		// ������ ������ ��ü ���ð�� �ݾ� ���� �� betsum ������ ����� ����.
	system("cls");

	printf(" '--------------------------------------'\n");
	for (i = 1; i <= playerNum; i++) {
		if (bet[i - 1] < 0) {
			printf(" |  lose   %d �÷��� �������� :  %5d'  |\n", i, bet[i - 1]);
		}else{
			printf(" |   win   %d �÷��� �������� :  %5d'  |\n", i, bet[i - 1]);
		}
	}
	printf(" |--------------------------------------|\n");
	printf(" |        �� �������� �ݾ� :  %5d'    |\n",betsum);
	printf(" '--------------------------------------'\n");

	sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);	// MYSQL ��ȸ ��ɹ� ���� id,pass�� �α��ν� �Է��Ѱ� �޾ƿ�.
	query_stat = mysql_query(connection, query);	// MYSQL ��ɹ� ����, connection���� ���� ���¿� ���� ������  query�� ����.
	sql_result = mysql_store_result(connection);	// �����Ͱ˻��� ������ ������ ȣ�� ������ ��� �ΰ�

	while ((row = mysql_fetch_row(sql_result))) {	// ��ɹ��� ���� ��� �� ��ȯ.
		printf("ID : %s \t COIN : %d\n", row[0], atoi(row[2]));
		// atoi�� ���Ͽ� ascii to interger ���ڿ� ���¸� ���ڷ� �ٲ� �־�� %d�� ��µ� �����ϰ� int�� ��밡��!!
		betsum += atoi(row[2]);
		break;
	}

	printf("����ݾ� : %d\n", betsum);
	sprintf(query, "UPDATE member SET coin = %d where id = '%s' AND pass = '%s'", betsum, id, pass);	// DB���� ��ɹ� ����.
	query_stat = mysql_query(connection, query);	// DB���� ��ɹ� ����.
	printf("���ñݾ� DB���� �Ϸ�\n");

	// mysql_store_result() �Լ� �Ŀ� mysql_fetch_row()�Լ��� ���̻� �˻��� �ο찡 ������ NULL ���� ��, �˻��� �ȵǸ� NULL�� ���
	if (sql_result->row_count == 0) {		// �˻��Ǿ��� �Ҵ� �� ���� ������� row sql_result���� row_count�� 0 ���ΰ� Ȯ�� 
		printf("������ ���� ����");
	}
	_getch();
}