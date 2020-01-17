#include "taisai.h"

void taisai_reshow(int(*rec_dice)[4], DICE re_d, int board_on) 
{
	// reshow의 기능 -> 게임의 진행상황 출력 배팅한값을 오른쪽 상단에 좌표를 주어 얼마를 어느곳에 배팅하였는지 배팅한 점수만 출력 !
	// board_on으로 보드를 출력할지 안할지 배정

	int betx = 111, bety = 5;	// 베팅금액 출력 X,Y 좌표
	int x = 108, y = 24;			// gotoxy 주사위 값 출력 좌표
	int i;
	int len = 0;				// 각 배열마다 사이즈가 달라서 사이즈를 구하기 위한 임시 길이저장 변수

	if (board_on == 1) {		// 1과 0을 입력 받아 보드판이 출력 여부 결정
		taisai_board();
		for (i = 0; rec_dice[i][0] != 0; i++) {
			gotoxy(x, y);
			printf("%2d %2d %2d 합:%2d", rec_dice[i][0], rec_dice[i][1], rec_dice[i][2], rec_dice[i][3]);
			y++;
		}
	}
	// 구조체 안의 각 배열들의 길이가 다르기 때문에 직접 구해줌.
	// 각 게임마다 배팅이 되어있다면 출력을 하며 bety++을 주어 출력되는 좌표의 y값을 증가 함으로써 순서대로 보여지게 함.
	len = sizeof(re_d.Abigsmall) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Abigsmall[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)게임 : %d", 'A', i + 1, re_d.Abigsmall[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Bevenodd) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Bevenodd[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)게임 : %d", 'B', i + 1, re_d.Bevenodd[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Cpairdice) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Cpairdice[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)게임 : %d", 'C', i + 1, re_d.Cpairdice[i]);
			bety++;
		}
	}
	if (re_d.Danytriple != 0) {
		gotoxy(betx, bety);
		printf("%c게임 : %d", 'D', re_d.Danytriple);
		bety++;
	}
	len = sizeof(re_d.Eseltriple) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Eseltriple[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)게임 : %d", 'E', i + 1, re_d.Eseltriple[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Ftotal) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Ftotal[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)게임 : %d", 'F', i + 1, re_d.Ftotal[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Gdomino) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Gdomino[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)게임 : %d", 'G', i + 1, re_d.Gdomino[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Hsingle) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Hsingle[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)게임 : %d", 'H', i + 1, re_d.Hsingle[i]);
			bety++;
		}
	}
}