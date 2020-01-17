#include <stdio.h>
#include <string.h>

#define N 50

int num[N], kor[N], math[N], eng[N],sum[N];
float avg[N];
char name[N][10],grade[N],score[N];
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
	scanf("%d",&num[p]);
	for(i=0; i<p; i++){
		if(num[i] == num[p]){
			printf("학번이 겹칩니다. 다시입력하여 주십시오.\n");
			scanf("%d",&num[p]);
			i=-1;
		}
	}
	fflush(stdin);
	printf("이름을 입력하시오:");
	scanf("%s", &name[p]);
	fflush(stdin);
	printf("국어성적을 입력하시오:");
	scanf("%d", &kor[p]);
	fflush(stdin);
	printf("영어성적을 입력하시오:");
	scanf("%d", &eng[p]);
	fflush(stdin);
	printf("수학성적을 입력하시오:");
	scanf("%d", &math[p]);
	fflush(stdin);
	for(i=0 ; i<=p ; i++){
		sum[i] = kor[i]+eng[i]+math[i];
		avg[i] = sum[i] / 3;
	}
}
//------------석차 구하기--------------------------
void ranking () {
	int i,j;
	for(i=0; i<p; i++){
		score[i] = 1;
		for(j=0; j<p; j++){
			if(sum[i] < sum[j]){
				score[i]++;
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
			if (numM == num[i]){
				printf("입력하신 학생을 찾았습니다.\n");
				printf("%s님의 성적은 국어:%d 영어:%d 수학:%d \n",name[i],kor[i],eng[i],math[i]);
				break;
			}
		}
		if (i == p){
			printf("찾는번호가 없습니다.\n");
			continue;
		} else {
			printf("국어성적을 입력하시오:");
			scanf("%d", &kor[i]);
			fflush(stdin);
			printf("영어성적을 입력하시오:");
			scanf("%d", &eng[i]);
			fflush(stdin);
			printf("수학성적을 입력하시오:");
			scanf("%d", &math[i]);
			fflush(stdin);
		}
		for(i=0 ; i<=p ; i++){
			sum[i] = kor[i]+eng[i]+math[i];
			avg[i] = sum[i] / 3;
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
			if (dele == num[i]){
				printf("입력하신 학생을 찾았습니다.\n");
				printf("%s님의 데이터를 삭제합니다.\n",name[i]);
				break;
			}
		}
		if (i == p){
			printf("찾는번호가 없습니다.\n");
			continue;
		} else {
			for (j = i; j < p; j++){
				num[j] = num[j+1];
				strcpy(name[j],name[j+1]);
				kor[j] = kor[j+1];
				eng[j] = eng[j+1];
				math[j] = math[j+1];
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
		printf("%3d\t%s\t%3d\t%3d\t%3d\t%3d\t%.2f\t%d\n",num[i],name[i],kor[i],eng[i],math[i],sum[i],avg[i],score[i]);
		printf("-----------------------------------------------------------\n");
	}
}
