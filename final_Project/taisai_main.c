#include "taisai.h"

void taisai_main(int* id, int*  pass, MYSQL* connection) {
	int i = 0, gostop = 0;	 // i = for���� / gostop = ��������
	char game = NULL;		// ���ð��� ���� ����
	int cnt = 0, rec_dice[10][4] = { 0 };		// ���� �Ǽ� / �ֻ����� ���� �� ����.
	int dice[3] = { 0 }, bet = 0, gamenum = 0;		// dice = �ֻ��� ��, bet = ���� �ӽ����尪, gamenum = ������ ��������
	int x = 0, y = 43, onoff[8] = { 0 }, end = 1;	// x,y = ���� ���� ���� ��ǥ / onoff = ���������� ���࿩�� / end = �������� 
	int betsum = 0;

	MYSQL_RES* sql_result = NULL;	// sql ��ɹ� ��� ���� 
	MYSQL_ROW row = NULL;			// ��ɹ� ����ÿ� ��ȯ�Ǵ� ���� ��.
	char query[100] = { 0 };		// ��ɹ� ���� ����
	int query_stat = 0;				// ��ɹ� ���� ���� ��.

	while (end != 0) {				//���� ���� ���� �� Ȯ��.
		DICE playgame = { 0 };		// ���� �ʱ�ȭ
		for (i = 0; i < 8; i++) {
			if (i < 3)
				dice[i] = 0;
			onoff[i] = 0;

		}
		while (1) {
			system("cls");
			taisai_reshow(rec_dice, playgame, 1);
			gotoxy(x, y);
			printf("����ӿ� �����ϰڽ��ϱ�? (a~h) : ");
			scanf(" %c", &game);
			printf("���ӿ� ��ȣ�� �Է��� �ּ���. | a:2 | b:2 | c:6 | d:1 | e:6 | f:18 | g:15 | h:3 |");
			scanf("%d", &gamenum);
			printf("�󸶸� �����ϰڽ��ϱ�?? : ");
			scanf("%d", &bet);
			// ���� ���� �� ���� �ݾ� ����
			switch (game)						// ���� ��ȣ�� �Է¹ް� ���ð��� ����.
			{
			case 'a':
				if (gamenum > 2)
					break;
				playgame.Abigsmall[gamenum - 1] += bet;
				onoff[0] = 1;
				break;
			case 'b':
				if (gamenum > 2)
					break;
				playgame.Bevenodd[gamenum - 1] += bet;
				onoff[1] = 1;
				break;
			case 'c':
				if (gamenum > 6)
					break;
				playgame.Cpairdice[gamenum - 1] += bet;
				onoff[2] = 1;
				break;
			case 'd':
				playgame.Danytriple += bet;
				onoff[3] = 1;
				break;
			case 'e':
				if (gamenum > 6)
					break;
				playgame.Eseltriple[gamenum - 1] += bet;
				onoff[4] = 1;
				break;
			case 'f':
				if (gamenum > 18)
					break;
				playgame.Ftotal[gamenum - 1] += bet;
				onoff[5] = 1;
				break;
			case 'g':
				if (gamenum > 15)
					break;
				playgame.Gdomino[gamenum - 1] += bet;
				onoff[6] = 1;
				break;
			case 'h':
				if (gamenum > 6)
					break;
				playgame.Hsingle[gamenum - 1] += bet;
				onoff[7] = 1;
				break;
			default:
				printf("���ӹ�ȣ�� �ٽ� Ȯ���Ͽ� �ּ���.");
				break;
			}
			system("cls");
			taisai_reshow(rec_dice, playgame, 1);
			gotoxy(x, y);
			printf("������ �׸��Ͻðڽ��ϱ�?? 0.�׸�");
			gotoxy(x, y+1);
			printf("����Ϸ��� �ƹ��ų� �Է��Ͻÿ�. : ");
			scanf("%d", &gostop);
			if (gostop == 0)
				break;
		}
		system("cls");
		taisai_reshow_board();
		taisai_show(dice,rec_dice,cnt);						// �ֻ����� �����ش�
		taisai_reshow(rec_dice, playgame, 0);		// 0�� �־� �������� ���� ���� ȭ���� �����ش�.
		cnt++;
		betsum = taisai_calc(dice, onoff, playgame);		// ������ ������ ����Ѵ�.
		puts(""); // ����
		sprintf(query, "select * from member where id = '%s' AND pass = '%s'", id, pass);
		query_stat = mysql_query(connection, query);
		sql_result = mysql_store_result(connection);	// �����Ͱ˻��� ������ ������ ȣ�� ������ ��� �ΰ�

		while ((row = mysql_fetch_row(sql_result))) {
			gotoxy(20, 15);
			printf("ID : %s   COIN : %d\n", row[0],atoi(row[2]));
			// �߿�!!!!!!!!!!!!!!!!!!!!! atoi�� ���Ͽ� ascii to interger ���ڿ� ���¸� ���ڷ� �ٲ� �־�� %d�� ��µ� �����ϰ� int�� ��밡��!!
			betsum += atoi(row[2]);
			_getch();
			break;
		}
		sprintf(query, "UPDATE member SET coin = %d where id = '%s' AND pass = '%s'", betsum, id, pass);
		query_stat = mysql_query(connection, query);
		gotoxy(20, 16);
		printf("���ñݾ� DB���� �Ϸ�\n");

		// mysql_store_result() �Լ� �Ŀ� mysql_fetch_row()�Լ��� ���̻� �˻��� �ο찡 ������ NULL ���� ��, �˻��� �ȵǸ� NULL�� ���
		if (sql_result->row_count == 0) {		// �˻��Ǿ��� �Ҵ� �� ���� ������� row sql_result���� row_count�� 0 ���ΰ� Ȯ�� 
			printf("������ ���� ����");
		}
		gotoxy(25, 3);
		printf("������ �����Ͻðڽ��ϱ�?? 0.����");
		scanf("%d", &end);
	}
	system("mode con cols=105 lines=25");
}