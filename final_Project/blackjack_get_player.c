#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//--------------------- �÷��̾� �� �޴� �Լ� -----------------------------------------
void blackjack_get_player(int* playerNum, int player_x[3], int player_y) 
{
	int disp_x = 48, disp_y = 5;
	while (1) {
		blackjack_disp_board();
		gotoxy(disp_x, disp_y);
		printf("������ �����մϴ�.");
		gotoxy(disp_x, disp_y + 1);
		printf("��� �÷��� �Ͻðڽ��ϱ�??");
		gotoxy(player_x[0] + 3, player_y - 1);
		printf("player1");
		back_card(player_x[0], player_y);
		gotoxy(player_x[1] + 3, player_y - 1);
		printf("player2");
		back_card(player_x[1], player_y);
		gotoxy(player_x[2] + 3, player_y - 1);
		printf("player3");
		back_card(player_x[2], player_y);
		//����� �÷��� ���� �ޱ�.!!
		gotoxy(disp_x, disp_y + 2);
		scanf("%d", playerNum);
		if (*playerNum <= 3)
			break;
		else
			continue;
	}
}