#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <mysql.h>

#define BUTTON_UP 17		// 배팅 up 버튼 
#define BUTTON_DOWN 27		// 배팅 down 버튼 
#define BUTTON_TEN 41		// 카운트 ten 버튼 
#define BUTTON_FIFTY 49		// 카운트 50 버튼 
#define BUTTON_HUNDRED 57	// 카운트 100 버튼 
#define BUTTON_START 75		// 게임 시작 버튼 

void gotoxy(int x, int y);		// 좌표 출력을 위한 함수
void slot_main(char* id, char* pass, MYSQL* connection);	// slot 게임의 메인역할
void slot_disp_board();										// slot 게임 보드 판 출력
void slot_play(int(*slot)[10], int gamecnt,int bet, char* id, char* pass, MYSQL* connection);	//	슬롯판 게임과 출력
void slot_input_value(int(*slot)[10]);		// 슬롯에 1~4 / 10 확률 넣기
int slot_calc(int(*slot)[10],int bet);		// 슬롯 값 계산 
void Aform(int x, int y);					// 슬롯 모양 폼
void Kform(int x, int y);
void Sform(int x, int y);
void SEVENform(int x, int y);