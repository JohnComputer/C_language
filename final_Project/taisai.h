#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>		//기본입출력을 위한 헤더
#include <conio.h>		//getch()로 입력과 중간중간 브레이크를 위한 함수
#include <Windows.h>	//sleep함수 사용
#include <mysql.h>

//---------------게임 플레이상 배팅 내역과 배팅 금액을 위한 구조체 선언------------------------
typedef struct playdice {
	int Abigsmall[2];		// 합의 크고작음
	int Bevenodd[2];		// 합의 짝 / 홀
	int Cpairdice[6];		// 3개중 2개가 같은 값
	int Eseltriple[6];		// 3개의 주사위 동일하고 그 값도 맞춤
	int Ftotal[18];			// 주사위 합
	int Gdomino[15];		// 2개의 주사위 조합
	int Hsingle[6];			// 각 주사위 값
	int Danytriple;			// 3개의 주사위가 동일
} DICE;

void taisai_board();	// 다이사이 보드 출력
void taisai_reshow(int(*rec_dice)[4], DICE re_d, int board_on); // 다이사이 게임진행 출력 함수
void taisai_show(int* dice, int(*rec_dice)[4], int cnt);	// 주사위 굴리는 화면 출력 및 저장
int taisai_calc(int* dice, int* onoff, DICE game_d);		// 주사위 값 계산
void taisai_reshow_board();									// 다이사이 계산값출력과 보드 재출력
void one_dice(int x, int y);								// 주사위 모양
void two_dice(int x, int y);
void three_dice(int x, int y);
void four_dice(int x, int y);
void five_dice(int x, int y);
void six_dice(int x, int y);