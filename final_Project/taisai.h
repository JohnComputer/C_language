#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>		//�⺻������� ���� ���
#include <conio.h>		//getch()�� �Է°� �߰��߰� �극��ũ�� ���� �Լ�
#include <Windows.h>	//sleep�Լ� ���
#include <mysql.h>

//---------------���� �÷��̻� ���� ������ ���� �ݾ��� ���� ����ü ����------------------------
typedef struct playdice {
	int Abigsmall[2];		// ���� ũ������
	int Bevenodd[2];		// ���� ¦ / Ȧ
	int Cpairdice[6];		// 3���� 2���� ���� ��
	int Eseltriple[6];		// 3���� �ֻ��� �����ϰ� �� ���� ����
	int Ftotal[18];			// �ֻ��� ��
	int Gdomino[15];		// 2���� �ֻ��� ����
	int Hsingle[6];			// �� �ֻ��� ��
	int Danytriple;			// 3���� �ֻ����� ����
} DICE;

void taisai_board();	// ���̻��� ���� ���
void taisai_reshow(int(*rec_dice)[4], DICE re_d, int board_on); // ���̻��� �������� ��� �Լ�
void taisai_show(int* dice, int(*rec_dice)[4], int cnt);	// �ֻ��� ������ ȭ�� ��� �� ����
int taisai_calc(int* dice, int* onoff, DICE game_d);		// �ֻ��� �� ���
void taisai_reshow_board();									// ���̻��� ��갪��°� ���� �����
void one_dice(int x, int y);								// �ֻ��� ���
void two_dice(int x, int y);
void three_dice(int x, int y);
void four_dice(int x, int y);
void five_dice(int x, int y);
void six_dice(int x, int y);