#include <stdio.h>
//-------------- 딜러의 첫판에 뒤집어진 카드를 뽑기위해 뒷면 출력 ------------------------
void back_card(int x, int y)
{
	//play함수에서
	//한칸에 가로 9!!
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