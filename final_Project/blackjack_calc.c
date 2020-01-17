#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//------------------------ 카드의 값을 계산하는 함수 -------------------------------------------------------
void blackjack_calc(int(*playing)[8], int play_num, int cnt, int* sum, int* die, int* stop, int* player_stopcard)
{
	// 계산하여 플레이어의 게임 종료여부와 상태를 주기위한 값을 만들어준다 (보여지는건 reshow함수에서)
	// 각 카드의값/플레이어수/총카드곗수/카드핪/게임생존과상태/각각의카드곗수/각플레이어 카드히팅여부 를 매개변수로 받는다.
	// clover heart diamond spade 순서 0~12 는 클로버 13~25 하트 26~38 다이아 39~51 스페이드

	int calc_temp = 0, dealer_temp= 0;	// clac_temp = 계산값 임시 저장 / dealer_temp = 딜러의 값이 A일 경우 자동 계산 해야함.(알고리즘)
	int A_Val = 0;	// A의 경우 1과 11로 사용가능하여 선택문을 둠.
	int i, j;
	int disp_x = 48, disp_y = 5;

	sum[play_num] = 0;

	if (play_num == 0) {			// 딜러의 경우
		for (i = 0; i < cnt; i++) {
			calc_temp = playing[play_num][i] % 13;
			switch (calc_temp) {
			case 0:
				if (cnt == 2) {
					for (j = 0; j < cnt; j++) {
						dealer_temp = playing[play_num][j] % 13;
						if (dealer_temp == 12 || dealer_temp == 11 || dealer_temp == 10 || dealer_temp == 9 || dealer_temp == 8 || dealer_temp == 7 || dealer_temp == 6) {
							calc_temp = 11;	// 처음받은 카드 2장 중 12~6의 카드가 있으면 11로 계산하여 17~21의 숫자를 가져 확률을 높인다.
							break;
						}
					}
					break;	// 아래 1 작동하지않고 나가기
				}
				calc_temp = 1;
				break;
			case 1:
				calc_temp = 2;
				break;
			case 2:
				calc_temp = 3;
				break;
			case 3:
				calc_temp = 4;
				break;
			case 4:
				calc_temp = 5;
				break;
			case 5:
				calc_temp = 6;
				break;
			case 6:
				calc_temp = 7;
				break;
			case 7:
				calc_temp = 8;
				break;
			case 8:
				calc_temp = 9;
				break;
			case 9:
				calc_temp = 10;
				break;
			case 10:
				calc_temp = 10;
				break;
			case 11:
				calc_temp = 10;
				break;
			case 12:
				calc_temp = 10;
				break;
			}
			sum[play_num] += calc_temp;
		}
	}
	else {			// 플레이어의 경우
		for (i = 0; i < cnt; i++) {
			calc_temp = playing[play_num][i] % 13;
			switch (calc_temp) {
			case 0:
				while (1) {
					gotoxy(disp_x, disp_y + 1);
					printf("( 1or11만 입력가능 )");
					gotoxy(disp_x - 5, disp_y);
					printf("player %d는 A를 1로 하시겠습니까? 11로 하시겠습니까? : ", play_num);
					// 플레이어의 경우 계산할때 본인이 선택 가능하도록 함 ! if else 문으로 딜러는 알고리즘 플레이어는 선택 하도록 함.
					scanf("%d", &A_Val);
					if (A_Val == 1 || A_Val == 11) {
						calc_temp = A_Val;
						break;
					}
				}
				break;
			case 1:
				calc_temp = 2;
				break;
			case 2:
				calc_temp = 3;
				break;
			case 3:
				calc_temp = 4;
				break;
			case 4:
				calc_temp = 5;
				break;
			case 5:
				calc_temp = 6;
				break;
			case 6:
				calc_temp = 7;
				break;
			case 7:
				calc_temp = 8;
				break;
			case 8:
				calc_temp = 9;
				break;
			case 9:
				calc_temp = 10;
				break;
			case 10:
				calc_temp = 10;
				break;
			case 11:
				calc_temp = 10;
				break;
			case 12:
				calc_temp = 10;
				break;
			}
			sum[play_num] += calc_temp;
		}
	}
	if (play_num != 0) {			//플레이어가 게임 오버상태인지 체크
		if (sum[play_num] > 21) {
			die[play_num] = 1;		//게임 상태 저장 0 = 진행중,1 = 게임오버, 2 = 블랙잭
			(*stop)++;
			player_stopcard[play_num - 1] = 1;
		}
		if (sum[play_num] == 21) {
			die[play_num] = 2;
			(*stop)++;
			player_stopcard[play_num - 1] = 1;
		}
	}
}
