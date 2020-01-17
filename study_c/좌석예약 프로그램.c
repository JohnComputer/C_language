#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

#define N 3   //hall 의 수
#define M 12  //시간값
#define T 10  //최대 입력 영화갯수
#define Col 10// 좌석 세로줄
#define Row 10// 좌석 가로줄
#define SEAT Col*Row //좌석 수
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
			printf("\t\t┏━━━━━━━━━━━━━━━┓\n");
			printf("\t\t\t1. 예약 시스템\n\t\t\t2. 관리자 모드 \n\t\t\t9. 시스템 종료\n");
			printf("\t\t┗━━━━━━━━━━━━━━━┛\n");
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
	printf("\n 예매 시스템 \n영화 제목 입력\n");
	scanf("%s",movi);

	system("cls");
	printf("\n ━━━");
	for(i = 0 ; i < N ; i++){
		printf("╋━━━[ %d 관 ]━━━━",i+1);
	}
	printf("\n       ┃   제목   ┃  좌석 수 ┃   제목   ┃  좌석 수 ┃   제목   ┃  좌석 수 ");
	printf("\n ━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━\n");
	for(i = 0 ; i < M ; i++){
		printf(" %2d:00 ",arr[c].time);
		for(k = 0 ; k < N ; k++){
					if(NULL != strstr(arr[c].title,movi)){  // strstr로 뒤에 문자를 자동으로 찾고, 그와 동일한 제목을 찾아내기 
			printf("┃[%8s]┃  [ %3d ] ",arr[c].title,SEAT-arr[c].seatcount);
		}else{
			printf("┃[        ]┃  [     ] ");
		}
		c++;
		}
		printf("\n ━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━\n");
	}
	printf("\n 구매하실 영화의 관과 시간을 입력하세요 ");
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
	printf("\t      ━━━━━━━━━━━━━━━━━━━━━\n\t\t1 . 영화 입력 \n\t\t2 . 상영 정보 출력\n\t\t0 . 종료\n\t      ━━━━━━━━━━━━━━━━━━━━━\n");
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
	//영화입력
	
	while(end != 0 && i < 10){
		system("cls");
		printf("\t      ━━━━━━━━━━━━━━━━━━━━━\n\t\tSystem에 추가할 영화 제목을 입력하세요\n\t      ━━━━━━━━━━━━━━━━━━━━━\n");
		scanf("%8s",movititle[i++]);
		fflush(stdin);
		printf("\t\tNew insert [ 1 ]\n \t\tEnd\t   [ 0 ]\n");
		scanf("%d",&end);
		count++;
	}//영화 각 시간대/관 별 랜덤 삽입

	system("cls");
	printf("\n ━━━");
	for(i = 0 ; i < N ; i++){
		printf("╋━━━[ %d 관 ]━━━━",i+1);
	}
	printf("\n       ┃   제목   ┃  좌석 수 ┃   제목   ┃  좌석 수 ┃   제목   ┃  좌석 수 ");
	printf("\n ━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━\n");
	for(i = 0 ; i < M ; i++){
		arr[c].time = i * 2 ;
		printf(" %2d:00 ",arr[c].time);
		for(k = 0 ; k < N ; k++){ 
			arr[c].hall = k + 1 ;
			ranT = rand()%count;
			strcpy(arr[c].title,movititle[ranT]);
			printf("┃[%8s]┃  [ %3d ] ",arr[c].title,SEAT-arr[c].seatcount);
			c++;
		}
		printf("\n ━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━\n");
	}
	printf(" *  Enter ━ Next Page  *");
	fflush(stdin);
	getchar();
}


void output(){
	int i,k,c=0;
	system("cls");
	printf("\n ━━━");
	for(i = 0 ; i < N ; i++){
		printf("╋━━━[ %d 관 ]━━━━",i+1);
	}
	printf("\n       ┃   제목   ┃  좌석 수 ┃   제목   ┃  좌석 수 ┃   제목   ┃  좌석 수 ");
	printf("\n ━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━\n");
	for(i = 0 ; i < M ; i++){
		printf(" %2d:00 ",arr[c].time);
		for(k = 0 ; k < N ; k++){
		printf("┃[%8s]┃  [ %3d ] ",arr[c].title,SEAT-arr[c].seatcount);
		c++;
		}
		printf("\n ━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━\n");
	}
	printf(" *  Enter ━ Next Page  *");
	fflush(stdin);
	getchar();
}

