// 시간값 출력중 민트색으로 나오는 부분은 '다음날' 이란 개념으로 출력하는 부분입니다.
// 민트색으로 출력되는부분이 예매가 아닌 시간 체크부분에서도 출력되는것은 오류가 아니라 일부러 그렇게 코딩을 한것입니다.


#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

time_t ltime;
struct tm *today;				//현재 시간 구성

#define N 5   //hall 의 수
#define M 12  //시간값
#define T 10  //최대 입력 영화갯수
#define Col 10// 최대좌석 세로(행)줄
#define Row 10// 최대좌석 가로(열)줄
int count = 0 ;
struct movitype{
	int hall,			// 0 일때는 값이 존재하지 않는것 , 그외 각각의 수 ( 해당하는 홀 ) 가 들어감
		seat[5][Col][Row],
		seatsub[5],		//각 회차에 따른 자리 카운터 ( 기본 값에서 빼서 남은 좌석수를 출력 )
		starttime,		//시작 시간
		runingtime,		// 러닝타임	
		recycle[5];		// 회차 
	char title[10];		// 영화 타이틀 
};
void input();
void recycleset();
void output();
void singlemode();			//관리자 모드
void reservation();			//예약
void movichange();			//영화관에대한 값 수정
void moviremove();			//영화관 삭제와 이동 
void nowtime();				//현재 시간
void sampleprint();			//현재 상영 정보를 간략히 표시함 (회차정보 없음)
void seatchange();			//좌석 수정

void timetable(int in,int switch_);
void seattable(int i, int numb);
struct movitype arr[N];
void seting(){		// 타이틀 초기화 
	int i;
	char movititle[13]="비어있음";
	for(i=0;i<N;i++){
		strcpy(arr[i].title,movititle);
	}
}
//------------------------------------------------------------------------------------
main(){
	int in;
	seting();
	while(1){
		system("cls");
		srand((unsigned int)time(NULL));
			printf("\t\t┏━━━━━━━━━━━━━━━┓\n");
			printf("\t\t\t1. 관리자 모드\n\t\t\t2. 영화 예매\n\t\t\t3. 잔여좌석 조회\n\t\t\t4. 좌석 수정\n\t\t\t5. 종료\n");
			printf("\t\t┗━━━━━━━━━━━━━━━┛\n");
			scanf_s("%d",&in);
		switch(in){
			case 1:
				singlemode();
				break;
			case 2:
				reservation();
				break;
			case 3:
				output();
				break;
			case 4:
				seatchange();
				break;
			case 5:
				return;
		}
	}
}
//------------------------------------------------------------------------------------예약
void reservation(){
	int i=0,c=0,end=1,breaktime=0 , m , numb, input , hallnum; 
	int input_seatnumb_r,input_seatnumb_c,input_seatcount;
	printf("\n 예매 시스템\n 상영중인 영화 ... \n");
	for( i = 0 ; i < N ; i++){
		if(arr[i].hall>0){
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
		}
		printf("[ %d 관 ] - %s \n",i+1,arr[i].title);
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	}
	printf("\n예매할 관 입력\n");
	scanf_s("%d",&input);
	system("cls");
	if( input <= 0 || input > N ){			// 관 입력의 유효범위 
		printf(" 존재하지 않는 관입니다.");
		fflush(stdin);
		getchar();
		return;
	}
	if (arr[input-1].hall == 0){
		printf(" 입력된 값에서 상영중인 영화를 찾을 수 없습니다..\n");
		fflush(stdin);
		getchar();
		return;
	}
	for(m=0;m<N;m++){
		if(arr[m].hall!=0){
			break;
		}
	}
	if( m == N ){
		printf("\n 현재 상영중인 영화가 없습니다.");
		getchar();
		return;
	}
	nowtime();		
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("╋\t▶   [  %d관  ]\t[  %8s 상영중 ]\t\t┃\n",arr[input-1].hall,arr[input-1].title);
	printf("┃[회차] [시작 시간]\t[종료 시간]\t[잔여 좌석수]\t┃\n");
	timetable(input-1,1);  // 타임테이블 불러오기
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n 구매하실 영화의 회차를 입력하세요 \n 회차선택 : ");
	scanf_s("%d",&numb);
	fflush(stdin);
	if((((today->tm_hour * 60)+today->tm_min) > arr[input-1].recycle[numb-1]) || numb>5){//시간값 오버되면 값을 넣을 수 없음.
		printf("현재 상영될 수 없는 회차입니다");
		getchar();
		return;
	}
	seattable(input-1,numb);//테이블 불러오기

	fflush(stdin);
	printf("\n몇개의 좌석을 입력하실겁니까?");
	scanf_s("%d",&input_seatcount);
		for( m = 0 ; m < input_seatcount ; m++){
			printf(" 예매할 좌석의 좌표를 입력하시오(행열) \n" );
			scanf_s("%d %d",&input_seatnumb_r,&input_seatnumb_c);
			if(!arr[input-1].seat[numb-1][input_seatnumb_r][input_seatnumb_c]){
				arr[input-1].seat[numb-1][input_seatnumb_r][input_seatnumb_c] = 1;
				arr[input-1].seatsub[numb-1]++;
			}else{
				printf(" 현재 자리는 좌석이 예약되어있습니다 . \n");
				m--;
			}
		}
	system("cls");
	seattable(input-1,numb);
	printf("\n\n 예매가 완료 되었습니다. \n감사합니다. \n");
	fflush(stdin);
	getchar();//다시한번 확인용으로 테이블 불러오기
}

