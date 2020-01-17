void card_suffle(int(*blackjack_card)[52])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 52; j++) {
			blackjack_card[i][j] = j;
		}
	}
}