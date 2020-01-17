#include <stdio.h>
#include <conio.h>
#include <mysql.h>

#define UPKEY 72			// 방향키 위 버튼의 ASCII CODE 값
#define DOWNKEY 80			// 방향키 아래 버튼의 ASCII CODE 값
#define ENTER 13			// 방향키 엔터 버튼의 ASCII CODE 값
// ------------------- 게임시작시 인트로 화면 함수 -----------------------------------------------------------
void blackjack_intro(char* id, char* pass, MYSQL* connection) {
	// id , pass 로그인시 입력한 아이디와 비번을 받음 / 연결 상태 유지 MYSQL connection 다음 함수로 넘겨줌.
	int x = 17, y = 19, sel = 0;
	while (1) {
		while (1) {
			system("cls");
			printf("                                                     \n");
			printf("                                                     \n");
			printf("         $$$$$$$   $$ |                    $$|       \n");
			printf("         $$  __$$| $$ |                    $$ |      \n");
			printf("         $$ |  $$ |$$ | $$$$$$    $$$$$$$| $$ |  $$| \n");
			printf("         $$$$$$$| |$$ | |____$$  $$  _____|$$ | $$  |\n");
			printf("         $$  __$$| $$ | $$$$$$$ |$$ |      $$$$$$  / \n");
			printf("         $$ |  $$ |$$ |$$  __$$ |$$ |      $$  _$$<  \n");
			printf("         $$$$$$$  |$$ | $$$$$$$ | $$$$$$$| $$ | |$$| \n");
			printf("                                                     \n");
			printf("           $$$$$ |                     $$ |          \n");
			printf("             __$$ |                    $$ |          \n");
			printf("               $$ | $$$$$$    $$$$$$$  $$ |  $$|     \n");
			printf("               $$ | |____$$  $$  _____|$$ | $$  |    \n");
			printf("         $$    $$ | $$$$$$$ |$$ /      $$$$$$  /     \n");
			printf("         $$ |  $$ |$$  __$$ |$$ |      $$  _$$<      \n");
			printf("          $$$$$$  | $$$$$$$ | $$$$$$$  $$ |  $$      \n");
			printf("           ______/   _______|  _______||__|   __|    \n");
			printf("                                                     \n");
			printf("                    1. 게임시작                       \n");
			printf("                    2. 돌아가기                       \n");
			printf("                                                     \n");

			gotoxy(x, y);
			printf("▶");
			if (_kbhit()) {	// 키 입력 받으면 실행
				sel = _getch();	// 입력 받은키 sel에 저장
				// 방향키는 처음에 224 를 주고 그 다음 한번더 아스키코드를 받기때문에 다른키와 구별을 위해 224를 준다.
				//밑에 y 값이 메뉴좌표값 초과하지 못하도록 하는 if문
				if (sel == 224) {
					sel = _getch();
					if (sel == UPKEY)	// UP / DOWN / ENTER 모두 위에서 define ASCII code 값 정의.
						y--;
					if (sel == DOWNKEY)
						y++;
				}
				if (sel == ENTER)
					break;
				if (y == 18)
					y++;
				if (y == 21)
					y--;
			}
			Sleep(100);
		}
		if (y == 19) {
			system("mode con cols=130 lines=40");
			blackjack_main(id, pass, connection);
			//게임 시작시 콘솔창 사이즈 조절과 함께 블랙젝 메인 연결.
		}
		else { system("mode con cols=105 lines=30"); return; }
	}
}