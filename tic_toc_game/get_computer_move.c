void get_computer_move(int board[3][3],int check) {
	int x, y;
	//��ü������ && ������ ��� 0���� Ȯ���� ��� , ���Է��Ͽ��� ��� return ���� ���� �ƴҰ�� ������ �������� ��ġ���� (ó��,��������������)
	//<-Ȯ���ʿ� ������ ó���� ����Ҽ��� ����.
	 //���� �ڵ忡���� ���°��� ���������� �Ͽ����� ���� �ڵ忡���� check���� ó���� �̱�� �ִ°��� ã�� �̱�� �ִ°��� ������ ���� 
	// �̱���� ������� ���°��� ã�� �׷��� �Ѱ��� ������� rand �� ��.
	if (board[0][0] == check) {
		if (board[0][1] == check && board[0][2] == 0) { board[0][2] = 2; return; } //�� ��� ���� 
		if (board[1][0] == check && board[2][0] == 0) { board[2][0] = 2; return; }
		if (board[0][2] == check && board[0][1] == 0) { board[0][1] = 2; return; } //�� ��� ���հ� ����
		if (board[2][0] == check && board[1][0] == 0) { board[1][0] = 2; return; }
	}
	if (board[0][2] == check) {
		if (board[0][1] == check && board[0][0] == 0) { board[0][0] = 2; return; } //�� ��� ����
		if (board[1][2] == check && board[2][2] == 0) { board[2][2] = 2; return; }
	}
	if (board[2][0] == check) {
		if (board[2][1] == check && board[2][2] == 0) { board[2][2] = 2; return; } //�� ��� ����
		if (board[1][0] == check && board[0][0] == 0) { board[0][0] = 2; return; }
	}
	if (board[2][2] == check) {
		if (board[2][1] == check && board[2][0] == 0) { board[2][0] = 2; return; } //�� ��� ���� 
		if (board[1][2] == check && board[0][0] == 0) { board[0][0] = 2; return; }
		if (board[0][2] == check && board[1][2] == 0) { board[1][2] = 2; return; } //�� ��� ���հ� ����
		if (board[2][0] == check && board[2][1] == 0) { board[2][1] = 2; return; }
	}
	if (board[1][1] == check) {
		if (board[1][0] == check && board[1][2] == 0) { board[1][2] = 2; return; } //�� ��� ���� ����
		if (board[1][2] == check && board[1][0] == 0) { board[1][0] = 2; return; }
		if (board[0][1] == check && board[2][1] == 0) { board[2][1] = 2; return; } // ����
		if (board[2][1] == check && board[0][1] == 0) { board[0][1] = 2; return; }
		if (board[0][0] == check && board[2][2] == 0) { board[2][2] = 2; return; } //�밢�� ������
		if (board[2][2] == check && board[0][0] == 0) { board[0][0] = 2; return; }
		if (board[2][0] == check && board[0][2] == 0) { board[0][2] = 2; return; } // �밢�� �����
		if (board[0][2] == check && board[2][0] == 0) { board[2][0] = 2; return; }
	}
	if (board[1][0] == check && board[1][2] == check && board[1][1] == 0) { board[1][1] = 2; return; }
	if (board[0][1] == check && board[2][1] == check && board[1][1] == 0) { board[1][1] = 2; return; }
	if (check == 2) {
		get_computer_move(board, 1);
	}
	//������ �̱�� ����� ���� ����ڰ� ����� ���� �ʾҴٴ� �����Ͽ� �Ǵ� ��ǻ�� ���� ����� �Ʒ� �ڵ�����ϸ� ������ �̱�.
	//����� ���� �ϴ°��� �̰��ӿ��� ���� �߿�...
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