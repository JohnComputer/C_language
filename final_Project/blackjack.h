#pragma once
#define _CRT_SECURE_NO_WARNINGS		// ������ ���� ���� �޼��� ó��
#include <stdio.h>			// �⺻ �����
#include <Windows.h>		// ȭ�� Ŭ����� �ܼ�â ������ ����
#include <conio.h>			// _getch�� �߰��߰� �극��ũ�� ���� ����
#include <mysql.h>

void card_suffle(int(*blackjack_card)[52]); // ī�带 �����ش�.
void blackjack_get_player(int* playerNum, int player_x[3], int player_y);			// �÷��̾�� ����
void blackjack_disp_board();														// ���� ���÷���
void blackjack_betting(int* playerNum, int *bet, int player_x[3], int player_y);	// ���� ����
void insert_deck(int X, int Y, int* cnt, int(*play)[8], int(*blackjack_card)[52]);	// ī�尪 �Է� �� ����
void show_card(int x, int y, int cardnum);											// �������� ī��
void back_card(int x, int y);														// �޸� ī��
void blackjack_calc(int(*playing)[8], int play_num, int cnt, int* sum, int* die, int* stop, int* player_stopcard);
// ���� ī�尪 ��� �� ��� �Է�
void blackjack_reshow(int playerNum, int* cnt, int(*playing)[8], int* sum, int* bet, int* die, int dealer_open);
// ���� ȭ�鿡 �ٽ� ��µǾ����� �Լ� (����� ����� ǥ���Ұ� �ٽ� ǥ����)
int blackjack_finish(int* sum, int* die, int* bet);
// ������ ��� �ϰ� ���ñݾ� ����