#pragma once
#define _CRT_SECURE_NO_WARNINGS		// 버전에 따른 오류 메세지 처리
#include <stdio.h>			// 기본 입출력
#include <Windows.h>		// 화면 클리어와 콘솔창 사이즈 조절
#include <conio.h>			// _getch로 중간중간 브레이크를 위해 정의
#include <mysql.h>

void card_suffle(int(*blackjack_card)[52]); // 카드를 섞어준다.
void blackjack_get_player(int* playerNum, int player_x[3], int player_y);			// 플레이어수 구함
void blackjack_disp_board();														// 블랙잭 디스플레이
void blackjack_betting(int* playerNum, int *bet, int player_x[3], int player_y);	// 블랙잭 배팅
void insert_deck(int X, int Y, int* cnt, int(*play)[8], int(*blackjack_card)[52]);	// 카드값 입력 및 저장
void show_card(int x, int y, int cardnum);											// 보여지는 카드
void back_card(int x, int y);														// 뒷면 카드
void blackjack_calc(int(*playing)[8], int play_num, int cnt, int* sum, int* die, int* stop, int* player_stopcard);
// 블랙잭 카드값 계산 및 결과 입력
void blackjack_reshow(int playerNum, int* cnt, int(*playing)[8], int* sum, int* bet, int* die, int dealer_open);
// 블랙잭 화면에 다시 출력되어지는 함수 (숨길건 숨기고 표시할건 다시 표시함)
int blackjack_finish(int* sum, int* die, int* bet);
// 마지막 계산 하고 배팅금액 정산