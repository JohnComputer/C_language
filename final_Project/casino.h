#pragma once
#define _CRT_SECURE_NO_WARNINGS		// 버전에 따른 오류 메세지 처리
#include <stdio.h>			// 기본 입출력
#include <Windows.h>		// 화면 클리어와 콘솔창 사이즈 조절
#include <conio.h>			// _getch로 중간중간 브레이크를 위해 정의
#include <stdlib.h>			// rand함수 사용
#include <mysql.h>

#pragma comment(lib,"libmysql.lib") 

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "0000"
#define DB_NAME "casinos"

#define UPKEY 72			// 방향키 위 버튼의 ASCII CODE 값
#define DOWNKEY 80			// 방향키 아래 버튼의 ASCII CODE 값
#define ENTER 13			// 방향키 엔터 버튼의 ASCII CODE 값

#define LOGIN 14			// 로그인    Y값 좌표
#define REGISTER 15			// 회원가입    Y값 좌표
#define BLACKJACK 16		// 블랙잭    Y값 좌표
#define TAISAI 17		    // 다이사이  Y값 좌표
#define SLOT 18		        // 슬롯     Y값 좌표
#define COIN 19				// 게임 시작 Y값 좌표
#define RANKING 20			// 랭킹    Y값 좌표
#define END 21				// 게임 시작 Y값 좌표

void gotoxy(int x, int y);      // 좌표를 위한 함수
void blackjack_intro(char* id, char* pass,MYSQL* connection);	// 블랙잭 인트로
void taisai_intro(char* id, char* pass, MYSQL* connection);			// 다이사이 인트로
void slot_intro(char* id, char* pass, MYSQL* connection);		    	// 슬롯 인트로
void slot_main(char* id, char* pass, MYSQL* connection);		    	// 슬롯 인트로
void blackjack_main(int* id, int* pass, MYSQL* connection);	 // 블랙잭 시작 메인
void taisai_main(int* id, int*  pass, MYSQL* connection);				// 다이사이 시작 메인