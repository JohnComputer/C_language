#include "taisai.h"

int taisai_calc(int* dice, int* onoff, DICE game_d) {
	// 여기에 배팅금을 받아서 맞으면 돌려주고 아니면 버린다.
	// 함수의 기본동작은 배팅한 게임에 한해서 확인 후 맞는 방식을 취한다. 모든게임을 비교하는것이 아닌 배팅된 게임에 한정하여 비교한다.
	int sum = 0, moneytemp = 0, moneysum = 0, tempbet = 0, i; // moneysum은 나중에 총 배팅금액 moneytemp는 배팅결과 바로 출력
	int paircnt[6] = { 0 }; // C게임의 카운팅 위한 변수
	int x = 111, y = 16;
	sum = dice[0] + dice[1] + dice[2];	// 주사위 합
	// A게임 주사위의 합이 크고 작음을 확인한다. 11~17 BIG / 4~10 SMALL 로 배당금은 배팅금액의 2배 정산
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
		printf("A게임 배팅환급금 : %d", moneytemp);
		y++;
	}
	// B게임 주사위의 합이 짝수인지 홀수인지 확인한다. EVEN / ODD
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
		printf("B게임 배팅환급금 : %d", moneytemp);
		y++;
	}
	// C게임 한쌍의 같은 주사위가 나오면 배당금을 지급한다. 배당금은 8배이다. 0~5 까지 1~6의 값을 갖는 한쌍을 찾는다.
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
		printf("C게임 배팅환급금 : %d", moneytemp);
		y++;
	}
	// D게임 어떠한 숫자든 3개의 주사위가 같은 값을 가지면 배당금을 지불한다. 배당금은 24배이다.
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
		printf("D게임 배팅환급금 : %d", moneytemp);
		y++;
	}
	// E게임 선택된 숫자의 값을 3개의 주사위가 가질경우 배당금이 지급된다. 배당금은 24배이다.
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
		printf("E게임 배팅환급금 : %d", moneytemp);
		y++;
	}
	// F게임 3개의 주사위의 합을 맞춘다. 점수마다 확률이 다름으로 배당금을 서로 상이하다.
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
		printf("F게임 배팅환급금 : %d", moneytemp);
		y++;
	}
	// G게임 3개의 주사위중 2개의 주사위가 도미노처럼 값이 맞는것을 선택하면 배당금 지급. 배당금은 5배이다.
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
		printf("G게임 배팅환급금 : %d", moneytemp);
		y++;
	}
	// H게임 한가지의 숫자가 일치할경우 배당금을 지급한다. 주사위 갯수별로 배당배율을 1씩 증가한다.
	if (onoff[7] != 0) {
		moneytemp = 0;
		for (i = 0; i < 5; i++) {
			tempbet = game_d.Hsingle[i];
			if (game_d.Hsingle[i] != 0) {
				if (dice[0] - 1 == i)				// 1,2,3 번 주사위를 따로 검색해서 3개중 2개 맞출경우도 예상하여 배팅환급 해야함.
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
		printf("H게임 배팅환급금 : %d", moneytemp);
		y++;
	}
	gotoxy(x, y);
	printf("총게임 배팅환급금 : %d", moneysum);
	return moneysum;
}