//------------------------------------------------------------------------------------
void singlemode(){
	int in;
	while(1){
	system("cls");
	printf("\t      ━━━━━━━━━━━━━━━━━━━━━\n\t\t1 . 상영프로 등록 \n\t\t2 . 상영프로 수정\n\t\t3 . 상영프로 삭제\n\t\t4 . 상영프로 현황\n\t\t5 . 돌아가기\n\t      ━━━━━━━━━━━━━━━━━━━━━\n");
	scanf_s("%d",&in);
		switch(in){\
			case 1:
				input();
				recycleset();
				break;
			case 2:
				movichange();
				break;
			case 3:
				moviremove();
				break;
			case 4:
				output();
				break;
			case 5:
				return;
		}
	}
}
//-----------------------------------------------------------------------------------영화 추가 
void input(){
	int i=0,c=0,end=1,sumtime,hall,k;
	char movititle[9];
	while(end != 0 && count < N){	// 영화 입력
		
		system("cls");
		printf("\t      ━━━━━━━━━━━━━━━━━━━━━\n\t\tSystem에 추가할 영화 정보를 입력하세요\n\t      ━━━━━━━━━━━━━━━━━━━━━\n");
		printf("상 영 관 :");
		scanf_s("%d",&hall);
		fflush(stdin);
		if( hall <= 0 || hall > N ){			// 관 입력의 유효범위 
			printf(" 존재하지 않는 관입니다.");
			getchar();
			return;
		}
		if(arr[hall-1].hall == hall){
			printf(" * 이미 입력된 상영관입니다.\n 이전 화면으로 돌아갑니다 . \n");
			getchar();
			return;
		}
		arr[hall-1].hall = hall;

		printf("상영프로 :");
		scanf("%8s",&movititle);
		fflush(stdin);
		strcpy(arr[hall-1].title,movititle);
		while(1){
			printf("시작시간 :");
			scanf_s("%d %d",&sumtime,&arr[hall-1].starttime);
			fflush(stdin);
			if(( sumtime < 0  || sumtime > 24 ) || (arr[hall-1].starttime < 0 || arr[hall-1].starttime > 60 )){
				printf(" 시간의 입력이 잘못되었습니다. 다시입력해주세요 \n");
			}else{
				break;
			}
		}

		arr[hall-1].starttime = arr[hall-1].starttime + sumtime * 60;	//분으로 환산하여 입력

		printf("상영시간 :");
		scanf_s("%d",&arr[hall-1].runingtime);

		printf("\t\tNew insert [ 1 ]\n \t\tEnd\t   [ 0 ]\n");
		scanf_s("%d",&end);
	}//영화 입력 최대 10번 돌거나, 0을 입력하여 종료함.
	printf("\n *  Enter ━ Next Page  *");
	fflush(stdin);
	getchar();
}

//-------------------------------------------------------회차 시간 값 리셋 ------
void recycleset(){
	int breaktime = 0;
	int i , k ;
		for(i = 0 ; i < N ; i++){
		if(arr[i].hall > 0){
			for(k = 0 ; k < 5 ; k++){
				arr[i].recycle[k] = arr[i].starttime+breaktime;					// 시작시간 + 브레이크 타임 
				breaktime = arr[i].runingtime + breaktime + 30;					// 브레이크 타임에는 이전에 상영했던 시간값과 쉬는시간(30분)을 모두 갖는다.
			}
			breaktime=0;														// 다른관으로 넘어갈때는 브레이크 타임 초기화
		}
	}
}
//----------------------------------------------------------- 현황 출력 -------------------------

