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
		printf("숨긴수가 무엇일까요?? \n 범위는 : %d ~ %d \n 틀린횟수:%d \n:",start,end,cnt);
		scanf("%d",&num);
		fflush(stdin);
		cnt++;
		if(num >end || num < start){
			printf("잘못입력하셨습니다.\n");
			continue;
		}
		if(com > num){
			printf("up\n");
			start = num +1;
		}else if(com < num){
			printf("down\n");
			end = num -1;
		}else{
			printf("정답입니다.\n");
			break;
		}
	}
	printf("맞추는대까지 걸린횟수:%d",cnt);
	getch();
}