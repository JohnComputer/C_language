#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#define N 50
#define M 50

char map1[N][M];
char map2[N][M];
int mine;
//---------------함수호출-----------------------
void output();
void reset();
void install();
void playGame ();
//----------------main -----------------------
main()
{
	int I,J,sel,reset;
	while(1){
		printf("1.맵초기화\n 2.게임시작 \n 0.게임종료 \n선택 : ");
		scanf("%d",&sel);
		fflush(stdin);
		switch(sel){
		case 1:
			memset(map1,'0',N*M);
			memset(map2,'.',N*M);
			printf("N*M의 크기를 입력하시오 : ");
			scanf("%d %d",&I,&J);
			fflush(stdin);
			while(1){
				printf("지뢰의 갯수를 입력하시오 : ");
				scanf("%d",&mine);
				fflush(stdin);
				if(mine>I*J){
					printf("지뢰의 갯수가 너무큽니다.\n\n");
				}else{
					break;
				}
			}
			install(I,J);
			printf("\n초기화를 하였습니다.");
			break;
		case 2:
			if(mine!=0){
				playGame(I,J);
			}else{
				printf("\n지뢰가 안깔려있습니다 안전지역인것 같습니다.\n맵을 초기화해주십시오\n\n");
			}
			break;
		default:
			if(sel!=0){
				printf("잘못된입력입니다.");
			}
		}
		if(sel==0){
			break;
		}
	}
	getch();
}
//----------------------------------------출력하기 ----------------------------------------------
void output(int I_O,int J_O)
{
	int i,k;
	system("cls");
	printf("\n");
	for(i=0;i<I_O;i++){
		for(k=0;k<J_O;k++){
			printf("%c  ",map2[i][k]);
		}
		printf("\n");
	}
}
//--------------------------------초기화 ----------------------------------------------
void reset(int rowR,int colR)
{
	int p;
	int offset_x[8]={-1,-1,0,1,1,1,0,-1};
	int offset_y[8]={0,1,1,1,0,-1,-1,-1};
	for(p=0;p<8;p++){
		if(map1[rowR+offset_x[p]][colR+offset_y[p]]!='*'){
			map1[rowR+offset_x[p]][colR+offset_y[p] ]+=1;
		}
	}
}
//------------------------------지뢰-------------------------------------------
void install(int s1,int s2)
{
	int row,col,cnt=0;

	srand(time(NULL));

	while(cnt<mine){
		row=rand()%s1;
		col=rand()%s2;
		if(map1[row][col]!='*'){
			map1[row][col]='*';
			cnt++;
			reset(row,col);
		}		
	}
}
//----------------------------------------게임시작 ----------------------------------------------
void playGame(int I_P,int J_P){
	int r,c,cnt=0;
	while(1){
		output(I_P,J_P);
		printf("좌표를 입력하세요 : ");
		scanf("%d %d",&r,&c);
		fflush(stdin);
		if(r>I_P || r<0 || c>J_P || c<0){
			printf("좌표값이 이상합니다.");
		}else{
			map2[r][c]=map1[r][c];
			output(I_P,J_P);
			cnt++;
			if(map1[r][c]=='*'){
				printf("You Lose");
				mine=0;
				break;
			}
			if(cnt==I_P*J_P-mine){
				printf("You Win");
				mine=0;
				break;
			}
		}
	}
}