void output(){		
	int i=0,c=0,end=1,breaktime=0,input,numb=0,hall;
	while(1){
	system("cls");
	nowtime();
	for(i = 0 ; i < N ; i++){
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		if(arr[i].hall==0){
			printf("╋\t▶   [  %d관  ]\t[  비어있음 ]\t\t\t┃\n",i+1,arr[i].title);
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			continue;
		}
		printf("╋\t▶   [  %d관  ]\t[  %8s 상영중 ]\t\t┃\n",arr[i].hall,arr[i].title);
		printf("┃[회차] [시작 시간]\t[종료 시간]\t[잔여 좌석수]\t┃\n");
		timetable(i,0);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	}

	
		printf("  ---- 좌석표 확인 ---- \n [ 0 ] . End \n [ 1 ] . Check \n");
		scanf_s("%d",&input);
		fflush(stdin);
		switch(input){
			case 0:
				return;	
			case 1:				//이렇게 확인할때에는 시간값이 오버되어도 확인될 수 있게끔 함.
				printf("관과 회차를 입력하시오\n");
				scanf_s("%d %d",&input,&numb);
				if( input <= 0 || input > N ){			// 관 입력의 유효범위 
					printf(" 존재하지 않는 관입니다.");
					fflush(stdin);
					getchar();
					return;
				}
				if (arr[input-1].hall == 0){
					printf(" 입력된 값에서 상영중인 영화를 찾을 수 없습니다.");
					fflush(stdin);
					getchar();
					return;
				}
				seattable(input-1,numb);
				printf("\n *  Enter ━ Next Page  *");
				fflush(stdin);
				getchar();
				break;
		}
	}
}
//------------------------------------------------------------------------------------
void moviremove(){
	int input , i, k , m , o , z ;
	printf("몇 관에 있는 영화를 삭제할건지? \n");
	sampleprint();	// 상영중 영화 간략히 출력
	scanf_s("%d",&input);
	if( input <= 0 || input > N ){			// 관 입력의 유효범위 
		printf(" 존재하지 않는 관입니다.");
		fflush(stdin);
		getchar();
		return;
	}	
	if (arr[input-1].hall == 0 ){
		printf(" 입력된 값에서 상영중인 영화를 찾을 수 없습니다.");	// 해당하는 관이 없을경우
		fflush(stdin);
		getchar();
		return;
	}else{
		arr[input-1].hall = 0;
	}
}
//------------------------------------------------------------------------------------
void movichange(){
	char movititle[9];
	int input , i ,k, sumtime,breaktime=0;
	fflush(stdin);
	printf("몇 관에 있는 영화를 수정할건지?\n");
	sampleprint();
	scanf_s("%d",&input);
	if( input <= 0 || input > N ){			// 관 입력의 유효범위 
		printf(" 존재하지 않는 관입니다.\n");
		fflush(stdin);
		getchar();
		return;
	}
	if (arr[input-1].hall == 0 ){
		printf(" 입력된 값에서 상영중인 영화를 찾을 수 없습니다.\n");
		fflush(stdin);
		getchar();
		return;
	}else{	
		system("cls");
		printf("\t      ━━━━━━━━━━━━━━━━━━━━━\n\t\tSystem에 수정할 영화 정보를 입력하세요\n\t      ━━━━━━━━━━━━━━━━━━━━━\n");
		printf("상 영 관 : %d\n" , arr[input-1].hall);
	
		printf("상영프로 : %s \n 수정 값  ▶ " , arr[input-1].title);
		scanf("%8s",&movititle);
		fflush(stdin);
		strcpy(arr[input-1].title,movititle);

		printf("시작시간 :");
		printf("%2d시%2d분 \n",arr[input-1].recycle[0]/60,arr[input-1].recycle[0]%60);
		printf(" 수정 값  ▶ ");
		scanf_s("%d %d",&sumtime,&arr[input-1].starttime);
		arr[input-1].starttime = arr[input-1].starttime + sumtime * 60;	//분으로 환산하여 입력

		printf("상영시간 : %d \n",arr[input-1].runingtime);
		printf(" 수정 값  ▶ ");
		scanf_s("%d",&arr[input-1].runingtime);

	//영화 입력 최대 N번 돌거나, 0을 입력하여 종료함.

		for(k = 0 ; k < 5 ; k++){
			arr[input-1].recycle[k] = arr[input-1].starttime+breaktime;
			breaktime = arr[input-1].runingtime + breaktime + 30;
		}
	}
	printf("\n *  Enter ━ Next Page  *");
	fflush(stdin);
	getchar();
}

