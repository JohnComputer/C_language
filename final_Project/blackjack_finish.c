#include <stdio.h>
//-------------------------- ���ñݾ� ����κ� --------------------------------------------
int blackjack_finish(int* sum,int* die,int* bet) {
	int i = 0;

	for (i = 1; i <= 3; i++) { //���� ���� ���� 0 = ������,1 = ���ӿ���, 2 = ����
		switch (die[i]) {
		case 0:
			if (sum[0] > sum[i]) {			// ������ sum[0] ���ں� !
				bet[i - 1] = bet[i - 1] * -1;
			}
			else if (sum[0] < sum[i]) {
				bet[i - 1] *= 2;
			}
			// �̺κ� �ۼ� �ʿ� ���� ���ϰ� ����ϸ�� !!
			break;
		case 1:
			bet[i - 1] = bet[i - 1] * -1;	// �������ÿ� ���� -1�ݾ�
			break;
		case 2:
			bet[i - 1] *= 2;	// �����̹Ƿ� ������ �¸� 2��
			break;
		}
	}
	return (bet[0] + bet[1] + bet[2]);
	// �÷��̾��� ���� �ݾ� ���� ���� �� ����
}