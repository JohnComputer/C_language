#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//-----------------------------------배팅 금액 설정-----------------------------------
void blackjack_betting(int* playerNum, int *bet, int player_x[3], int player_y) 
{
	int i;
	int disp_x = 48, disp_y = 5;
	// playerNum = 플레이어의 수 / bet = 배팅 금액 / player_x,y = 플레이어 좌표 위치  
	for (i = 0; i < *playerNum; i++) {
		gotoxy(disp_x, disp_y);
		printf("player %d 얼마 배팅하시겠습니까? (1 ~ 1000) : ", i + 1);
		scanf("%d", &bet[i]);
		if (bet[i] < 1 || bet[i] > 1000)
			i--;
		blackjack_disp_board();
	}
	for (i = 0; i < *playerNum; i++) {
		gotoxy(player_x[i], player_y + 8);
		printf("player %d 배팅금액 : %d", i + 1, bet[i]);
	}
}