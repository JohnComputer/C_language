#include <stdio.h>
#include <conio.h>
#include <mysql.h>

#define UPKEY 72			// ����Ű �� ��ư�� ASCII CODE ��
#define DOWNKEY 80			// ����Ű �Ʒ� ��ư�� ASCII CODE ��
#define ENTER 13			// ����Ű ���� ��ư�� ASCII CODE ��

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
			printf("                               1. ����ϱ�                           \n");
			printf("                               2. ���ư���                           \n");
			gotoxy(x, y);
			printf("��");
			if (_kbhit()) {	// Ű �Է� ������ ����
				sel = _getch();	// �Է� ����Ű sel�� ����
				// ����Ű�� ó���� 224 �� �ְ� �� ���� �ѹ��� �ƽ�Ű�ڵ带 �ޱ⶧���� �ٸ�Ű�� ������ ���� 224�� �ش�.
				//�ؿ� y ���� �޴���ǥ�� �ʰ����� ���ϵ��� �ϴ� if��
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
