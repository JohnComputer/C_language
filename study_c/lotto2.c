#include <stdio.h>
#include <time.h.>
#include <stdlib.h>
#include <conio.h>

main(){
	int arr[45];
	int i,jamsi,p1,p2;
	for(i=0; i<=44; i++){
		arr[i] = i+1;
	}
	srand(time(NULL));
	for(i=0; i<100; i++){
		p1 = rand()%45;
		p2 = rand()%45;

		jamsi = arr[p1];
		arr[p1] = arr[p2];
		arr[p2] = jamsi;
	}
	for(i=0; i<=5; i++){
		printf("%d\t",arr[i]);
	}
	getch();
}
