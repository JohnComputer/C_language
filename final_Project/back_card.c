#include <stdio.h>
//-------------- ������ ù�ǿ� �������� ī�带 �̱����� �޸� ��� ------------------------
void back_card(int x, int y)
{
	//play�Լ�����
	//��ĭ�� ���� 9!!
	gotoxy(x, y);
	printf(".-------.");
	gotoxy(x, y + 1);
	printf("|?------|");
	gotoxy(x, y + 2);
	printf("|-------|");
	gotoxy(x, y + 3);
	printf("|---?---|");
	gotoxy(x, y + 4);
	printf("|-------|");
	gotoxy(x, y + 5);
	printf("|------?|");
	gotoxy(x, y + 6);
	printf("'-------'");
}