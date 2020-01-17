#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

//=============�Լ� ȣ��===========
void input();
void print();
void car_S();
void car_M();
void car_H();
void car_B();
//===========����ü============
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

		printf("\t��������������������������\n");
		printf("\t��1.�ڷ��Է�\t\t��\n");
		printf("\t��2.�ڷ����\t\t��\n");
		printf("\t��3.����    \t\t��\n");
		printf("\t��������������������������\n");
		printf("\t���Ͻô� �۾�����:");
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
				printf("1~3�������� �۾������ð����մϴ�.\n");
		}
	}
}
//==============�ڷ� �Է�==============
void input() 
{
	int i;
	while(1){
		printf("����ȣ:");
		scanf("%d",&X[p].num);
		fflush(stdin);

		if(X[p].num < 1 || X[p].num > 9){
			printf("���� 1~9���̷� �Է����ּ���.^^\n");
			continue;
		}
		for(i=0; i<p; i++){
			if(X[i].num == X[p].num){
				printf("�ߺ��Ǵ� ����ȣ�� �ֽ��ϴ�.\n �ٽ��Է��Ͽ� �ֽʽÿ�.\n");
				break;
			}
		}if(i == p){
			break;
		}
	}
	while(1){
		printf("�����ڵ�:");
		scanf("%c",&X[p].carCode);
		fflush(stdin);

		if(X[p].carCode == 'S' || X[p].carCode == 's'){
			strcpy(X[p].carName,"�����¿���");
			break;
		}else if(X[p].carCode == 'M' || X[p].carCode == 'm'){
			strcpy(X[p].carName,"�����¿���");
			break;
		}else if(X[p].carCode == 'H' || X[p].carCode == 'h'){
			strcpy(X[p].carName,"������");
			break;
		}else if(X[p].carCode == 'B' || X[p].carCode == 'b'){
			strcpy(X[p].carName,"�̴Ϲ���");
			break;
		}else{
			printf("�ڵ����� �ڵ尡 �߸��Ǿ����ϴ�. ���Է� ��Ź�帳�ϴ�.\n");
		}
	}
	while(1){
		printf("������� �̿뿩��:");
		scanf("%c",&X[p].YesNo);
		fflush(stdin);

		if(X[p].YesNo == 'Y' || X[p].YesNo == 'y' || X[p].YesNo == 'N' || X[p].YesNo == 'n'){
			break;
		}else{
			printf("�̿뿩�θ� ����� �Է��Ͽ� �ֽʽÿ�.\n");
		}
	}
	while(1){
		printf("�̿�ð�:");
		scanf("%d",&X[p].usedTime);
		fflush(stdin);

		if(X[p].usedTime < 0 || X[p].usedTime > 999){
			printf("0 ~ 999������ ���ڸ� �Է��Ͽ��ּ���.\n");
			continue;
		}
		break;
	}
	while(1){
		printf("�̿�Ÿ�:");
		scanf("%d",&X[p].usedRoad);
		fflush(stdin);

		if(X[p].usedRoad < 0 || X[p].usedRoad > 999){
			printf("0 ~ 999������ ���ڸ� �Է��Ͽ��ּ���.\n");
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
//===============�ڷ� ���================
void print()
{
	int i;
	printf("\n����ȣ   ������       �̿���  ���ξ�   û����   ���  \n");
	printf("��������������������������������������������������������");
	for(i=0; i<p; i++){
		printf("\n%2d\t  %5s\t%7d\t%7d\t  %7d   ",X[i].num,X[i].carName,X[i].price,X[i].discount,X[i].realPrice);
		if(X[i].realPrice >= 100000){
			printf("A");
		}
	}
	getch();
	system("cls");
}
//==================�����¿���============
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
//==================�����¿���=============
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
//==============������======================
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
//===============�̴Ϲ���========================
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