#include <stdio.h>
#include <conio.h>

#define  N 6
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

	for(i=0; i<N; i++){
		if(i<N/2){
			for(j=i; j<N-i; j++){
				arr[i][j] = ++cnt;
			}
		}else{
			for(j=(N-1)-i; j<i+1; j++){
				arr[i][j] = ++cnt;
			}
		}
	}
}
//-------------------------------------------------------
void marumo()
{ //마름모 모양 출력함수
	int a , b = (N/2) , cnt =1;
	int i,j;
	if(N%2 == 1){
		a = b;
	}else{
		a = b-1;
	}
		for(i=0; i<=N; i++){
			for(j=a; j<=b; j++){
				arr[i][j] = cnt;
				cnt= cnt+2;;
			}
			if(i<N/2){
				if(a==0 && b == N-1){
				continue;
			}
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
		for(j=a; j<b; j++){ // 오른쪽증가
			arr[a][j] = ++cnt;
		}
		for(i=a; i<b; i++){	//아래로증가
			arr[i][b] = ++cnt;
		}
		for(j=b; j>a; j--){	//왼쪽감소
			arr[b][j] = ++cnt;
		}
		for(i=b; i>a; i--){ //위로감소
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
void ants() 
{ // 체스판위의 개미
	int i,j,k;
	int a=1, b=0;
	int cnt = 1;

	arr[b][b] = cnt; //어떤값을 받던 처음시작하는 곳은 1이 들어가기 때문에 따로 처리 해준다.

	for(k=0;k<N/2;k++){
		for(j=b;j<a;j++){ //오른쪽 열 증가
			arr[a][j] = ++cnt;
			print();
			getch();
		}
		for(i=a;i>=b;i--){ //위쪽 행 감소
			arr[i][a] = ++cnt;
			print();
			getch();
		}
		a++;				
		if(cnt == (N*N)){	//짝수의 경우 필요
			break;
			print();
			getch();
		}
		for(i=b; i<a; i++){	//아래로 행 증가
			arr[i][a] = ++cnt;
			print();
			getch();
		}
		for(j=a; j>=b; j--){ //좌로 열 감소
			arr[a][j] = ++cnt;
			print();
			getch();
		}
		a++;
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

		printf(" 1.행우선 \n 2.ㄹ자 \n 3.삼각형 \n 4.모래시계 \n 5.마름모 \n 6.달팽이 \n 7.체스판위의 개미 \n 0.종료\n");
		scanf("%d",&choice);

		if(choice < 0 || choice > 7 ){
			printf("제대로 된 값을 입력하시오!! 0 ~ 7 \n");
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
			case 7 :ants();
					break;
		}
	print ();
	clear();
	}
}

//  마름모와 모래시계 둘다 짝수도 되게 하도록
// 같은 행 나오도록   마름모 책 p.207쪽참고 
// 체스판위에 개미 프린트까지 모두 완료해서 올리도록
//file 이름은 reg_wark.c 7번에 넣은 후 7번 오류 검출한것 체크해서 내도록!!!