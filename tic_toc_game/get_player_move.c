#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_player_move(int board[3][3])
{
	int x, y;
	while (1) {
		printf("첫번째 선수가 착수할 행렬값은 : ");
		scanf("%d %d", &x, &y);
		if (board[x][y] == 0) {
			board[x][y] = 1;
			return;
		}
		else {
			printf("잘못된 위치입니다.\n");
		}
	}
}