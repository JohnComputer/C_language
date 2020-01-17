#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void show_card(int x, int y, int cardnum) 
{
	char clover[3] = { "♣" };		// char 1개로 표현이 불가능 하여 배열로 표현
	char heart[3] = { "♥" };
	char diamond[3] = { "◈" };
	char spade[3] = { "♠" };
	char temp[3];					// 아래에서 함께 출력하기 위해 잠시 모양을 담는다.(그림)
	char cardform;					// 범위에 따른 카드모양 출력 저장

	switch (cardnum / 13) {
	case 0:
		strcpy(temp, clover);		// 0~52까지 중 0~12클로버/13~25하트/26~38다이아/39~51스페이드
		break;
	case 1:
		strcpy(temp, heart);
		break;
	case 2:
		strcpy(temp, diamond);
		break;
	case 3:
		strcpy(temp, spade);
		break;
	}
	switch (cardnum % 13) {			// 카드를 나누어 나오는 0~12의 정수값을 모양으로 뽑기위해 변환
	case 0:
		cardform = 'A';
		break;
	case 1:
		cardform = '2';
		break;
	case 2:
		cardform = '3';
		break;
	case 3:
		cardform = '4';
		break;
	case 4:
		cardform = '5';
		break;
	case 5:
		cardform = '6';
		break;
	case 6:
		cardform = '7';
		break;
	case 7:
		cardform = '8';
		break;
	case 8:
		cardform = '9';
		break;
	case 9:
		//10을 char로 표현이 안됨 그래서 Ten의 약자 
		cardform = 'T';
		break;
	case 10:
		cardform = 'J';
		break;
	case 11:
		cardform = 'Q';
		break;
	case 12:
		cardform = 'K';
		break;
	}
	gotoxy(x, y);
	printf(".-------.");
	gotoxy(x, y + 1);
	printf("|%s-----|", temp);
	gotoxy(x, y + 2);
	printf("|-------|");
	gotoxy(x, y + 3);
	printf("|---%c---|", cardform);
	gotoxy(x, y + 4);
	printf("|-------|");
	gotoxy(x, y + 5);
	printf("|-----%s|", temp);
	gotoxy(x, y + 6);
	printf("'-------'");
}