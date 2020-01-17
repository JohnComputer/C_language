#include "a.h"
//-------------------main-------------------------------
int main(void)
//quit 수정 -> cnt 그리고 굳이 int 로 하여 반환값을 받을 필요없이 check 에만 cnt값을 주어 값 증가 시키기.
//다시 공부한다는 생각으로 직접 다르게 제작..
{
	system("mode con cols=45 lines=20");
	srand((unsigned)time(NULL));
	int board[3][3];
	int cnt = 0;
	init_board(board);
	disp_board(board);
	do {
		// 컴퓨터가 먼저 둬야함 1,1 에 나두는것이 좋지만 다른곳에 두었도 컴퓨터가 먼저 한수 두면 이김.
		printf("엔터키를 누르면 컴퓨터가 좌표를 선택합니다.\n");
		_getch();
		get_computer_move(board,2);
		system("cls");
		disp_board(board);
		cnt = checkfinish(board, cnt);
		if (cnt >= 9) {
			if (cnt == 10) {  //cnt가 10이면 누군가가 마지막에 승부를 냈기 때문에 무승부를 출력하지 않고 종료해야한다.
				break;
			}
			else {
				printf("게임이 무승부로 끝났습니다.\n");
				break;
			}
		}
		get_player_move(board);
		system("cls");
		disp_board(board);
		cnt = checkfinish(board, cnt);
		//_getch();
		//system("cls"); 어디다 두었는지 확인을 위해서 일단 보류!!! 수정완료 27,40줄
	} while (cnt <= 9);
	_getch();
	return 0;
}