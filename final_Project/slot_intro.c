#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <mysql.h>

#define UPKEY 72				// UPKEY / DOWNKEY // ENTER �ƽ�Ű �ڵ尪
#define DOWNKEY 80
#define ENTER 13

void slot_intro(char* id, char* pass, MYSQL* connection) {
	printf("                                               \n");
	printf("                                               \n");
	printf("        $$$$$$$$$ $$$$$$$$$ $$$$$$$$$  \n");
	printf("        $____$$  |$____$$  |$____$$  | \n");
	printf("            $$  /     $$  /     $$  /  \n");
	printf("           $$  /     $$  /     $$  /   \n");
	printf("          $$  /     $$  /     $$  /    \n");
	printf("         $$  /     $$  /     $$  /     \n");
	printf("         $__/      $__/      $__/      \n");
	printf("                                              \n");
	printf("                                              \n");
	printf("      ����Ͻ÷��� �ƹ���ư�̳� �����ּ���...       \n");
	_getch();
	slot_main(id,pass,connection);
}