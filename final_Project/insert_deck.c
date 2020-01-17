#include <stdio.h>
#include <time.h>

void insert_deck(int X, int Y, int* cnt, int(*play)[8], int(*blackjack_card)[52]) {
	int a, b;
	while (1) {
		a = rand() % 3;
		b = rand() % 52;
		if (blackjack_card[a][b] != -1) {
			play[X][Y] = blackjack_card[a][b];
			blackjack_card[a][b] = -1;
			cnt[X]++;
			return;
		}
	}
}