#include "a.h"
//-------------------main-------------------------------
int main(void)
//quit ���� -> cnt �׸��� ���� int �� �Ͽ� ��ȯ���� ���� �ʿ���� check ���� cnt���� �־� �� ���� ��Ű��.
//�ٽ� �����Ѵٴ� �������� ���� �ٸ��� ����..
{
	system("mode con cols=45 lines=20");
	srand((unsigned)time(NULL));
	int board[3][3];
	int cnt = 0;
	init_board(board);
	disp_board(board);
	do {
		// ��ǻ�Ͱ� ���� �־��� 1,1 �� ���δ°��� ������ �ٸ����� �ξ��� ��ǻ�Ͱ� ���� �Ѽ� �θ� �̱�.
		printf("����Ű�� ������ ��ǻ�Ͱ� ��ǥ�� �����մϴ�.\n");
		_getch();
		get_computer_move(board,2);
		system("cls");
		disp_board(board);
		cnt = checkfinish(board, cnt);
		if (cnt >= 9) {
			if (cnt == 10) {  //cnt�� 10�̸� �������� �������� �ºθ� �±� ������ ���ºθ� ������� �ʰ� �����ؾ��Ѵ�.
				break;
			}
			else {
				printf("������ ���ºη� �������ϴ�.\n");
				break;
			}
		}
		get_player_move(board);
		system("cls");
		disp_board(board);
		cnt = checkfinish(board, cnt);
		//_getch();
		//system("cls"); ���� �ξ����� Ȯ���� ���ؼ� �ϴ� ����!!! �����Ϸ� 27,40��
	} while (cnt <= 9);
	_getch();
	return 0;
}