//---------------------------------------------------------------------------------------------------
void nowtime()
{
	time(&ltime);
	today = localtime(&ltime);
	printf("현재 시각 :%02d월 %02d일 %02d시 %02d분 \n", today->tm_mon+1,today->tm_mday, today ->tm_hour, today->tm_min );
}
//----------------------------------------------------------------------------------------------------
void seatchange(){
	int numb,i,o,k,j,input,input_2;
	while(1){
	nowtime();
	for(i = 0 ; i < N ; i++){
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			if(arr[i].hall==0){
				printf("╋\t▶   [  %d관  ]\t[  비어있음 ]\t\t\t┃\n",i+1,arr[i].title);
				printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				continue;
			}
			printf("╋\t▶   [  %d관  ]\t[  %8s 상영중 ]\t\t┃\n",arr[i].hall,arr[i].title);
			printf("┃[회차] [시작 시간]\t[종료 시간]\t[잔여 좌석수]\t┃\n");
			timetable(i,1);
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	}

	printf(" 좌석을 수정할 관과 회차를 입력하시오 ");
	scanf_s("%d %d",&input,&numb);
	if( input <= 0 || input > N ){			// 관 입력의 유효범위 
		printf(" 존재하지 않는 관입니다.");
		fflush(stdin);
		getchar();
		return;
	}
	if (arr[input-1].hall == 0 ){
		printf(" 입력된 값에서 상영중인 영화를 찾을 수 없습니다.");
		fflush(stdin);
		getchar();
		return;
	}
	if((((today->tm_hour * 60)+today->tm_min) > arr[input-1].recycle[numb-1])|| numb>5){//시간값 오버되면 값을 넣을 수 없음.
		printf("현재 상영될 수 없는 회차입니다");
		fflush(stdin);
		getchar();
		return;
	}
		while(1){
			seattable(input-1,numb);
			printf(" 현재 %d 관 %d 회차 좌석 수정모드 입니다. \n 수정할 좌석의 좌표를 입력해주세요\n ",input,numb);
			scanf_s("%d %d",&j,&k);
			fflush(stdin);
			if( ( j < 0 || j >= Col ) || ( k < 0 || k >= Row ) ){
				printf(" 잘못된 입력입니다 ");
				getchar();
			}else{
				system("cls");
				arr[input-1].seat[numb-1][j][k] = ( arr[input-1].seat[numb-1][j][k] + 1 ) * -1 ; // 이 좌표 값만 '암호화'하듯, 값을 뒤집어놓음
				seattable(input-1,numb);
				printf(" 현재 좌석을 ... \n [ 0 ] . check out \n [ 1 ] . check in\n" );
				scanf_s("%d",&input);
				fflush(stdin);
				if( input < 0 || input > 1 ){
					printf("잘못된 값입니다.");
					getchar();
				}else{
					if( input == 1 && arr[input-1].seat[numb-1][j][k] == 0 ){				// 원래 있었던 값과 비교하여 남은 좌석수를 수정
						arr[input-1].seatsub[numb-1]++;
					}else if ( input == 0 && arr[input-1].seat[numb-1][j][k] == 1 ){ 
						printf(" check out 하셨습니다. \n 이동하시겠습니까? \n [ 0 ] No \n [ 1 ] Yes\n");
						scanf("%d",&input_2);
						if( input_2 == 0 ){
							arr[input-1].seatsub[numb-1]--; //삭제시 잔여 좌석수 --;
						}else{
							while(1){
								printf(" 수정할 좌석의 좌표를 입력해주세요 \n");
								scanf("%d %d",&i,&o);
								if( arr[input-1].seat[numb-1][i][o] == 0 ){
									arr[input-1].seat[numb-1][i][o] = 1;
									break;
								}else{
									printf(" 입력되어 있는 자리입니다. ");
								}
							}
						}
					}
					arr[input-1].seat[numb-1][j][k] = input;
				}
			}
			printf("\n [ 0 ] . End \n [ 1 ] . And... \n");
			scanf_s("%d",&input);
			fflush(stdin);
			if(input == 0){
				break;
			}else{
				system("cls");
			}
		}
	printf("\n좌석 수정 프로그램 ...\n [ 0 ] . End \n [ 1 ] . And... \n");
		scanf_s("%d",&input);
		fflush(stdin);
		if(input == 0){
			return;
		}else{
			system("cls");
		}
	}
}

