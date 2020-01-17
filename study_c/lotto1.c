#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

main(){
	int lotto[6]={0};
	int i,r,j;

	for(i=0; i<=5; i++){
		srand(time(NULL));	
		r = rand()%45 +1;
		lotto[i] = r;

		for(j=0; j<=i-1; j++){
			if(r == lotto[j]){
				i = i-1;
				break;
			}
		}
	}
	for(i=0; i<=5; i++){
		printf("로또 번호 %d번째:%d\n",(i+1),lotto[i]);
	}
	getch();
}