void init_board(int board[][3])
{
	int x, y;
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++) board[x][y] = 0;
}