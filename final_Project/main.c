#include "casino.h"
// ------------------------------- main --------------------------------------------------------
int main() {
	int x = 34, y = 14; // ȭ��ǥ ��ǥ �Է�
	int sel, rankcnt;		// getch�� �Է¹��� �ƽ�Ű�ڵ� ���� / rank ����

	MYSQL* connection = NULL, conn; // sql ���� ���� / ���� ���� ����
	MYSQL_RES* sql_result = NULL;	// sql ��ɹ� ��� ���� 
	MYSQL_ROW row = NULL;			// ��ɹ� ����ÿ� ��ȯ�Ǵ� ���� ��.

	char id[15] = { 0 };			// �Է¹޴� ID
	char pass[15] = { 0 };			// �Է¹޴� PASSWD
	int coin, login = 0;			// ���Խ� �ʿ��� ���� ���� / login ���� ����
	int getcoin = 0;				//�ӽ����� ����
	int recoin;						// ���� ����

	char query[100] = { 0 };		// query ��ɹ�
	int query_stat = 0;				// ��ɹ� ���� ���� ��.

	mysql_init(&conn); 
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	//mysql ���� �����ͺ��̽� ���� (connection Ȯ��)

	if (connection == NULL) {	// ���� ���н� ���� �޼���
		printf("connect error!\n");
		exit(1);
	}

	system("mode con cols=105 lines=30"); //���۽ÿ� ȭ�� ũ�� ����

	srand((unsigned)time(NULL));	// srand�� ����ǥ�� seed �� ���� ó�� ����ÿ� �ѹ��� ���ָ� ��.

	while (1) {
		query_stat = 0;

		while (1) {
			system("cls");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("    /$$$$$$ /$$   /$$  /$$$$$$         /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$     \n");
			printf("   |_  $$_/| $$$ | $$ /$$__  $$       /$$__  $$ /$$__  $$ /$$__  $$|_  $$_/| $$$ | $$ /$$__  $$    \n");
			printf("     | $$  | $$$$| $$| $$  ' $$      | $$  '__/| $$  ' $$| $$  '__/  | $$  | $$$$| $$| $$  ' $$    \n");
			printf("     | $$  | $$ $$ $$| $$  | $$      | $$      | $$$$$$$$|  $$$$$$   | $$  | $$ $$ $$| $$  | $$    \n");
			printf("     | $$  | $$  $$$$| $$  | $$      | $$      | $$__  $$ '____  $$  | $$  | $$  $$$$| $$  | $$    \n");
			printf("     | $$  | $$'  $$$| $$  | $$      | $$    $$| $$  | $$ /$$  ' $$  | $$  | $$'  $$$| $$  | $$    \n");
			printf("    /$$$$$$| $$ '  $$|  $$$$$$/      |  $$$$$$/| $$  | $$|  $$$$$$/ /$$$$$$| $$ '  $$|  $$$$$$/    \n");
			printf("   |______/|__/  '__/ '______/        '______/ |__/  |__/ '______/ |______/|__/  '__/ '______/     \n");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("                                     1. �α���                                                      \n");
			printf("                                     2. ȸ������                                                     \n");
			printf("                                     3. BLACK JACK                                                 \n");
			printf("                                     4. TAI SAI (SIC BO)                                           \n");
			printf("                                     5. SLOT 777                                                   \n");
			printf("                                     6. ���� ����                                                   \n");
			printf("                                     7. ����ǥ                                                     \n");
			printf("                                     8. ��������                                                    \n");
			printf("                                                                                                   \n");
			printf("                                                                                                   \n");
			printf("                                                                                   Make by INO     \n");
			printf("                                                                                 Design by INO     \n");
			printf("                                                                           bizbyinho@gmail.com     \n");


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
				if (y == 13)
					y++;
				if (y == 22)
					y--;
			}
			Sleep(100);
		}
		switch (y) {
		case LOGIN:
			system("cls");
			printf("\t< �α��� >\n\n");
			printf("���̵� : ");
			scanf(" %s", id);			// ���̵�� �н����� ���� �Է� ���� ó�� ����Ἥ �޴´�.

			printf("�н����� : ");
			scanf(" %s", pass);


			sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass); // MYSQL ��ȸ ��ɹ� ����
			query_stat = mysql_query(connection, query);	// MYSQL ��ɹ� ����
			sql_result = mysql_store_result(connection);	// �����Ͱ˻��� ������ ������ ȣ�� ������ ��� �ΰ�

			while ((row = mysql_fetch_row(sql_result))) {
				printf("�α��� ����\n");
				printf("ID : %s PASSWORD: %s COIN : %d\n", row[0], row[1], atoi(row[2])); 
				login = 1;	// �α��� Ȯ�� ����.
				// �߿�!!!!!!!!!!!!!!!!!!!!! atoi�� ���Ͽ� ascii to interger ���ڿ� ���¸� ���ڷ� �ٲ� �־�� %d�� ��µ� �����ϰ� int�� ��밡��!!
				break;
			}
			// mysql_store_result() �Լ� �Ŀ� mysql_fetch_row()�Լ��� ���̻� �˻��� �ο찡 ������ NULL ���� ��, �˻��� �ȵǸ� NULL�� ���
			if (sql_result->row_count == 0) {		// �˻��Ǿ��� �Ҵ� �� ���� ������� row sql_result���� row_count�� 0 ���ΰ� Ȯ�� 
				printf("�α��ν���");
			}
			mysql_free_result(sql_result); // ����¿� �Ҵ�� �޸� ����
			_getch();
			break;

		case REGISTER:
			system("cls");
			// ���̵�� �н����� ���� �Է� ���� ó�� ����Ἥ �޴´�.
			printf("������ ���̵� �Է��Ͽ� �ּ���. : ");
			scanf(" %s", id);

			printf("������ �н����带 �Է��Ͽ� �ּ��� : ");
			scanf(" %s", pass);

			printf("COIN�� �־��ּ���. : \n");
			scanf("%d", &coin);

			sprintf(query, "insert into member values" "('%s', '%s', '%d')", id, pass, coin);	// MYSQL ������ �Է� ��ɹ� ����
			query_stat = mysql_query(connection, query);										// MYSQL ������ �Է� ��ɹ� ����

			if (query_stat != 0) {
				fprintf(stderr, "�������� : %s", mysql_error(&conn));
				_getch();
				break;
			}

			printf("���Լ���");
			_getch();
			break;
		case BLACKJACK:
			if (login == 1) {		// �α��� Ȯ�� �� ���� �α��� �Ǿ����� ������� ���ڸ��� ����Ʈ �� ���.
				system("mode con cols=75 lines=30");
				blackjack_intro(id,pass,connection);
				break;
			}
			printf("�α��� ���� ��Ź�帳�ϴ�.");
			_getch();
			break;
		case TAISAI:
			if (login == 1) {		// �α��� Ȯ�� �� ���� �α��� �Ǿ����� ������� ���ڸ��� ����Ʈ �� ���.
				system("mode con cols=90 lines=30");
				taisai_intro(id, pass, connection);
				break;
			}
			printf("�α��� ���� ��Ź�帳�ϴ�.");
			_getch();
			break;
		case SLOT:
			if (login == 1) {		// �α��� Ȯ�� �� ���� �α��� �Ǿ����� ������� ���ڸ��� ����Ʈ �� ���.
				system("mode con cols=50 lines=30");
				slot_intro(id, pass, connection);
				break;
			}
			printf("�α��� ���� ��Ź�帳�ϴ�.");
			_getch();
			break;
		case COIN:
			system("cls");
			printf("\t������ �����մϴ�\n");
			printf("������ ���̵� : ");
			scanf(" %s", id);

			printf("�н����� : ");
			scanf(" %s", pass);

			sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);	// MYSQL ��ȸ ��ɹ� ����
			query_stat = mysql_query(connection, query);	// MYSQL ��ɹ� ����
			sql_result = mysql_store_result(connection);	// �����Ͱ˻��� ������ ������ ȣ�� ������ ��� �ΰ�

			while ((row = mysql_fetch_row(sql_result))) {
				printf("���� �ܾ� ���� : %d\n",atoi(row[2])); 
				// atoi�� ���Ͽ� ascii to interger ���ڿ� ���¸� ���ڷ� �ٲ� �־�� %d�� ��µ� �����ϰ� int�� ��밡��!!
				getcoin = atoi(row[2]);
			}
			// mysql_store_result() �Լ� �Ŀ� mysql_fetch_row()�Լ��� ���̻� �˻��� �ο찡 ������ NULL ���� ��, �˻��� �ȵǸ� NULL�� ���
			if (sql_result->row_count == 0) {		// �˻��Ǿ��� �Ҵ� �� ���� ������� row sql_result���� row_count�� 0 ���ΰ� Ȯ�� 
				printf("�α��ν���");
				_getch();
				break;
			}
			// �α��� Ȯ�� �� �Ϸ� �� �Ʒ����� ����.
			printf("�����ϰ��� �ϴ� ������ �Է��ϼ���. : ");
			scanf("%d", &recoin);
			getcoin += recoin;			// ���� ���ΰ� ���� �ޱ�� �� ���� ��
			sprintf(query, "UPDATE member SET coin = %d where id = '%s' AND pass = '%s'",getcoin, id, pass);// MYSQL ���� ��ɹ� ����
			query_stat = mysql_query(connection, query);		// MYSQL ���� ��ɹ� ����
			printf("���� : %5d  �����Ϸ� ", recoin);
			_getch();
			break;
		case RANKING:
			system("cls");
			rankcnt = 0;
			sprintf(query, "select * from member ORDER BY 3 DESC");	// MYSQL ���� ��ɹ� ����
			query_stat = mysql_query(connection, query);			// MYSQL ���� ��ɹ� ����
			sql_result = mysql_store_result(connection);   // �����Ͱ˻��� ������ ������ ȣ�� ������ ��� �ΰ�
			printf(".-----------------------------------------------.\n");
			printf("     ��ŷ                  ID       ����     \n");
			while ((row = mysql_fetch_row(sql_result))) {
				rankcnt++;
				printf("\t%d\t%14s\t%10d\n", rankcnt, row[0], atoi(row[2]));
				//atoi�� ���Ͽ� ascii to interger ���ڿ� ���¸� ���ڷ� �ٲ� �־�� %d�� ��µ� �����ϰ� int�� ��밡��!!
			}
			// mysql_store_result() �Լ� �Ŀ� mysql_fetch_row()�Լ��� ���̻� �˻��� �ο찡 ������ NULL ���� ��, �˻��� �ȵǸ� NULL�� ���
			printf("'-----------------------------------------------'\n");
			mysql_free_result(sql_result); // ����¿� �Ҵ�� �޸� ����
			_getch();
			break;
		case END:
			mysql_close(connection); // ���� ����!!
			return 0;
		}
	}
}