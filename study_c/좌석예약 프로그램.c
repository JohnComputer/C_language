#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

#define N 3   //hall �� ��
#define M 12  //�ð���
#define T 10  //�ִ� �Է� ��ȭ����
#define Col 10// �¼� ������
#define Row 10// �¼� ������
#define SEAT Col*Row //�¼� ��
struct movitype{
	int hall,
		seat[10][10],
		seatcount,
		time;
	char title[10];
};
void input();
void output();
void singlemode();
void reservation();
struct movitype arr[N*M];

main(){
	
	int in;
	while(1){
		system("cls");
		srand(time(NULL));
			printf("\t\t����������������������������������\n");
			printf("\t\t\t1. ���� �ý���\n\t\t\t2. ������ ��� \n\t\t\t9. �ý��� ����\n");
			printf("\t\t����������������������������������\n");
			scanf("%d",&in);
		switch(in){
			case 1:
				reservation();
				break;
			case 2:
				singlemode();
				break;
			case 9:
				return;
		}
	}
}

void reservation(){
	char movi[9];
	int i,k,hal,tim,combi,c=0;
	printf("\n ���� �ý��� \n��ȭ ���� �Է�\n");
	scanf("%s",movi);

	system("cls");
	printf("\n ������");
	for(i = 0 ; i < N ; i++){
		printf("��������[ %d �� ]��������",i+1);
	}
	printf("\n       ��   ����   ��  �¼� �� ��   ����   ��  �¼� �� ��   ����   ��  �¼� �� ");
	printf("\n ������������������������������������������������������������������������������\n");
	for(i = 0 ; i < M ; i++){
		printf(" %2d:00 ",arr[c].time);
		for(k = 0 ; k < N ; k++){
					if(NULL != strstr(arr[c].title,movi)){  // strstr�� �ڿ� ���ڸ� �ڵ����� ã��, �׿� ������ ������ ã�Ƴ��� 
			printf("��[%8s]��  [ %3d ] ",arr[c].title,SEAT-arr[c].seatcount);
		}else{
			printf("��[        ]��  [     ] ");
		}
		c++;
		}
		printf("\n ������������������������������������������������������������������������������\n");
	}
	printf("\n �����Ͻ� ��ȭ�� ���� �ð��� �Է��ϼ��� ");
	scanf("%d%d",&hal,&tim);
	combi = (hal - 1) + ( 3 * (tim / 2)); 
	for(i = 0 ; i < Col ; i++ ){
		for( k = 0 ; k < Row ; k++){
			if( k == (Row-1) / 3){
				printf(" ");
			}printf("%d",arr[combi].seat[i][k]);
			if( k == (Row-1) -  (Row-1) / 3){
				printf(" ");
			}
		}
		printf("\n");
	}

	printf("%d , %d , %d" ,hal,tim,combi);
	
	fflush(stdin);
	getchar();

}

void singlemode(){
	int in;
	while(1){
	system("cls");
	printf("\t      ������������������������������������������\n\t\t1 . ��ȭ �Է� \n\t\t2 . �� ���� ���\n\t\t0 . ����\n\t      ������������������������������������������\n");
	scanf("%d",&in);
		switch(in){
			case 1:
				input();
				break;
			case 2:
				output();
				break;
			case 0:
				return;
		}
	}
}

void input(){
	int i=0,k,c=0,o,ranT,count=0,end=1;
	char movititle[T][9];
	//��ȭ�Է�
	
	while(end != 0 && i < 10){
		system("cls");
		printf("\t      ������������������������������������������\n\t\tSystem�� �߰��� ��ȭ ������ �Է��ϼ���\n\t      ������������������������������������������\n");
		scanf("%8s",movititle[i++]);
		fflush(stdin);
		printf("\t\tNew insert [ 1 ]\n \t\tEnd\t   [ 0 ]\n");
		scanf("%d",&end);
		count++;
	}//��ȭ �� �ð���/�� �� ���� ����

	system("cls");
	printf("\n ������");
	for(i = 0 ; i < N ; i++){
		printf("��������[ %d �� ]��������",i+1);
	}
	printf("\n       ��   ����   ��  �¼� �� ��   ����   ��  �¼� �� ��   ����   ��  �¼� �� ");
	printf("\n ������������������������������������������������������������������������������\n");
	for(i = 0 ; i < M ; i++){
		arr[c].time = i * 2 ;
		printf(" %2d:00 ",arr[c].time);
		for(k = 0 ; k < N ; k++){ 
			arr[c].hall = k + 1 ;
			ranT = rand()%count;
			strcpy(arr[c].title,movititle[ranT]);
			printf("��[%8s]��  [ %3d ] ",arr[c].title,SEAT-arr[c].seatcount);
			c++;
		}
		printf("\n ������������������������������������������������������������������������������\n");
	}
	printf(" *  Enter �� Next Page  *");
	fflush(stdin);
	getchar();
}


void output(){
	int i,k,c=0;
	system("cls");
	printf("\n ������");
	for(i = 0 ; i < N ; i++){
		printf("��������[ %d �� ]��������",i+1);
	}
	printf("\n       ��   ����   ��  �¼� �� ��   ����   ��  �¼� �� ��   ����   ��  �¼� �� ");
	printf("\n ������������������������������������������������������������������������������\n");
	for(i = 0 ; i < M ; i++){
		printf(" %2d:00 ",arr[c].time);
		for(k = 0 ; k < N ; k++){
		printf("��[%8s]��  [ %3d ] ",arr[c].title,SEAT-arr[c].seatcount);
		c++;
		}
		printf("\n ������������������������������������������������������������������������������\n");
	}
	printf(" *  Enter �� Next Page  *");
	fflush(stdin);
	getchar();
}

