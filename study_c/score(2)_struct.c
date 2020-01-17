#include <stdio.h>
#include <string.h>

struct rec
{
	int num,kor,math,eng,score,sum;
	float avg;
	char name[10];
}X [30];

int p = 0;

//----------�Լ� ȣ��--------------------
void input();
void modify();
void del();
void print();
//----------���� �Լ�--------------------
main(){
	int sel;

	while(1){
		printf("���� ó�� �۾� ���� \n 1.�ڷ��Է� \n 2.�ڷ���� \n 3.�ڷ���� \n 4.�ڷ���� \n 5.���� \n");
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
			default:printf("����ε� ��ȣ�� �Է��Ͽ� �ֽʽÿ�\n");
				continue;
		}
	}
}
//-------------�ڷ� �Է�------------------
void input(){
	int i = 0;
	int find = 1;
	printf("�й��� �Է��Ͻÿ�:");
	scanf("%d",&X[p].num);
	for(i=0; i<p; i++){
		if(X[i].num == X[p].num){
			printf("�й��� ��Ĩ�ϴ�. �ٽ��Է��Ͽ� �ֽʽÿ�.\n");
			scanf("%d",&X[p].num);
			i=-1;
		}
	}
	fflush(stdin);
	printf("�̸��� �Է��Ͻÿ�:");
	scanf("%s", &X[p].name);
	fflush(stdin);
	printf("������� �Է��Ͻÿ�:");
	scanf("%d", &X[p].kor);
	fflush(stdin);
	printf("������� �Է��Ͻÿ�:");
	scanf("%d", &X[p].eng);
	fflush(stdin);
	printf("���м����� �Է��Ͻÿ�:");
	scanf("%d", &X[p].math);
	fflush(stdin);
	for(i=0 ; i<=p ; i++){
		X[i].sum = X[i].kor+X[i].eng+X[i].math;
		X[i].avg = X[i].sum / 3;
	}
}
//------------���� ���ϱ�--------------------------
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
//------------�ڷ� ����-----------------------------
void modify () {
	int numM, sujung;
	int i = 0;
	while (1){
		printf("�����ϰ��� �л��� �й��� �Է��Ͻÿ�:\n");
		scanf("%d", &numM);
		fflush(stdin);
		for (i = 0; i < p; i++){
			if (numM == X[i].num){
				printf("�Է��Ͻ� �л��� ã�ҽ��ϴ�.\n");
				printf("%s���� ������ ����:%d ����:%d ����:%d \n",X[i].name,X[i].kor,X[i].eng,X[i].math);
				break;
			}
		}
		if (i == p){
			printf("ã�¹�ȣ�� �����ϴ�.\n");
			continue;
		} else {
			printf("������� �Է��Ͻÿ�:");
			scanf("%d", &X[i].kor);
			fflush(stdin);
			printf("������� �Է��Ͻÿ�:");
			scanf("%d", &X[i].eng);
			fflush(stdin);
			printf("���м����� �Է��Ͻÿ�:");
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

//----------------�ڷ����----------------------
void del (){
	int i,j;
	int dele;
	while (1){
		printf("�����ϰ��� �л��� �й��� �Է��Ͻÿ�:");
		scanf("%d", &dele);
		fflush(stdin);
		for (i = 0; i < p; i++){
			if (dele == X[i].num){
				printf("�Է��Ͻ� �л��� ã�ҽ��ϴ�.\n");
				printf("%s���� �����͸� �����մϴ�.\n",X[i].name);
				break;
			}
		}
		if (i == p){
			printf("ã�¹�ȣ�� �����ϴ�.\n");
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
//-----------�ڷ� ���------------------------
void print (){
	int i;
	ranking ();
	printf("�й�\t�̸�\t����\t����\t����\t�հ�\t���\t��ŷ\n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; i<p; i++){
		printf("%3d\t%s\t%3d\t%3d\t%3d\t%3d\t%.2f\t%d\n",X[i].num,X[i].name,X[i].kor,X[i].eng,X[i].math,X[i].sum,X[i].avg,X[i].score);
		printf("-----------------------------------------------------------\n");
	}
}