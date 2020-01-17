#include <stdio.h>
#include <string.h>

#define N 50

int num[N], kor[N], math[N], eng[N],sum[N];
float avg[N];
char name[N][10],grade[N],score[N];
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
	scanf("%d",&num[p]);
	for(i=0; i<p; i++){
		if(num[i] == num[p]){
			printf("�й��� ��Ĩ�ϴ�. �ٽ��Է��Ͽ� �ֽʽÿ�.\n");
			scanf("%d",&num[p]);
			i=-1;
		}
	}
	fflush(stdin);
	printf("�̸��� �Է��Ͻÿ�:");
	scanf("%s", &name[p]);
	fflush(stdin);
	printf("������� �Է��Ͻÿ�:");
	scanf("%d", &kor[p]);
	fflush(stdin);
	printf("������� �Է��Ͻÿ�:");
	scanf("%d", &eng[p]);
	fflush(stdin);
	printf("���м����� �Է��Ͻÿ�:");
	scanf("%d", &math[p]);
	fflush(stdin);
	for(i=0 ; i<=p ; i++){
		sum[i] = kor[i]+eng[i]+math[i];
		avg[i] = sum[i] / 3;
	}
}
//------------���� ���ϱ�--------------------------
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
//------------�ڷ� ����-----------------------------
void modify () {
	int numM, sujung;
	int i = 0;
	while (1){
		printf("�����ϰ��� �л��� �й��� �Է��Ͻÿ�:\n");
		scanf("%d", &numM);
		fflush(stdin);
		for (i = 0; i < p; i++){
			if (numM == num[i]){
				printf("�Է��Ͻ� �л��� ã�ҽ��ϴ�.\n");
				printf("%s���� ������ ����:%d ����:%d ����:%d \n",name[i],kor[i],eng[i],math[i]);
				break;
			}
		}
		if (i == p){
			printf("ã�¹�ȣ�� �����ϴ�.\n");
			continue;
		} else {
			printf("������� �Է��Ͻÿ�:");
			scanf("%d", &kor[i]);
			fflush(stdin);
			printf("������� �Է��Ͻÿ�:");
			scanf("%d", &eng[i]);
			fflush(stdin);
			printf("���м����� �Է��Ͻÿ�:");
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

//----------------�ڷ����----------------------
void del (){
	int i,j;
	int dele;
	while (1){
		printf("�����ϰ��� �л��� �й��� �Է��Ͻÿ�:");
		scanf("%d", &dele);
		fflush(stdin);
		for (i = 0; i < p; i++){
			if (dele == num[i]){
				printf("�Է��Ͻ� �л��� ã�ҽ��ϴ�.\n");
				printf("%s���� �����͸� �����մϴ�.\n",name[i]);
				break;
			}
		}
		if (i == p){
			printf("ã�¹�ȣ�� �����ϴ�.\n");
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
//-----------�ڷ� ���------------------------
void print (){
	int i;
	ranking ();
	printf("�й�\t�̸�\t����\t����\t����\t�հ�\t���\t��ŷ\n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; i<p; i++){
		printf("%3d\t%s\t%3d\t%3d\t%3d\t%3d\t%.2f\t%d\n",num[i],name[i],kor[i],eng[i],math[i],sum[i],avg[i],score[i]);
		printf("-----------------------------------------------------------\n");
	}
}
