#include <stdio.h>
#include <time.h>
#include <Windows.h>

void taisai_show(int* dice, int(*rec_dice)[4],int cnt)
{
	// 주사위의 모양을 함수로 만들고 for과 rand를 사용하여 30번동안 1/100초 3개의 주사위 출력 마지막 출력때 나온 주사위 저장.
	int i, j, go;
	int x[3] = { 10,45,80 }, y = 5;  // 주사위 출력을 위한 좌표값
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
		if (i == 29) {		//마지막 출력때 나온 주사위 저장.
			gotoxy(111, 2);
			printf("주사위가 멈추었습니다.");
			gotoxy(111, 3);
			printf("%3d %3d %3d 합계 : %3d", dice[0], dice[1], dice[2], dice[0] + dice[1] + dice[2]);

			if (cnt > 9) {								// cnt가 9를 넘어가면 한칸식 앞으로 땡기고 뒤에 새로 입력해줌.
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