#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

//=============함수 호출===========
void input();
void print();
void car_S();
void car_M();
void car_H();
void car_B();
//===========구조체============
struct rec {

	int num;
	char carCode;
	char YesNo;
	int usedTime;
	int usedRoad;
	char carName[10];
	int price;
	int discount;
	int realPrice;
}X[10];

int p = 0;
//==============main=================
main()
{
	int sel;
	while(1){

		printf("\t┌───────────┐\n");
		printf("\t│1.자료입력\t\t│\n");
		printf("\t│2.자료출력\t\t│\n");
		printf("\t│3.종료    \t\t│\n");
		printf("\t└───────────┘\n");
		printf("\t원하시는 작업선택:");
		scanf("%d",&sel);
		fflush(stdin);
		system("cls");
		switch (sel){
			case 1:
				input();
				p++;
				break;
			case 2:
				print();
				break;
			case 3:
				return;
			default:
				printf("1~3번까지의 작업만선택가능합니다.\n");
		}
	}
}
//==============자료 입력==============
void input() 
{
	int i;
	while(1){
		printf("고객번호:");
		scanf("%d",&X[p].num);
		fflush(stdin);

		if(X[p].num < 1 || X[p].num > 9){
			printf("정수 1~9사이로 입력해주세요.^^\n");
			continue;
		}
		for(i=0; i<p; i++){
			if(X[i].num == X[p].num){
				printf("중복되는 고객번호가 있습니다.\n 다시입력하여 주십시오.\n");
				break;
			}
		}if(i == p){
			break;
		}
	}
	while(1){
		printf("차종코드:");
		scanf("%c",&X[p].carCode);
		fflush(stdin);

		if(X[p].carCode == 'S' || X[p].carCode == 's'){
			strcpy(X[p].carName,"소형승용차");
			break;
		}else if(X[p].carCode == 'M' || X[p].carCode == 'm'){
			strcpy(X[p].carName,"중형승용차");
			break;
		}else if(X[p].carCode == 'H' || X[p].carCode == 'h'){
			strcpy(X[p].carName,"승합차");
			break;
		}else if(X[p].carCode == 'B' || X[p].carCode == 'b'){
			strcpy(X[p].carName,"미니버스");
			break;
		}else{
			printf("자동차의 코드가 잘못되었습니다. 재입력 부탁드립니다.\n");
		}
	}
	while(1){
		printf("운전기사 이용여부:");
		scanf("%c",&X[p].YesNo);
		fflush(stdin);

		if(X[p].YesNo == 'Y' || X[p].YesNo == 'y' || X[p].YesNo == 'N' || X[p].YesNo == 'n'){
			break;
		}else{
			printf("이용여부를 제대로 입력하여 주십시오.\n");
		}
	}
	while(1){
		printf("이용시간:");
		scanf("%d",&X[p].usedTime);
		fflush(stdin);

		if(X[p].usedTime < 0 || X[p].usedTime > 999){
			printf("0 ~ 999사이의 숫자를 입력하여주세요.\n");
			continue;
		}
		break;
	}
	while(1){
		printf("이용거리:");
		scanf("%d",&X[p].usedRoad);
		fflush(stdin);

		if(X[p].usedRoad < 0 || X[p].usedRoad > 999){
			printf("0 ~ 999사이의 숫자를 입력하여주세요.\n");
			continue;
		}
		break;
	}
	if(X[p].carCode == 'S' || X[p].carCode == 's'){
		car_S();
	}else if(X[p].carCode == 'M' || X[p].carCode == 'm'){
		car_M();
	}else if(X[p].carCode == 'H' || X[p].carCode == 'h'){
		car_H();
	}else if(X[p].carCode == 'B' || X[p].carCode == 'b'){
		car_B();
	}
}
//===============자료 출력================
void print()
{
	int i;
	printf("\n고객번호   차종명       이용요금  할인액   청구액   비고  \n");
	printf("────────────────────────────");
	for(i=0; i<p; i++){
		printf("\n%2d\t  %5s\t%7d\t%7d\t  %7d   ",X[i].num,X[i].carName,X[i].price,X[i].discount,X[i].realPrice);
		if(X[i].realPrice >= 100000){
			printf("A");
		}
	}
	getch();
	system("cls");
}
//==================소형승용차============
void car_S()
{
	if(X[p].usedTime <= 12){
		X[p].price = 40000 + (X[p].usedTime * 76);
	}else if(X[p].usedTime > 12){
		X[p].price = 40000 + (12 * 76) + ((X[p].usedTime-12) * 86);
	}
	if(X[p].YesNo == 'Y' || X[p].YesNo == 'y'){
		X[p].price = X[p].price + 30000;
	}
	if(X[p].usedRoad < 120){
		X[p].discount = ((120 - X[p].usedRoad) * 150);
	}else if(X[p].usedRoad >= 120){
		X[p].discount = 0;
	}
	X[p].realPrice = X[p].price - X[p].discount;
}
//==================중형승용차=============
void car_M ()
{
	if(X[p].usedTime <= 10){
		X[p].price = 50000 + (X[p].usedTime * 88);
	}else if(X[p].usedTime > 10){
		X[p].price = 50000  + (10 * 88) + ((X[p].usedTime-10) * 100);
	}
	if(X[p].YesNo == 'Y' || X[p].YesNo == 'y'){
		X[p].price = X[p].price + 30000;
	}
	if(X[p].usedRoad < 185){
		X[p].discount = ((185 - X[p].usedRoad) * 150);
	}else if(X[p].usedRoad >= 185){
		X[p].discount = 0;
	}
	X[p].realPrice = X[p].price - X[p].discount;
}
//==============승합차======================
void car_H ()
{
	if(X[p].usedTime <= 9){
		X[p].price = 35000 + (X[p].usedTime *116);
	}else if(X[p].usedTime > 9){
		X[p].price = 35000  + (9 * 116) + ((X[p].usedTime-9) * 120);
	}
	if(X[p].YesNo == 'Y' || X[p].YesNo == 'y'){
		X[p].price = X[p].price + 30000;
	}
	if(X[p].usedRoad < 119){
		X[p].discount = ((119 - X[p].usedRoad) * 150);
	}else if(X[p].usedRoad >= 119){
		X[p].discount = 0;
	}
	X[p].realPrice = X[p].price - X[p].discount;
}
//===============미니버스========================
void car_B ()
{
	if(X[p].usedTime <= 15){
		X[p].price = 50000 + (X[p].usedTime * 95);
	}else if(X[p].usedTime > 15){
		X[p].price = 50000  + (15 * 95) + ((X[p].usedTime-15) * 111);
	}
	if(X[p].YesNo == 'Y' || X[p].YesNo == 'y'){
		X[p].price = X[p].price + 30000;
	}
	if(X[p].usedRoad < 135){
		X[p].discount = ((135 - X[p].usedRoad) * 150);
	}else if(X[p].usedRoad >= 135){
		X[p].discount = 0;
	}
	X[p].realPrice = X[p].price - X[p].discount;
}