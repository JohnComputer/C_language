#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//-----------------------------------���� �ݾ� ����-----------------------------------
void blackjack_betting(int* playerNum, int *bet, int player_x[3], int player_y) 
{
	int i;
	int disp_x = 48, disp_y = 5;
	// playerNum = �÷��̾��� �� / bet = ���� �ݾ� / player_x,y = �÷��̾� ��ǥ ��ġ  
	for (i = 0; i < *playerNum; i++) {
		gotoxy(disp_x, disp_y);
		printf("player %d �� �����Ͻðڽ��ϱ�? (1 ~ 1000) : ", i + 1);
		scanf("%d", &bet[i]);
		if (bet[i] < 1 || bet[i] > 1000)
			i--;
		blackjack_disp_board();
	}
	for (i = 0; i < *playerNum; i++) {
		gotoxy(player_x[i], player_y + 8);
		printf("player %d ���ñݾ� : %d", i + 1, bet[i]);
	}
}