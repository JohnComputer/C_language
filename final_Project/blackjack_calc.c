#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//------------------------ ī���� ���� ����ϴ� �Լ� -------------------------------------------------------
void blackjack_calc(int(*playing)[8], int play_num, int cnt, int* sum, int* die, int* stop, int* player_stopcard)
{
	// ����Ͽ� �÷��̾��� ���� ���Ῡ�ο� ���¸� �ֱ����� ���� ������ش� (�������°� reshow�Լ�����)
	// �� ī���ǰ�/�÷��̾��/��ī����/ī���D/���ӻ���������/������ī����/���÷��̾� ī�����ÿ��� �� �Ű������� �޴´�.
	// clover heart diamond spade ���� 0~12 �� Ŭ�ι� 13~25 ��Ʈ 26~38 ���̾� 39~51 �����̵�

	int calc_temp = 0, dealer_temp= 0;	// clac_temp = ��갪 �ӽ� ���� / dealer_temp = ������ ���� A�� ��� �ڵ� ��� �ؾ���.(�˰���)
	int A_Val = 0;	// A�� ��� 1�� 11�� ��밡���Ͽ� ���ù��� ��.
	int i, j;
	int disp_x = 48, disp_y = 5;

	sum[play_num] = 0;

	if (play_num == 0) {			// ������ ���
		for (i = 0; i < cnt; i++) {
			calc_temp = playing[play_num][i] % 13;
			switch (calc_temp) {
			case 0:
				if (cnt == 2) {
					for (j = 0; j < cnt; j++) {
						dealer_temp = playing[play_num][j] % 13;
						if (dealer_temp == 12 || dealer_temp == 11 || dealer_temp == 10 || dealer_temp == 9 || dealer_temp == 8 || dealer_temp == 7 || dealer_temp == 6) {
							calc_temp = 11;	// ó������ ī�� 2�� �� 12~6�� ī�尡 ������ 11�� ����Ͽ� 17~21�� ���ڸ� ���� Ȯ���� ���δ�.
							break;
						}
					}
					break;	// �Ʒ� 1 �۵������ʰ� ������
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
	else {			// �÷��̾��� ���
		for (i = 0; i < cnt; i++) {
			calc_temp = playing[play_num][i] % 13;
			switch (calc_temp) {
			case 0:
				while (1) {
					gotoxy(disp_x, disp_y + 1);
					printf("( 1or11�� �Է°��� )");
					gotoxy(disp_x - 5, disp_y);
					printf("player %d�� A�� 1�� �Ͻðڽ��ϱ�? 11�� �Ͻðڽ��ϱ�? : ", play_num);
					// �÷��̾��� ��� ����Ҷ� ������ ���� �����ϵ��� �� ! if else ������ ������ �˰��� �÷��̾�� ���� �ϵ��� ��.
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
	if (play_num != 0) {			//�÷��̾ ���� ������������ üũ
		if (sum[play_num] > 21) {
			die[play_num] = 1;		//���� ���� ���� 0 = ������,1 = ���ӿ���, 2 = ����
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
