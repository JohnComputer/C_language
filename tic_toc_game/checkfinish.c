int checkfinish(int check[3][3], int cnt) {
	//tic tac toe ������ �迭 ��, �÷������� ũ�Ⱑ Ŀ���ٸ� for ������ ȿ�����ϼ� ������ 3*3�ǰ�� if�� ȿ�����̰� �������ϰ� ����.
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
		printf("ù��° player�� �¸� �Ͽ����ϴ�.");
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
		printf("��ǻ�Ͱ� �¸� �Ͽ����ϴ�.");
		return 10;
	}
	return cnt;
}