#include <stdio.h>
#include <time.h>
#include <Windows.h>

void taisai_show(int* dice, int(*rec_dice)[4],int cnt)
{
	// �ֻ����� ����� �Լ��� ����� for�� rand�� ����Ͽ� 30������ 1/100�� 3���� �ֻ��� ��� ������ ��¶� ���� �ֻ��� ����.
	int i, j, go;
	int x[3] = { 10,45,80 }, y = 5;  // �ֻ��� ����� ���� ��ǥ��
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 3; j++) {
			go = rand() % 6;
			switch (go) {
			case 0:
				one_dice(x[j], y);
				break;
			case 1:
				two_dice(x[j], y);
				break;
			case 2:
				three_dice(x[j], y);
				break;
			case 3:
				four_dice(x[j], y);
				break;
			case 4:
				five_dice(x[j], y);
				break;
			case 5:
				six_dice(x[j], y);
				break;
			}
			if (i == 29) {
				dice[j] = go + 1;
			}
		}
		Sleep(100);
		if (i == 29) {		//������ ��¶� ���� �ֻ��� ����.
			gotoxy(111, 2);
			printf("�ֻ����� ���߾����ϴ�.");
			gotoxy(111, 3);
			printf("%3d %3d %3d �հ� : %3d", dice[0], dice[1], dice[2], dice[0] + dice[1] + dice[2]);

			if (cnt > 9) {								// cnt�� 9�� �Ѿ�� ��ĭ�� ������ ����� �ڿ� ���� �Է�����.
				for (j = 0; j < 9; j++) {
					rec_dice[j][0] = rec_dice[j + 1][0];
					rec_dice[j][1] = rec_dice[j + 1][1];
					rec_dice[j][2] = rec_dice[j + 1][2];
					rec_dice[j][3] = rec_dice[j + 1][3];
				}
				for (j = 0; j < 3; j++) {
					rec_dice[9][j] = dice[j];
				}
			}
			else {
				for (j = 0; j < 3; j++) {
					rec_dice[cnt][j] = dice[j];
				}
				rec_dice[cnt % 10][3] = dice[0] + dice[1] + dice[2];
			}
			_getch();
		}
	}
}