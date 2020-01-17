void disp_board(int board[3][3])
{
	int i;
	for (i = 0; i < 3; i++) {
		printf("|---|---|---|\n");
		printf("| %d | %d | %d |\n", board[i][0], board[i][1], board[i][2]);
	}
	printf("|---|---|---|\n");
}