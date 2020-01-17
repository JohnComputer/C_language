#include <stdio.h>
// --------------- 중간에 화면 리셋시 계속 출력 해주는 함수 ------------------------------------------------------------
void blackjack_reshow(int playerNum, int* cnt, int(*playing)[8], int* sum, int* bet, int* die, int dealer_open) {
	// reshow 계속 화면에 출력 되는 부분으로 /테이블곗수/카드곗수/카드값/카드합/배팅금액/게임생존여부/딜러의 오픈유무/ 를 매개변수로 받는다.
	int disp_x = 48, disp_y = 5;	// 메뉴의 디스플레이 좌표
	int player_x[3] = { 7, 47, 87 }, player_y = 15, player_y2 = 26;	// 플레이어의 디스플레이 좌표
	int dealer_x = 40, dealer_y = 7;	//딜러의 디스플레이 좌표
	int i, j;	//for구문 사용

	blackjack_disp_board();
	for (i = 0; i <= playerNum; i++) {
		for (j = 0; j < cnt[i]; j++) {
			if (i == 0 && dealer_open == 0) {
				if (j == 0) {
					show_card(dealer_x, dealer_y, playing[i][j]);
				}
				else {
					back_card(dealer_x + 9, dealer_y);				// 딜러의 경우 첫게임 뒷면 출력
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
			printf("player %d 카드값 : %d", i, sum[i]);
			gotoxy(player_x[i - 1], player_y + 8);
			printf("player %d 배팅금액 : %d", i, bet[i - 1]);
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