void get_computer_move(int board[3][3],int check) {
	int x, y;
	//전체적으로 && 연산자 사용 0임을 확인후 출력 , 값입력하였을 경우 return 으로 종료 아닐경우 마지막 랜덤으로 배치실행 (처음,위험하지않은곳)
	//<-확인필요 어차피 처음만 사용할수도 있음.
	 //원래 코드에서는 막는것을 중점적으로 하였지만 수정 코드에서는 check를줘 처음에 이길수 있는곳을 찾고 이길수 있는곳에 먼저둠 만약 
	// 이길곳이 없을경우 막는곳을 찾고 그래도 둘곳이 없을경우 rand 로 줌.
	if (board[0][0] == check) {
		if (board[0][1] == check && board[0][2] == 0) { board[0][2] = 2; return; } //┌ 모양 막기 
		if (board[1][0] == check && board[2][0] == 0) { board[2][0] = 2; return; }
		if (board[0][2] == check && board[0][1] == 0) { board[0][1] = 2; return; } //┌ 모양 사잇값 막기
		if (board[2][0] == check && board[1][0] == 0) { board[1][0] = 2; return; }
	}
	if (board[0][2] == check) {
		if (board[0][1] == check && board[0][0] == 0) { board[0][0] = 2; return; } //┐ 모양 막기
		if (board[1][2] == check && board[2][2] == 0) { board[2][2] = 2; return; }
	}
	if (board[2][0] == check) {
		if (board[2][1] == check && board[2][2] == 0) { board[2][2] = 2; return; } //└ 모양 막기
		if (board[1][0] == check && board[0][0] == 0) { board[0][0] = 2; return; }
	}
	if (board[2][2] == check) {
		if (board[2][1] == check && board[2][0] == 0) { board[2][0] = 2; return; } //┘ 모양 막기 
		if (board[1][2] == check && board[0][0] == 0) { board[0][0] = 2; return; }
		if (board[0][2] == check && board[1][2] == 0) { board[1][2] = 2; return; } //┘ 모양 사잇값 막기
		if (board[2][0] == check && board[2][1] == 0) { board[2][1] = 2; return; }
	}
	if (board[1][1] == check) {
		if (board[1][0] == check && board[1][2] == 0) { board[1][2] = 2; return; } //┼ 모양 막기 가로
		if (board[1][2] == check && board[1][0] == 0) { board[1][0] = 2; return; }
		if (board[0][1] == check && board[2][1] == 0) { board[2][1] = 2; return; } // 세로
		if (board[2][1] == check && board[0][1] == 0) { board[0][1] = 2; return; }
		if (board[0][0] == check && board[2][2] == 0) { board[2][2] = 2; return; } //대각선 우하향
		if (board[2][2] == check && board[0][0] == 0) { board[0][0] = 2; return; }
		if (board[2][0] == check && board[0][2] == 0) { board[0][2] = 2; return; } // 대각선 우상향
		if (board[0][2] == check && board[2][0] == 0) { board[2][0] = 2; return; }
	}
	if (board[1][0] == check && board[1][2] == check && board[1][1] == 0) { board[1][1] = 2; return; }
	if (board[0][1] == check && board[2][1] == check && board[1][1] == 0) { board[1][1] = 2; return; }
	if (check == 2) {
		get_computer_move(board, 1);
	}
	//무조건 이기는 방법중 만약 사용자가 정가운데 두지 않았다는 가정하에 또는 컴퓨터 먼저 실행시 아래 코드실행하면 무조건 이김.
	//가운데를 선점 하는것이 이게임에서 가장 중요...
	//if(board[1][1] == 0){board[1][1] == 2}
	if (check == 1) {
		while (1) {
			x = rand() % 3;
			y = rand() % 3;
			if (board[x][y] == 0) {
				board[x][y] = 2;
				return;
			}
		}
	}
}