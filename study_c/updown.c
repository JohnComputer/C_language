#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

main(){
	int com, num;
	int cnt = 0;
	int start=1, end=100;
	srand(time(NULL));
	com = rand()%100 + 1;

	while(1){
		printf("������� �����ϱ��?? \n ������ : %d ~ %d \n Ʋ��Ƚ��:%d \n:",start,end,cnt);
		scanf("%d",&num);
		fflush(stdin);
		cnt++;
		if(num >end || num < start){
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			continue;
		}
		if(com > num){
			printf("up\n");
			start = num +1;
		}else if(com < num){
			printf("down\n");
			end = num -1;
		}else{
			printf("�����Դϴ�.\n");
			break;
		}
	}
	printf("���ߴ´���� �ɸ�Ƚ��:%d",cnt);
	getch();
}