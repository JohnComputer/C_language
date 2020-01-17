#include "taisai.h"

void taisai_reshow(int(*rec_dice)[4], DICE re_d, int board_on) 
{
	// reshow�� ��� -> ������ �����Ȳ ��� �����Ѱ��� ������ ��ܿ� ��ǥ�� �־� �󸶸� ������� �����Ͽ����� ������ ������ ��� !
	// board_on���� ���带 ������� ������ ����

	int betx = 111, bety = 5;	// ���ñݾ� ��� X,Y ��ǥ
	int x = 108, y = 24;			// gotoxy �ֻ��� �� ��� ��ǥ
	int i;
	int len = 0;				// �� �迭���� ����� �޶� ����� ���ϱ� ���� �ӽ� �������� ����

	if (board_on == 1) {		// 1�� 0�� �Է� �޾� �������� ��� ���� ����
		taisai_board();
		for (i = 0; rec_dice[i][0] != 0; i++) {
			gotoxy(x, y);
			printf("%2d %2d %2d ��:%2d", rec_dice[i][0], rec_dice[i][1], rec_dice[i][2], rec_dice[i][3]);
			y++;
		}
	}
	// ����ü ���� �� �迭���� ���̰� �ٸ��� ������ ���� ������.
	// �� ���Ӹ��� ������ �Ǿ��ִٸ� ����� �ϸ� bety++�� �־� ��µǴ� ��ǥ�� y���� ���� �����ν� ������� �������� ��.
	len = sizeof(re_d.Abigsmall) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Abigsmall[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)���� : %d", 'A', i + 1, re_d.Abigsmall[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Bevenodd) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Bevenodd[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)���� : %d", 'B', i + 1, re_d.Bevenodd[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Cpairdice) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Cpairdice[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)���� : %d", 'C', i + 1, re_d.Cpairdice[i]);
			bety++;
		}
	}
	if (re_d.Danytriple != 0) {
		gotoxy(betx, bety);
		printf("%c���� : %d", 'D', re_d.Danytriple);
		bety++;
	}
	len = sizeof(re_d.Eseltriple) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Eseltriple[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)���� : %d", 'E', i + 1, re_d.Eseltriple[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Ftotal) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Ftotal[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)���� : %d", 'F', i + 1, re_d.Ftotal[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Gdomino) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Gdomino[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)���� : %d", 'G', i + 1, re_d.Gdomino[i]);
			bety++;
		}
	}
	len = sizeof(re_d.Hsingle) / sizeof(int);
	for (i = 0; i < len; i++) {
		if (re_d.Hsingle[i] != 0) {
			gotoxy(betx, bety);
			printf("%c(%d)���� : %d", 'H', i + 1, re_d.Hsingle[i]);
			bety++;
		}
	}
}