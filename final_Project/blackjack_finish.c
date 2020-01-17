#include <stdio.h>
//-------------------------- 배팅금액 정산부분 --------------------------------------------
int blackjack_finish(int* sum,int* die,int* bet) {
	int i = 0;

	for (i = 1; i <= 3; i++) { //게임 상태 저장 0 = 진행중,1 = 게임오버, 2 = 블랙잭
		switch (die[i]) {
		case 0:
			if (sum[0] > sum[i]) {			// 딜러는 sum[0] 숫자비교 !
				bet[i - 1] = bet[i - 1] * -1;
			}
			else if (sum[0] < sum[i]) {
				bet[i - 1] *= 2;
			}
			// 이부분 작성 필요 서로 비교하고 계산하면됨 !!
			break;
		case 1:
			bet[i - 1] = bet[i - 1] * -1;	// 게임질시에 배팅 -1금액
			break;
		case 2:
			bet[i - 1] *= 2;	// 블랙잭이므로 무조건 승리 2배
			break;
		}
	}
	return (bet[0] + bet[1] + bet[2]);
	// 플레이어의 배팅 금액 전부 합한 후 리턴
}