void seattable(int i,int numb){
	int j,m,k;
	for( j = 0 ; j < Col ; j++ ){
		if( j == 0 ){
			printf("  ");
			for( m = 0 ; m < Row ; m++ ){
				if( m == (Row-1) / 3){
				printf(" ");
				}
				printf(" %d",m);
				if( m == (Row-1) -  (Row-1) / 3){
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("%d ",j);
		for( k = 0 ; k < Row ; k++ ){
			if( k == (Row-1) / 3){		//좌석 띄우기
				printf(" ");
			}
			if(arr[i].seat[numb-1][j][k] < 0){
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 12<<4 | 15);
				arr[i].seat[numb-1][j][k] = ( arr[i].seat[numb-1][j][k] +1 ) * -1; //뒤집어 놓은 값을 원래대로 돌리기.'
			}
			if(arr[i].seat[numb-1][j][k] == 0 ){
				printf("□");
			}else{
				printf("■");
			}
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
			if( k == (Row-1) -  (Row-1) / 3){			//좌석 띄우기
				printf(" ");
			}
		}
		printf("\n");
	}
}

void sampleprint(){
	int i;
	for ( i = 0 ; i < N ; i++ ){						//관별로 차례대로 출력하기 위하여.
			if(arr[i].hall == i+1){
				printf("[ %d ] 관 ▶ %s \n",arr[i].hall,arr[i].title);
			}
	}
}

void timetable(int in, int switch_){
	int k , colorsw=0;
		for(k = 0 ; k < 5 ; k++){
			if((((today->tm_hour * 60)+today->tm_min) < arr[in].recycle[k]) && (switch_)){ //현재 시간보다 상영시간이 크면 초록색
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
				if( ((arr[in].recycle[k])/60) >= 24){// 24시가 넘을경우, 다음 날의 개념으로 색을 다르게 주고싶음 -------
					arr[in].recycle[k] = arr[in].recycle[k] - 1440 ;		//24 시간을 분으로 바꾼 시간 1440.
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
					colorsw = 1;
				}
				if( (((arr[in].recycle[k]+arr[in].runingtime)/60 >= 24))){ //종료시간이 24시가 넘을경우
					printf("┃%d회\t%2d시%2d분\t%2d시%2d분\t\t%d \t┃\n",k+1,arr[in].recycle[k]/60,arr[in].recycle[k]%60,( (arr[in].recycle[k]+arr[in].runingtime) -1440)/60,((arr[in].recycle[k]+arr[in].runingtime) - 1440)%60,(Col*Row)-arr[in].seatsub[k]);
				}else{
				printf("┃%d회\t%2d시%2d분\t%2d시%2d분\t\t%d \t┃\n",k+1,arr[in].recycle[k]/60,arr[in].recycle[k]%60,(arr[in].recycle[k]+arr[in].runingtime)/60,(arr[in].recycle[k]+arr[in].runingtime)%60,(Col*Row)-arr[in].seatsub[k]);
				}
			}else if(switch_ == 0){
				if( ((arr[in].recycle[k])/60) >= 24){// 24시가 넘을경우, 다음 날의 개념으로 색을 다르게 주고싶음 -------
					arr[in].recycle[k] = arr[in].recycle[k] - 1440 ;		//24 시간을 분으로 바꾼 시간 1440.
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
					colorsw = 1;
				}
				if( (((arr[in].recycle[k]+arr[in].runingtime)/60 >= 24))){ //종료시간이 24시가 넘을경우
					printf("┃%d회\t%2d시%2d분\t%2d시%2d분\t\t%d \t┃\n",k+1,arr[in].recycle[k]/60,arr[in].recycle[k]%60,( (arr[in].recycle[k]+arr[in].runingtime) -1440)/60,((arr[in].recycle[k]+arr[in].runingtime) - 1440)%60,(Col*Row)-arr[in].seatsub[k]);
				}else{
				printf("┃%d회\t%2d시%2d분\t%2d시%2d분\t\t%d \t┃\n",k+1,arr[in].recycle[k]/60,arr[in].recycle[k]%60,(arr[in].recycle[k]+arr[in].runingtime)/60,(arr[in].recycle[k]+arr[in].runingtime)%60,(Col*Row)-arr[in].seatsub[k]);
				}
			}
			if(colorsw==1){//값을 다시 되돌려놓음.
				arr[in].recycle[k] = arr[in].recycle[k] + 1440 ;
				colorsw = 0;
			}
		}
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);

}

