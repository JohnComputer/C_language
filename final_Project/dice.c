#include <stdio.h>
// �ֻ��� ��� ����� c����
void one_dice(int x, int y) {
	gotoxy(x, y);
	printf(".----------------.");
	gotoxy(x, y + 1);
	printf("|                |");
	gotoxy(x, y + 2);
	printf("|                |");
	gotoxy(x, y + 3);
	printf("|         @      |");
	gotoxy(x, y + 4);
	printf("|                |");
	gotoxy(x, y + 5);
	printf("|                |");
	gotoxy(x, y + 6);
	printf("'----------------'");
}
void two_dice(int x, int y) {
	gotoxy(x, y);
	printf(".----------------.");
	gotoxy(x, y + 1);
	printf("|             @  |");
	gotoxy(x, y + 2);
	printf("|                |");
	gotoxy(x, y + 3);
	printf("|                |");
	gotoxy(x, y + 4);
	printf("|                |");
	gotoxy(x, y + 5);
	printf("|  @             |");
	gotoxy(x, y + 6);
	printf("'----------------'");
}
void three_dice(int x, int y) {
	gotoxy(x, y);
	printf(".----------------.");
	gotoxy(x, y + 1);
	printf("|             @  |");
	gotoxy(x, y + 2);
	printf("|                |");
	gotoxy(x, y + 3);
	printf("|       @        |");
	gotoxy(x, y + 4);
	printf("|                |");
	gotoxy(x, y + 5);
	printf("|  @             |");
	gotoxy(x, y + 6);
	printf("'----------------'");
}
void four_dice(int x, int y) {
	gotoxy(x, y);
	printf(".----------------.");
	gotoxy(x, y + 1);
	printf("|  @          @  |");
	gotoxy(x, y + 2);
	printf("|                |");
	gotoxy(x, y + 3);
	printf("|                |");
	gotoxy(x, y + 4);
	printf("|                |");
	gotoxy(x, y + 5);
	printf("|  @          @  |");
	gotoxy(x, y + 6);
	printf("'----------------'");
}
void five_dice(int x, int y) {
	gotoxy(x, y);
	printf(".----------------.");
	gotoxy(x, y + 1);
	printf("|  @          @  |");
	gotoxy(x, y + 2);
	printf("|                |");
	gotoxy(x, y + 3);
	printf("|        @       |");
	gotoxy(x, y + 4);
	printf("|                |");
	gotoxy(x, y + 5);
	printf("|  @          @  |");
	gotoxy(x, y + 6);
	printf("'----------------'");
}
void six_dice(int x, int y) {
	gotoxy(x, y);
	printf(".----------------.");
	gotoxy(x, y + 1);
	printf("|  @          @  |");
	gotoxy(x, y + 2);
	printf("|                |");
	gotoxy(x, y + 3);
	printf("|  @          @  |");
	gotoxy(x, y + 4);
	printf("|                |");
	gotoxy(x, y + 5);
	printf("|  @          @  |");
	gotoxy(x, y + 6);
	printf("'----------------'");
}