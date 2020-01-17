#include <stdio.h>
#include <conio.h>
#include <mysql.h>

#define UPKEY 72			// 방향키 위 버튼의 ASCII CODE 값
#define DOWNKEY 80			// 방향키 아래 버튼의 ASCII CODE 값
#define ENTER 13			// 방향키 엔터 버튼의 ASCII CODE 값

void taisai_intro(char* id, char* pass, MYSQL* connection) {
	int x = 27, y = 12, sel = 0;
	while (1) {
		while (1) {

			system("cls");
			printf("                                                                    \n");
			printf("                                                                    \n");
			printf("        /$$$$$$$$ /$$$$$$  /$$$$$$        /$$$$$$   /$$$$$$  /$$$$$$\n");
			printf("       |__  $$__//$$__  $$|_  $$_/       /$$__  $$ /$$__  $$|_  $$_/\n");
			printf("          | $$  | $$  | $$  | $$        | $$  |__/| $$  | $$  | $$  \n");
			printf("          | $$  | $$$$$$$$  | $$        |  $$$$$$ | $$$$$$$$  | $$  \n");
			printf("          | $$  | $$__  $$  | $$         |____  $$| $$__  $$  | $$  \n");
			printf("          | $$  | $$  | $$  | $$         /$$  | $$| $$  | $$  | $$  \n");
			printf("          | $$  | $$  | $$ /$$$$$$      |  $$$$$$/| $$  | $$ /$$$$$$\n");
			printf("          |__/  |__/  |__/|______/       |______/ |__/  |__/|______/\n");
			printf("                                                                    \n");
			printf("                                                                    \n");
			printf("                               1. 계속하기                           \n");
			printf("                               2. 돌아가기                           \n");
			gotoxy(x, y);
			printf("▶");
			if (_kbhit()) {	// 키 입력 받으면 실행
				sel = _getch();	// 입력 받은키 sel에 저장
				// 방향키는 처음에 224 를 주고 그 다음 한번더 아스키코드를 받기때문에 다른키와 구별을 위해 224를 준다.
				//밑에 y 값이 메뉴좌표값 초과하지 못하도록 하는 if문
				if (sel == 224) {
					sel = _getch();
					if (sel == UPKEY)
						y--;
					if (sel == DOWNKEY)
						y++;
				}
				if (sel == ENTER)
					break;
				if (y == 11)
					y++;
				if (y == 14)
					y--;
			}
			Sleep(100);
		}
		if (y == 12) {
			system("mode con cols=150 lines=60");
			taisai_main(id, pass, connection);
		}
		else { system("mode con cols=105 lines=30"); return; }
	}
}
