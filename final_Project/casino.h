#pragma once
#define _CRT_SECURE_NO_WARNINGS		// ������ ���� ���� �޼��� ó��
#include <stdio.h>			// �⺻ �����
#include <Windows.h>		// ȭ�� Ŭ����� �ܼ�â ������ ����
#include <conio.h>			// _getch�� �߰��߰� �극��ũ�� ���� ����
#include <stdlib.h>			// rand�Լ� ���
#include <mysql.h>

#pragma comment(lib,"libmysql.lib") 

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "0000"
#define DB_NAME "casinos"

#define UPKEY 72			// ����Ű �� ��ư�� ASCII CODE ��
#define DOWNKEY 80			// ����Ű �Ʒ� ��ư�� ASCII CODE ��
#define ENTER 13			// ����Ű ���� ��ư�� ASCII CODE ��

#define LOGIN 14			// �α���    Y�� ��ǥ
#define REGISTER 15			// ȸ������    Y�� ��ǥ
#define BLACKJACK 16		// ����    Y�� ��ǥ
#define TAISAI 17		    // ���̻���  Y�� ��ǥ
#define SLOT 18		        // ����     Y�� ��ǥ
#define COIN 19				// ���� ���� Y�� ��ǥ
#define RANKING 20			// ��ŷ    Y�� ��ǥ
#define END 21				// ���� ���� Y�� ��ǥ

void gotoxy(int x, int y);      // ��ǥ�� ���� �Լ�
void blackjack_intro(char* id, char* pass,MYSQL* connection);	// ���� ��Ʈ��
void taisai_intro(char* id, char* pass, MYSQL* connection);			// ���̻��� ��Ʈ��
void slot_intro(char* id, char* pass, MYSQL* connection);		    	// ���� ��Ʈ��
void slot_main(char* id, char* pass, MYSQL* connection);		    	// ���� ��Ʈ��
void blackjack_main(int* id, int* pass, MYSQL* connection);	 // ���� ���� ����
void taisai_main(int* id, int*  pass, MYSQL* connection);				// ���̻��� ���� ����