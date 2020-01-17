#include <stdio.h>
// --------------- �߰��� ȭ�� ���½� ��� ��� ���ִ� �Լ� ------------------------------------------------------------
void blackjack_reshow(int playerNum, int* cnt, int(*playing)[8], int* sum, int* bet, int* die, int dealer_open) {
	// reshow ��� ȭ�鿡 ��� �Ǵ� �κ����� /���̺���/ī����/ī�尪/ī����/���ñݾ�/���ӻ�������/������ ��������/ �� �Ű������� �޴´�.
	int disp_x = 48, disp_y = 5;	// �޴��� ���÷��� ��ǥ
	int player_x[3] = { 7, 47, 87 }, player_y = 15, player_y2 = 26;	// �÷��̾��� ���÷��� ��ǥ
	int dealer_x = 40, dealer_y = 7;	//������ ���÷��� ��ǥ
	int i, j;	//for���� ���

	blackjack_disp_board();
	for (i = 0; i <= playerNum; i++) {
		for (j = 0; j < cnt[i]; j++) {
			if (i == 0 && dealer_open == 0) {
				if (j == 0) {
					show_card(dealer_x, dealer_y, playing[i][j]);
				}
				else {
					back_card(dealer_x + 9, dealer_y);				// ������ ��� ù���� �޸� ���
				}
			}
			else if (i == 0 && dealer_open == 1) {
				show_card(dealer_x + (j * 9), dealer_y, playing[i][j]);
			}
			else {
				if (j > 3)
					show_card(player_x[i - 1] + ((j - 4) * 9), player_y2, playing[i][j]);
				else
					show_card(player_x[i - 1] + (j * 9), player_y, playing[i][j]);
			}
		}
		if (i != 0) {
			gotoxy(player_x[i - 1], player_y + 9);
			printf("player %d ī�尪 : %d", i, sum[i]);
			gotoxy(player_x[i - 1], player_y + 8);
			printf("player %d ���ñݾ� : %d", i, bet[i - 1]);
			if (die[i] == 1) {
				gotoxy(player_x[i - 1], player_y - 1);
				printf("Player LOSE");
			}
			if (die[i] == 2) {
				gotoxy(player_x[i - 1], player_y - 1);
				printf("BLACK JACK");
			}
			if (die[i] == 3) {
				gotoxy(player_x[i - 1], player_y - 1);
				printf("PLAYER WIN");
			}
		}
	}
}