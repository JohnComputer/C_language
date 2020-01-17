int checkfinish(int check[3][3], int cnt) {
	//tic tac toe 게임의 배열 즉, 플레이판의 크기가 커진다면 for 구문이 효율적일수 있으나 3*3의경우 if가 효율적이고 직관적일것 같음.
	cnt++;
	if ((check[0][0] == 1 && check[1][1] == 1 && check[2][2] == 1) ||
		(check[2][0] == 1 && check[1][1] == 1 && check[0][2] == 1) ||
		(check[0][0] == 1 && check[0][1] == 1 && check[0][2] == 1) ||
		(check[1][0] == 1 && check[1][1] == 1 && check[1][2] == 1) ||
		(check[2][0] == 1 && check[2][1] == 1 && check[2][2] == 1) ||
		(check[0][0] == 1 && check[1][0] == 1 && check[2][0] == 1) ||
		(check[0][1] == 1 && check[1][1] == 1 && check[2][1] == 1) ||
		(check[0][2] == 1 && check[1][2] == 1 && check[2][2] == 1)
		) {
		printf("첫번째 player가 승리 하였습니다.");
		return 10;
	}
	if ((check[0][0] == 2 && check[1][1] == 2 && check[2][2] == 2) ||
		(check[2][0] == 2 && check[1][1] == 2 && check[0][2] == 2) ||
		(check[0][0] == 2 && check[0][1] == 2 && check[0][2] == 2) ||
		(check[1][0] == 2 && check[1][1] == 2 && check[1][2] == 2) ||
		(check[2][0] == 2 && check[2][1] == 2 && check[2][2] == 2) ||
		(check[0][0] == 2 && check[1][0] == 2 && check[2][0] == 2) ||
		(check[0][1] == 2 && check[1][1] == 2 && check[2][1] == 2) ||
		(check[0][2] == 2 && check[1][2] == 2 && check[2][2] == 2)
		) {
		printf("컴퓨터가 승리 하였습니다.");
		return 10;
	}
	return cnt;
}