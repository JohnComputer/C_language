#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_player_move(int board[3][3])
{
	int x, y;
	while (1) {
		printf("ù��° ������ ������ ��İ��� : ");
		scanf("%d %d", &x, &y);
		if (board[x][y] == 0) {
			board[x][y] = 1;
			return;
		}
		else {
			printf("�߸��� ��ġ�Դϴ�.\n");
		}
	}
}