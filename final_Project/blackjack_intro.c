#include <stdio.h>
#include <conio.h>
#include <mysql.h>

#define UPKEY 72			// ����Ű �� ��ư�� ASCII CODE ��
#define DOWNKEY 80			// ����Ű �Ʒ� ��ư�� ASCII CODE ��
#define ENTER 13			// ����Ű ���� ��ư�� ASCII CODE ��
// ------------------- ���ӽ��۽� ��Ʈ�� ȭ�� �Լ� -----------------------------------------------------------
void blackjack_intro(char* id, char* pass, MYSQL* connection) {
	// id , pass �α��ν� �Է��� ���̵�� ����� ���� / ���� ���� ���� MYSQL connection ���� �Լ��� �Ѱ���.
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
			printf("                    1. ���ӽ���                       \n");
			printf("                    2. ���ư���                       \n");
			printf("                                                     \n");

			gotoxy(x, y);
			printf("��");
			if (_kbhit()) {	// Ű �Է� ������ ����
				sel = _getch();	// �Է� ����Ű sel�� ����
				// ����Ű�� ó���� 224 �� �ְ� �� ���� �ѹ��� �ƽ�Ű�ڵ带 �ޱ⶧���� �ٸ�Ű�� ������ ���� 224�� �ش�.
				//�ؿ� y ���� �޴���ǥ�� �ʰ����� ���ϵ��� �ϴ� if��
				if (sel == 224) {
					sel = _getch();
					if (sel == UPKEY)	// UP / DOWN / ENTER ��� ������ define ASCII code �� ����.
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
			//���� ���۽� �ܼ�â ������ ������ �Բ� ���� ���� ����.
		}
		else { system("mode con cols=105 lines=30"); return; }
	}
}