#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
void init_board(int board[][3]);
void disp_board(int board[3][3]);
void get_player_move(int board[3][3]);
void get_computer_move(int board[3][3],int check);
int checkfinish(int check[3][3], int cnt);