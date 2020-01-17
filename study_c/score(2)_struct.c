#include <stdio.h>
#include <string.h>

struct rec
{
	int num,kor,math,eng,score,sum;
	float avg;
	char name[10];
}X [30];

int p = 0;

//----------함수 호출--------------------
void input();
void modify();
void del();
void print();
//----------메인 함수--------------------
main(){
	int sel;

	while(1){
		printf("성적 처리 작업 선택 \n 1.자료입력 \n 2.자료수정 \n 3.자료삭제 \n 4.자료출력 \n 5.종료 \n");
		scanf("%d", &sel);
		fflush(stdin);
		switch (sel){
			case (1) :
				input();
				p++;
				continue;
			case (2) :
				modify();
				continue;
			case (3) :
				del();
				continue;
			case (4) :
				print();
				continue;
			case (5) :
				break;
			default:printf("제대로된 번호를 입력하여 주십시오\n");
				continue;
		}
	}
}
//-------------자료 입력------------------
void input(){
	int i = 0;
	int find = 1;
	printf("학번을 입력하시오:");
	scanf("%d",&X[p].num);
	for(i=0; i<p; i++){
		if(X[i].num == X[p].num){
			printf("학번이 겹칩니다. 다시입력하여 주십시오.\n");
			scanf("%d",&X[p].num);
			i=-1;
		}
	}
	fflush(stdin);
	printf("이름을 입력하시오:");
	scanf("%s", &X[p].name);
	fflush(stdin);
	printf("국어성적을 입력하시오:");
	scanf("%d", &X[p].kor);
	fflush(stdin);
	printf("영어성적을 입력하시오:");
	scanf("%d", &X[p].eng);
	fflush(stdin);
	printf("수학성적을 입력하시오:");
	scanf("%d", &X[p].math);
	fflush(stdin);
	for(i=0 ; i<=p ; i++){
		X[i].sum = X[i].kor+X[i].eng+X[i].math;
		X[i].avg = X[i].sum / 3;
	}
}
//------------석차 구하기--------------------------
void ranking () {
	int i,j;
	for(i=0; i<p; i++){
		X[i].score = 1;
		for(j=0; j<p; j++){
			if(X[i].sum < X[j].sum){
				X[i].score++;
			}
		}
	}
}
//------------자료 수정-----------------------------
void modify () {
	int numM, sujung;
	int i = 0;
	while (1){
		printf("수정하고픈 학생의 학번을 입력하시오:\n");
		scanf("%d", &numM);
		fflush(stdin);
		for (i = 0; i < p; i++){
			if (numM == X[i].num){
				printf("입력하신 학생을 찾았습니다.\n");
				printf("%s님의 성적은 국어:%d 영어:%d 수학:%d \n",X[i].name,X[i].kor,X[i].eng,X[i].math);
				break;
			}
		}
		if (i == p){
			printf("찾는번호가 없습니다.\n");
			continue;
		} else {
			printf("국어성적을 입력하시오:");
			scanf("%d", &X[i].kor);
			fflush(stdin);
			printf("영어성적을 입력하시오:");
			scanf("%d", &X[i].eng);
			fflush(stdin);
			printf("수학성적을 입력하시오:");
			scanf("%d", &X[i].math);
			fflush(stdin);
		}
		for(i=0 ; i<=p ; i++){
			X[i].sum = X[i].kor+X[i].eng+X[i].math;
			X[i].avg = X[i].sum / 3;
		}
		return;
	}
}

//----------------자료삭제----------------------
void del (){
	int i,j;
	int dele;
	while (1){
		printf("삭제하고픈 학생의 학번을 입력하시오:");
		scanf("%d", &dele);
		fflush(stdin);
		for (i = 0; i < p; i++){
			if (dele == X[i].num){
				printf("입력하신 학생을 찾았습니다.\n");
				printf("%s님의 데이터를 삭제합니다.\n",X[i].name);
				break;
			}
		}
		if (i == p){
			printf("찾는번호가 없습니다.\n");
			continue;
		} else {
			for (j = i; j < p; j++){
				X[j] = X[j+1];
			}
			p = p-1;
			return;
		}
	}
}
//-----------자료 출력------------------------
void print (){
	int i;
	ranking ();
	printf("학번\t이름\t국어\t영어\t수학\t합계\t평균\t랭킹\n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; i<p; i++){
		printf("%3d\t%s\t%3d\t%3d\t%3d\t%3d\t%.2f\t%d\n",X[i].num,X[i].name,X[i].kor,X[i].eng,X[i].math,X[i].sum,X[i].avg,X[i].score);
		printf("-----------------------------------------------------------\n");
	}
}