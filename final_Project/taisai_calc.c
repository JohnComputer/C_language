#include "taisai.h"

int taisai_calc(int* dice, int* onoff, DICE game_d) {
	// ���⿡ ���ñ��� �޾Ƽ� ������ �����ְ� �ƴϸ� ������.
	// �Լ��� �⺻������ ������ ���ӿ� ���ؼ� Ȯ�� �� �´� ����� ���Ѵ�. �������� ���ϴ°��� �ƴ� ���õ� ���ӿ� �����Ͽ� ���Ѵ�.
	int sum = 0, moneytemp = 0, moneysum = 0, tempbet = 0, i; // moneysum�� ���߿� �� ���ñݾ� moneytemp�� ���ð�� �ٷ� ���
	int paircnt[6] = { 0 }; // C������ ī���� ���� ����
	int x = 111, y = 16;
	sum = dice[0] + dice[1] + dice[2];	// �ֻ��� ��
	// A���� �ֻ����� ���� ũ�� ������ Ȯ���Ѵ�. 11~17 BIG / 4~10 SMALL �� ������ ���ñݾ��� 2�� ����
	if (onoff[0] != 0) {
		if (game_d.Abigsmall[0] != 0) {
			if (sum >= 11 && sum <= 17)
				game_d.Abigsmall[0] *= 2;
			else
				game_d.Abigsmall[0] *= -1;
		}
		if (game_d.Abigsmall[1] != 0) {
			if (sum >= 4 && sum <= 10)
				game_d.Abigsmall[1] *= 2;
			else
				game_d.Abigsmall[1] *= -1;
		}
		moneytemp = game_d.Abigsmall[0] + game_d.Abigsmall[1];
		moneysum += moneytemp;
		gotoxy(x, y);
		printf("A���� ����ȯ�ޱ� : %d", moneytemp);
		y++;
	}
	// B���� �ֻ����� ���� ¦������ Ȧ������ Ȯ���Ѵ�. EVEN / ODD
	if (onoff[1] != 0) {
		if (game_d.Bevenodd[0] != 0) {
			if (sum % 2 == 0)
				game_d.Bevenodd[0] *= 2;
			else
				game_d.Bevenodd[0] *= -1;
		}
		if (game_d.Bevenodd[1] != 0) {
			if (sum % 2 == 1)
				game_d.Bevenodd[1] *= 2;
			else
				game_d.Bevenodd[1] *= -1;
		}
		moneytemp = game_d.Bevenodd[0] + game_d.Bevenodd[1];
		moneysum += moneytemp;
		gotoxy(x, y);
		printf("B���� ����ȯ�ޱ� : %d", moneytemp);
		y++;
	}
	// C���� �ѽ��� ���� �ֻ����� ������ ������ �����Ѵ�. ������ 8���̴�. 0~5 ���� 1~6�� ���� ���� �ѽ��� ã�´�.
	if (onoff[2] != 0) {
		if (game_d.Cpairdice[0] != 0) {
			for (i = 0; i < 3; i++) {
				if (dice[i] == 1) {
					paircnt[0]++;
				}
			}
			if (paircnt[0] >= 2)
				game_d.Cpairdice[0] *= 8;
			else
				game_d.Cpairdice[0] *= -1;
		}
		if (game_d.Cpairdice[1] != 0) {
			for (i = 0; i < 3; i++) {
				if (dice[i] == 2) {
					paircnt[1]++;
				}
			}
			if (paircnt[1] >= 2)
				game_d.Cpairdice[1] *= 8;
			else
				game_d.Cpairdice[1] *= -1;
		}
		if (game_d.Cpairdice[2] != 0) {
			for (i = 0; i < 3; i++) {
				if (dice[i] == 3) {
					paircnt[2]++;
				}
			}
			if (paircnt[2] >= 2)
				game_d.Cpairdice[2] *= 8;
			else
				game_d.Cpairdice[2] *= -1;
		}
		if (game_d.Cpairdice[3] != 0) {
			for (i = 0; i < 3; i++) {
				if (dice[i] == 4) {
					paircnt[3]++;
				}
			}
			if (paircnt[3] >= 2)
				game_d.Cpairdice[3] *= 8;
			else
				game_d.Cpairdice[3] *= -1;
		}
		if (game_d.Cpairdice[4] != 0) {
			for (i = 0; i < 3; i++) {
				if (dice[i] == 5) {
					paircnt[4]++;
				}
			}
			if (paircnt[4] >= 2)
				game_d.Cpairdice[4] *= 8;
			else
				game_d.Cpairdice[4] *= -1;
		}
		if (game_d.Cpairdice[5] != 0) {
			for (i = 0; i < 3; i++) {
				if (dice[i] == 6) {
					paircnt[5]++;
				}
			}
			if (paircnt[5] >= 2)
				game_d.Cpairdice[5] *= 8;
			else
				game_d.Cpairdice[5] *= -1;
		}
		moneytemp = 0;
		for (i = 0; i < 6; i++) {
			moneytemp += game_d.Cpairdice[i];
		}
		moneysum += moneytemp;
		gotoxy(x, y);
		printf("C���� ����ȯ�ޱ� : %d", moneytemp);
		y++;
	}
	// D���� ��� ���ڵ� 3���� �ֻ����� ���� ���� ������ ������ �����Ѵ�. ������ 24���̴�.
	if (onoff[3] != 0) {
		if (game_d.Danytriple != 0) {
			if (dice[0] == dice[1] && dice[1] == dice[2])
				game_d.Danytriple *= 24;
			else
				game_d.Danytriple *= -1;
		}
		moneytemp = game_d.Danytriple;
		moneysum += moneytemp;
		gotoxy(x, y);
		printf("D���� ����ȯ�ޱ� : %d", moneytemp);
		y++;
	}
	// E���� ���õ� ������ ���� 3���� �ֻ����� ������� ������ ���޵ȴ�. ������ 24���̴�.
	if (onoff[4] != 0) {
		if (dice[0] == 1 && dice[1] == 1 && dice[2] == 1)
			game_d.Eseltriple[0] *= 150;
		else
			game_d.Eseltriple[0] *= -1;
		if (dice[0] == 2 && dice[1] == 2 && dice[2] == 2)
			game_d.Eseltriple[1] *= 150;
		else
			game_d.Eseltriple[1] *= -1;
		if (dice[0] == 3 && dice[1] == 3 && dice[2] == 3)
			game_d.Eseltriple[2] *= 150;
		else
			game_d.Eseltriple[2] *= -1;
		if (dice[0] == 4 && dice[1] == 4 && dice[2] == 4)
			game_d.Eseltriple[3] *= 150;
		else
			game_d.Eseltriple[3] *= -1;
		if (dice[0] == 5 && dice[1] == 5 && dice[2] == 5)
			game_d.Eseltriple[4] *= 150;
		else
			game_d.Eseltriple[4] *= -1;
		if (dice[0] == 6 && dice[1] == 6 && dice[2] == 6)
			game_d.Eseltriple[5] *= 150;
		else
			game_d.Eseltriple[5] *= -1;
		moneytemp = 0;
		for (i = 0; i < 6; i++) {
			moneytemp += game_d.Eseltriple[i];
		}
		moneysum += moneytemp;
		gotoxy(x, y);
		printf("E���� ����ȯ�ޱ� : %d", moneytemp);
		y++;
	}
	// F���� 3���� �ֻ����� ���� �����. �������� Ȯ���� �ٸ����� ������ ���� �����ϴ�.
	if (onoff[5] != 0) {
		if (game_d.Ftotal[0] != 0 || game_d.Ftotal[13] != 0) {
			if (sum == 4 || sum == 17) {
				game_d.Ftotal[0] *= 50;
				game_d.Ftotal[13] *= 50;
			}
			else {
				game_d.Ftotal[0] *= -1;
				game_d.Ftotal[13] *= -1;
			}
		}
		if (game_d.Ftotal[1] != 0 || game_d.Ftotal[12] != 0) {
			if (sum == 5 || sum == 16) {
				game_d.Ftotal[1] *= 30;
				game_d.Ftotal[12] *= 30;
			}
			else {
				game_d.Ftotal[1] *= -1;
				game_d.Ftotal[12] *= -1;
			}
		}
		if (game_d.Ftotal[2] != 0 || game_d.Ftotal[11] != 0) {
			if (sum == 6 || sum == 15) {
				game_d.Ftotal[2] *= 18;
				game_d.Ftotal[11] *= 18;
			}
			else {
				game_d.Ftotal[2] *= -1;
				game_d.Ftotal[11] *= -1;
			}

		}
		if (game_d.Ftotal[3] != 0 || game_d.Ftotal[10] != 0) {
			if (sum == 7 || sum == 14) {
				game_d.Ftotal[3] *= 12;
				game_d.Ftotal[10] *= 12;
			}
			else {
				game_d.Ftotal[3] *= -1;
				game_d.Ftotal[10] *= -1;
			}
		}
		if (game_d.Ftotal[4] != 0 || game_d.Ftotal[9] != 0) {
			if (sum == 8 || sum == 13) {
				game_d.Ftotal[4] *= 8;
				game_d.Ftotal[9] *= 8;
			}
			else {
				game_d.Ftotal[4] *= -1;
				game_d.Ftotal[9] *= -1;
			}
		}
		if (game_d.Ftotal[5] != 0 || game_d.Ftotal[6] != 0 || game_d.Ftotal[7] != 0 || game_d.Ftotal[8] != 0) {
			if (sum == 9 || sum == 10 || sum == 11 || sum == 12) {
				game_d.Ftotal[5] *= 6;
				game_d.Ftotal[6] *= 6;
				game_d.Ftotal[7] *= 6;
				game_d.Ftotal[8] *= 6;
			}
			else {
				game_d.Ftotal[5] *= -1;
				game_d.Ftotal[6] *= -1;
				game_d.Ftotal[7] *= -1;
				game_d.Ftotal[8] *= -1;
			}
		}
		moneytemp = 0;
		for (i = 0; i < 14; i++) {
			moneytemp += game_d.Ftotal[i];
		}
		moneysum += moneytemp;
		gotoxy(x, y);
		printf("F���� ����ȯ�ޱ� : %d", moneytemp);
		y++;
	}
	// G���� 3���� �ֻ����� 2���� �ֻ����� ���̳�ó�� ���� �´°��� �����ϸ� ���� ����. ������ 5���̴�.
	if (onoff[6] != 0) {
		moneytemp = 0;
		if (game_d.Gdomino[0] != 0)
			if (dice[0] == 5 || dice[1] == 5 || dice[2] == 5)
				if (dice[0] == 6 || dice[1] == 6 || dice[2] == 6)
					moneytemp += (game_d.Gdomino[0] * 5);
				else
					moneytemp += (game_d.Gdomino[0] * -1);
		if (game_d.Gdomino[1] != 0)
			if (dice[0] == 4 || dice[1] == 4 || dice[2] == 4)
				if (dice[0] == 6 || dice[1] == 6 || dice[2] == 6)
					moneytemp += (game_d.Gdomino[1] * 5);
				else
					moneytemp += (game_d.Gdomino[1] * -1);
		if (game_d.Gdomino[2] != 0)
			if (dice[0] == 4 || dice[1] == 4 || dice[2] == 4)
				if (dice[0] == 5 || dice[1] == 5 || dice[2] == 5)
					moneytemp += (game_d.Gdomino[2] * 5);
				else
					moneytemp += (game_d.Gdomino[2] * -1);
		if (game_d.Gdomino[3] != 0)
			if (dice[0] == 3 || dice[1] == 3 || dice[2] == 3)
				if (dice[0] == 6 || dice[1] == 6 || dice[2] == 6)
					moneytemp += (game_d.Gdomino[3] * 5);
				else
					moneytemp += (game_d.Gdomino[3] * -1);
		if (game_d.Gdomino[4] != 0)
			if (dice[0] == 3 || dice[1] == 3 || dice[2] == 3)
				if (dice[0] == 5 || dice[1] == 5 || dice[2] == 5)
					moneytemp += (game_d.Gdomino[4] * 5);
				else
					moneytemp += (game_d.Gdomino[4] * -1);
		if (game_d.Gdomino[5] != 0)
			if (dice[0] == 3 || dice[1] == 3 || dice[2] == 3)
				if (dice[0] == 4 || dice[1] == 4 || dice[2] == 4)
					moneytemp += (game_d.Gdomino[5] * 5);
				else
					moneytemp += (game_d.Gdomino[5] * -1);
		if (game_d.Gdomino[6] != 0)
			if (dice[0] == 2 || dice[1] == 2 || dice[2] == 2)
				if (dice[0] == 6 || dice[1] == 6 || dice[2] == 6)
					moneytemp += (game_d.Gdomino[6] * 5);
				else
					moneytemp += (game_d.Gdomino[6] * -1);
		if (game_d.Gdomino[7] != 0)
			if (dice[0] == 2 || dice[1] == 2 || dice[2] == 2)
				if (dice[0] == 5 || dice[1] == 5 || dice[2] == 5)
					moneytemp += (game_d.Gdomino[7] * 5);
				else
					moneytemp += (game_d.Gdomino[7] * -1);
		if (game_d.Gdomino[8] != 0)
			if (dice[0] == 2 || dice[1] == 2 || dice[2] == 2)
				if (dice[0] == 4 || dice[1] == 4 || dice[2] == 4)
					moneytemp += (game_d.Gdomino[8] * 5);
				else
					moneytemp += (game_d.Gdomino[8] * -1);
		if (game_d.Gdomino[9] != 0)
			if (dice[0] == 2 || dice[1] == 2 || dice[2] == 2)
				if (dice[0] == 3 || dice[1] == 3 || dice[2] == 3)
					moneytemp += (game_d.Gdomino[9] * 5);
				else
					moneytemp += (game_d.Gdomino[9] * -1);
		if (game_d.Gdomino[10] != 0)
			if (dice[0] == 1 || dice[1] == 1 || dice[2] == 1)
				if (dice[0] == 6 || dice[1] == 6 || dice[2] == 6)
					moneytemp += (game_d.Gdomino[10] * 5);
				else
					moneytemp += (game_d.Gdomino[10] * -1);
		if (game_d.Gdomino[11] != 0)
			if (dice[0] == 1 || dice[1] == 1 || dice[2] == 1)
				if (dice[0] == 5 || dice[1] == 5 || dice[2] == 5)
					moneytemp += (game_d.Gdomino[11] * 5);
				else
					moneytemp += (game_d.Gdomino[11] * -1);
		if (game_d.Gdomino[12] != 0)
			if (dice[0] == 1 || dice[1] == 1 || dice[2] == 1)
				if (dice[0] == 4 || dice[1] == 4 || dice[2] == 4)
					moneytemp += (game_d.Gdomino[12] * 5);
				else
					moneytemp += (game_d.Gdomino[12] * -1);
		if (game_d.Gdomino[13] != 0)
			if (dice[0] == 1 || dice[1] == 1 || dice[2] == 1)
				if (dice[0] == 3 || dice[1] == 3 || dice[2] == 3)
					moneytemp += (game_d.Gdomino[13] * 5);
				else
					moneytemp += (game_d.Gdomino[13] * -1);
		if (game_d.Gdomino[14] != 0)
			if (dice[0] == 1 || dice[1] == 1 || dice[2] == 1)
				if (dice[0] == 2 || dice[1] == 2 || dice[2] == 2)
					moneytemp += (game_d.Gdomino[14] * 5);
				else
					moneytemp += (game_d.Gdomino[14] * -1);
		moneysum += moneytemp;
		gotoxy(x, y);
		printf("G���� ����ȯ�ޱ� : %d", moneytemp);
		y++;
	}
	// H���� �Ѱ����� ���ڰ� ��ġ�Ұ�� ������ �����Ѵ�. �ֻ��� �������� �������� 1�� �����Ѵ�.
	if (onoff[7] != 0) {
		moneytemp = 0;
		for (i = 0; i < 5; i++) {
			tempbet = game_d.Hsingle[i];
			if (game_d.Hsingle[i] != 0) {
				if (dice[0] - 1 == i)				// 1,2,3 �� �ֻ����� ���� �˻��ؼ� 3���� 2�� �����쵵 �����Ͽ� ����ȯ�� �ؾ���.
					game_d.Hsingle[i] += tempbet;
				else if(dice[1] - 1 == i)
					game_d.Hsingle[i] += tempbet;
				else if(dice[2] - 1 == i)
					game_d.Hsingle[i] += tempbet;
				else
					game_d.Hsingle[i] *= -1;
				moneytemp += game_d.Hsingle[i];
			}
		}
		moneysum += moneytemp;
		gotoxy(x, y);
		printf("H���� ����ȯ�ޱ� : %d", moneytemp);
		y++;
	}
	gotoxy(x, y);
	printf("�Ѱ��� ����ȯ�ޱ� : %d", moneysum);
	return moneysum;
}