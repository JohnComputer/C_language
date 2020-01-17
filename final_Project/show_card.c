#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void show_card(int x, int y, int cardnum) 
{
	char clover[3] = { "��" };		// char 1���� ǥ���� �Ұ��� �Ͽ� �迭�� ǥ��
	char heart[3] = { "��" };
	char diamond[3] = { "��" };
	char spade[3] = { "��" };
	char temp[3];					// �Ʒ����� �Բ� ����ϱ� ���� ��� ����� ��´�.(�׸�)
	char cardform;					// ������ ���� ī���� ��� ����

	switch (cardnum / 13) {
	case 0:
		strcpy(temp, clover);		// 0~52���� �� 0~12Ŭ�ι�/13~25��Ʈ/26~38���̾�/39~51�����̵�
		break;
	case 1:
		strcpy(temp, heart);
		break;
	case 2:
		strcpy(temp, diamond);
		break;
	case 3:
		strcpy(temp, spade);
		break;
	}
	switch (cardnum % 13) {			// ī�带 ������ ������ 0~12�� �������� ������� �̱����� ��ȯ
	case 0:
		cardform = 'A';
		break;
	case 1:
		cardform = '2';
		break;
	case 2:
		cardform = '3';
		break;
	case 3:
		cardform = '4';
		break;
	case 4:
		cardform = '5';
		break;
	case 5:
		cardform = '6';
		break;
	case 6:
		cardform = '7';
		break;
	case 7:
		cardform = '8';
		break;
	case 8:
		cardform = '9';
		break;
	case 9:
		//10�� char�� ǥ���� �ȵ� �׷��� Ten�� ���� 
		cardform = 'T';
		break;
	case 10:
		cardform = 'J';
		break;
	case 11:
		cardform = 'Q';
		break;
	case 12:
		cardform = 'K';
		break;
	}
	gotoxy(x, y);
	printf(".-------.");
	gotoxy(x, y + 1);
	printf("|%s-----|", temp);
	gotoxy(x, y + 2);
	printf("|-------|");
	gotoxy(x, y + 3);
	printf("|---%c---|", cardform);
	gotoxy(x, y + 4);
	printf("|-------|");
	gotoxy(x, y + 5);
	printf("|-----%s|", temp);
	gotoxy(x, y + 6);
	printf("'-------'");
}