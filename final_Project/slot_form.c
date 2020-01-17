#include <stdio.h>

void Aform(int x, int y) {
	gotoxy(x, y);
	printf(" ___ ");
	gotoxy(x, y + 1);
	printf("| . |");
	gotoxy(x, y + 2);
	printf("|   |");
	gotoxy(x, y + 3);
	printf("|_|_|");
}
void Kform(int x, int y) {
	gotoxy(x, y);
	printf(" _ __");
	gotoxy(x, y + 1);
	printf("| / /'");
	gotoxy(x, y + 2);
	printf("|  '");
	gotoxy(x, y + 3);
	printf("|_'_'");
}
void Sform(int x, int y) {
	gotoxy(x, y);
	printf(" ___ ");
	gotoxy(x, y + 1);
	printf("/ __>");
	gotoxy(x, y + 2);
	printf("'__ '");
	gotoxy(x, y + 3);
	printf("<___/");
}
void SEVENform(int x, int y) {
	gotoxy(x, y);
	printf(" ___ ");
	gotoxy(x, y + 1);
	printf("|_  |");
	gotoxy(x, y + 2);
	printf(" / /");
	gotoxy(x, y + 3);
	printf("/_/ ");
}