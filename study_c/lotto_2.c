#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int lotto[45];
	int P1, P2,i,R;

	srand(time(NULL));

	for(i=0;i<45;i++){
		lotto[i]=i+1;
	}

	for(i=0;i<100;i++){
		P1=rand()%45;
		P2=rand()%45;

		R=lotto[P1];
		lotto[P1]=lotto[P2];
		lotto[P2]=R;
	}
	
	for(i=0;i<6;i++){
		printf("%d\t",lotto[i]);
	}
	getch();
}

	

	

