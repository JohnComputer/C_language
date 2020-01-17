#include <stdio.h>
#include <conio.h>

#define  N 6
int arr[N][N] ={0};

void clear()
{// �迭 �ʱ�ȭ
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			arr[i][j] = 0;
		}
	}
}
//-------------------------------------------------------
void hangfirst() 
{ // ��켱
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
{// ���� ��� ���
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
{ //�ﰢ�� ��� ���
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
{//�𷡽ð� ���
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
{ //������ ��� ����Լ�
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
{ // ������ ��� ���
	int a = 0,b, cnt =0;
	int i,j,k,x;

	x = N - 1;
	b = x;

	for (k=0; k<(x/2)+1; k++){
		for(j=a; j<b; j++){ // ����������
			arr[a][j] = ++cnt;
		}
		for(i=a; i<b; i++){	//�Ʒ�������
			arr[i][b] = ++cnt;
		}
		for(j=b; j>a; j--){	//���ʰ���
			arr[b][j] = ++cnt;
		}
		for(i=b; i>a; i--){ //���ΰ���
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
{ // ü�������� ����
	int i,j,k;
	int a=1, b=0;
	int cnt = 1;

	arr[b][b] = cnt; //����� �޴� ó�������ϴ� ���� 1�� ���� ������ ���� ó�� ���ش�.

	for(k=0;k<N/2;k++){
		for(j=b;j<a;j++){ //������ �� ����
			arr[a][j] = ++cnt;
			print();
			getch();
		}
		for(i=a;i>=b;i--){ //���� �� ����
			arr[i][a] = ++cnt;
			print();
			getch();
		}
		a++;				
		if(cnt == (N*N)){	//¦���� ��� �ʿ�
			break;
			print();
			getch();
		}
		for(i=b; i<a; i++){	//�Ʒ��� �� ����
			arr[i][a] = ++cnt;
			print();
			getch();
		}
		for(j=a; j>=b; j--){ //�·� �� ����
			arr[a][j] = ++cnt;
			print();
			getch();
		}
		a++;
	}
}
//-------------------------------------------------------
void print() 
{ // ����Լ�
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
{ // �����Լ�
	int choice;

	while (1){

		printf(" 1.��켱 \n 2.���� \n 3.�ﰢ�� \n 4.�𷡽ð� \n 5.������ \n 6.������ \n 7.ü�������� ���� \n 0.����\n");
		scanf("%d",&choice);

		if(choice < 0 || choice > 7 ){
			printf("����� �� ���� �Է��Ͻÿ�!! 0 ~ 7 \n");
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

//  ������� �𷡽ð� �Ѵ� ¦���� �ǰ� �ϵ���
// ���� �� ��������   ������ å p.207������ 
// ü�������� ���� ����Ʈ���� ��� �Ϸ��ؼ� �ø�����
//file �̸��� reg_wark.c 7���� ���� �� 7�� ���� �����Ѱ� üũ�ؼ� ������!!!