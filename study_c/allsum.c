#include <stdio.h>
#include <conio.h>

#define  N 5
int arr[N][N] ={0};

void clear()
{// 배열 초기화
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			arr[i][j] = 0;
		}
	}
}
//-------------------------------------------------------
void hangfirst() 
{ // 행우선
	int i,j,cnt = 0;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cnt++;
			arr[j][i] = cnt;
		}
	}
}
//-------------------------------------------------------
void riel() 
{// ㄹ자 모양 출력
	int i,j,cnt = 0;

		for(i=0;i<N;i++){
			if(i%2 == 0){
				for(j=0;j<N;j++){
					cnt++;
					arr[i][j] = cnt;	
				}
			}else{
				for(j=(N-1);j>=0;j--){
					cnt++;
					arr[i][j] = cnt;
				}
			}
		}
}
//-------------------------------------------------------
void triangle()
{ //삼각형 모양 출력
	int i,j,cnt = 0;
	int k;

	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			cnt++;
			arr[i][j] = cnt;
		}
	}
}
//-------------------------------------------------------
void sandtime() 
{//모래시계 출력
	int i,j,cnt = 0;
	int a=0,b=N;

	for(i=0;i<N;i++){
		for(j=a;j<b;j++){
			cnt++;
			arr[i][j] = cnt;
		}
		if(i<(N-1)/2){
			a++;
			b--;
		}else{
			a--;
			b++;
		}
	}
}
//-------------------------------------------------------
void marumo()
{ //마름모 모양 출력함수
	int a = (N-1)/2,b = N/2, cnt =1;
	int i,j;
	for(i=0; i<N; i++){
		for(j=a; j<=b; j++){
			arr[i][j] = cnt;
			cnt= cnt+2;;
		}
		if(i<N/2){
			a--;
			b++;
		}else{
			a++;
			b--;
		}
	}
}
//-------------------------------------------------------
void snail()
{ // 달팽이 모양 출력
	int a = 0,b, cnt =0;
	int i,j,k,x;

	x = N - 1;
	b = x;

	for (k=0; k<(x/2)+1; k++){
		for(j=a; j<b; j++){
			arr[a][j] = ++cnt;
		}
		for(i=a; i<b; i++){
			arr[i][b] = ++cnt;
		}
		for(j=b; j>a; j--){
			arr[b][j] = ++cnt;
		}
		for(i=b; i>a; i--){
			arr[i][a] = ++cnt;
		}
			a++;
			b--;
		if(a == b){
			arr[a][b] = ++cnt;
		}
	}
}
//-------------------------------------------------------
void print() 
{ // 출력함수
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(arr[i][j] != 0 ){
				printf("%d\t",arr[i][j]);
			} else {
				printf("\t");
			}
		}
	printf("\n");
	}
}
//-------------------------------------------------------
main () 
{ // 메인함수
	int choice;

	while (1){

		printf(" 1.행우선 \n 2.ㄹ자 \n 3.삼각형 \n 4.모래시계 \n 5.마름모 \n 6.달팽이 \n 0.종료\n");
		scanf("%d",&choice);

		if(choice < 0 || choice > 6 ){
			printf("제대로 된 값을 입력하시오!! 0 ~ 6 \n");
			continue;
		}
		switch(choice){
			case 0 :return ;
			case 1 :hangfirst();
					break;
			case 2 :riel();
					break;
			case 3 :triangle();
					break;
			case 4 :sandtime();
					break;
			case 5 :marumo();
					break;
			case 6 :snail();
					break;
		}
	print ();
	clear();
	}
}