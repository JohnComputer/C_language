#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <mysql.h>

#define BUTTON_UP 17		// ���� up ��ư 
#define BUTTON_DOWN 27		// ���� down ��ư 
#define BUTTON_TEN 41		// ī��Ʈ ten ��ư 
#define BUTTON_FIFTY 49		// ī��Ʈ 50 ��ư 
#define BUTTON_HUNDRED 57	// ī��Ʈ 100 ��ư 
#define BUTTON_START 75		// ���� ���� ��ư 

void gotoxy(int x, int y);		// ��ǥ ����� ���� �Լ�
void slot_main(char* id, char* pass, MYSQL* connection);	// slot ������ ���ο���
void slot_disp_board();										// slot ���� ���� �� ���
void slot_play(int(*slot)[10], int gamecnt,int bet, char* id, char* pass, MYSQL* connection);	//	������ ���Ӱ� ���
void slot_input_value(int(*slot)[10]);		// ���Կ� 1~4 / 10 Ȯ�� �ֱ�
int slot_calc(int(*slot)[10],int bet);		// ���� �� ��� 
void Aform(int x, int y);					// ���� ��� ��
void Kform(int x, int y);
void Sform(int x, int y);
void SEVENform(int x, int y);