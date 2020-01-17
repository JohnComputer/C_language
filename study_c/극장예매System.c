// �ð��� ����� ��Ʈ������ ������ �κ��� '������' �̶� �������� ����ϴ� �κ��Դϴ�.
// ��Ʈ������ ��µǴºκ��� ���Ű� �ƴ� �ð� üũ�κп����� ��µǴ°��� ������ �ƴ϶� �Ϻη� �׷��� �ڵ��� �Ѱ��Դϴ�.


#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

time_t ltime;
struct tm *today;				//���� �ð� ����

#define N 5   //hall �� ��
#define M 12  //�ð���
#define T 10  //�ִ� �Է� ��ȭ����
#define Col 10// �ִ��¼� ����(��)��
#define Row 10// �ִ��¼� ����(��)��
int count = 0 ;
struct movitype{
	int hall,			// 0 �϶��� ���� �������� �ʴ°� , �׿� ������ �� ( �ش��ϴ� Ȧ ) �� ��
		seat[5][Col][Row],
		seatsub[5],		//�� ȸ���� ���� �ڸ� ī���� ( �⺻ ������ ���� ���� �¼����� ��� )
		starttime,		//���� �ð�
		runingtime,		// ����Ÿ��	
		recycle[5];		// ȸ�� 
	char title[10];		// ��ȭ Ÿ��Ʋ 
};
void input();
void recycleset();
void output();
void singlemode();			//������ ���
void reservation();			//����
void movichange();			//��ȭ�������� �� ����
void moviremove();			//��ȭ�� ������ �̵� 
void nowtime();				//���� �ð�
void sampleprint();			//���� �� ������ ������ ǥ���� (ȸ������ ����)
void seatchange();			//�¼� ����

void timetable(int in,int switch_);
void seattable(int i, int numb);
struct movitype arr[N];
void seting(){		// Ÿ��Ʋ �ʱ�ȭ 
	int i;
	char movititle[13]="�������";
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
			printf("\t\t����������������������������������\n");
			printf("\t\t\t1. ������ ���\n\t\t\t2. ��ȭ ����\n\t\t\t3. �ܿ��¼� ��ȸ\n\t\t\t4. �¼� ����\n\t\t\t5. ����\n");
			printf("\t\t����������������������������������\n");
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
//------------------------------------------------------------------------------------����
void reservation(){
	int i=0,c=0,end=1,breaktime=0 , m , numb, input , hallnum; 
	int input_seatnumb_r,input_seatnumb_c,input_seatcount;
	printf("\n ���� �ý���\n ������ ��ȭ ... \n");
	for( i = 0 ; i < N ; i++){
		if(arr[i].hall>0){
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
		}
		printf("[ %d �� ] - %s \n",i+1,arr[i].title);
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	}
	printf("\n������ �� �Է�\n");
	scanf_s("%d",&input);
	system("cls");
	if( input <= 0 || input > N ){			// �� �Է��� ��ȿ���� 
		printf(" �������� �ʴ� ���Դϴ�.");
		fflush(stdin);
		getchar();
		return;
	}
	if (arr[input-1].hall == 0){
		printf(" �Էµ� ������ ������ ��ȭ�� ã�� �� �����ϴ�..\n");
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
		printf("\n ���� ������ ��ȭ�� �����ϴ�.");
		getchar();
		return;
	}
	nowtime();		
	printf("����������������������������������������������������������\n");
	printf("��\t��   [  %d��  ]\t[  %8s ���� ]\t\t��\n",arr[input-1].hall,arr[input-1].title);
	printf("��[ȸ��] [���� �ð�]\t[���� �ð�]\t[�ܿ� �¼���]\t��\n");
	timetable(input-1,1);  // Ÿ�����̺� �ҷ�����
	printf("����������������������������������������������������������\n");
	printf("\n �����Ͻ� ��ȭ�� ȸ���� �Է��ϼ��� \n ȸ������ : ");
	scanf_s("%d",&numb);
	fflush(stdin);
	if((((today->tm_hour * 60)+today->tm_min) > arr[input-1].recycle[numb-1]) || numb>5){//�ð��� �����Ǹ� ���� ���� �� ����.
		printf("���� �󿵵� �� ���� ȸ���Դϴ�");
		getchar();
		return;
	}
	seattable(input-1,numb);//���̺� �ҷ�����

	fflush(stdin);
	printf("\n��� �¼��� �Է��Ͻǰ̴ϱ�?");
	scanf_s("%d",&input_seatcount);
		for( m = 0 ; m < input_seatcount ; m++){
			printf(" ������ �¼��� ��ǥ�� �Է��Ͻÿ�(�࿭) \n" );
			scanf_s("%d %d",&input_seatnumb_r,&input_seatnumb_c);
			if(!arr[input-1].seat[numb-1][input_seatnumb_r][input_seatnumb_c]){
				arr[input-1].seat[numb-1][input_seatnumb_r][input_seatnumb_c] = 1;
				arr[input-1].seatsub[numb-1]++;
			}else{
				printf(" ���� �ڸ��� �¼��� ����Ǿ��ֽ��ϴ� . \n");
				m--;
			}
		}
	system("cls");
	seattable(input-1,numb);
	printf("\n\n ���Ű� �Ϸ� �Ǿ����ϴ�. \n�����մϴ�. \n");
	fflush(stdin);
	getchar();//�ٽ��ѹ� Ȯ�ο����� ���̺� �ҷ�����
}

//------------------------------------------------------------------------------------
void singlemode(){
	int in;
	while(1){
	system("cls");
	printf("\t      ������������������������������������������\n\t\t1 . ������ ��� \n\t\t2 . ������ ����\n\t\t3 . ������ ����\n\t\t4 . ������ ��Ȳ\n\t\t5 . ���ư���\n\t      ������������������������������������������\n");
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
//-----------------------------------------------------------------------------------��ȭ �߰� 
void input(){
	int i=0,c=0,end=1,sumtime,hall,k;
	char movititle[9];
	while(end != 0 && count < N){	// ��ȭ �Է�
		
		system("cls");
		printf("\t      ������������������������������������������\n\t\tSystem�� �߰��� ��ȭ ������ �Է��ϼ���\n\t      ������������������������������������������\n");
		printf("�� �� �� :");
		scanf_s("%d",&hall);
		fflush(stdin);
		if( hall <= 0 || hall > N ){			// �� �Է��� ��ȿ���� 
			printf(" �������� �ʴ� ���Դϴ�.");
			getchar();
			return;
		}
		if(arr[hall-1].hall == hall){
			printf(" * �̹� �Էµ� �󿵰��Դϴ�.\n ���� ȭ������ ���ư��ϴ� . \n");
			getchar();
			return;
		}
		arr[hall-1].hall = hall;

		printf("������ :");
		scanf("%8s",&movititle);
		fflush(stdin);
		strcpy(arr[hall-1].title,movititle);
		while(1){
			printf("���۽ð� :");
			scanf_s("%d %d",&sumtime,&arr[hall-1].starttime);
			fflush(stdin);
			if(( sumtime < 0  || sumtime > 24 ) || (arr[hall-1].starttime < 0 || arr[hall-1].starttime > 60 )){
				printf(" �ð��� �Է��� �߸��Ǿ����ϴ�. �ٽ��Է����ּ��� \n");
			}else{
				break;
			}
		}

		arr[hall-1].starttime = arr[hall-1].starttime + sumtime * 60;	//������ ȯ���Ͽ� �Է�

		printf("�󿵽ð� :");
		scanf_s("%d",&arr[hall-1].runingtime);

		printf("\t\tNew insert [ 1 ]\n \t\tEnd\t   [ 0 ]\n");
		scanf_s("%d",&end);
	}//��ȭ �Է� �ִ� 10�� ���ų�, 0�� �Է��Ͽ� ������.
	printf("\n *  Enter �� Next Page  *");
	fflush(stdin);
	getchar();
}

//-------------------------------------------------------ȸ�� �ð� �� ���� ------
void recycleset(){
	int breaktime = 0;
	int i , k ;
		for(i = 0 ; i < N ; i++){
		if(arr[i].hall > 0){
			for(k = 0 ; k < 5 ; k++){
				arr[i].recycle[k] = arr[i].starttime+breaktime;					// ���۽ð� + �극��ũ Ÿ�� 
				breaktime = arr[i].runingtime + breaktime + 30;					// �극��ũ Ÿ�ӿ��� ������ ���ߴ� �ð����� ���½ð�(30��)�� ��� ���´�.
			}
			breaktime=0;														// �ٸ������� �Ѿ���� �극��ũ Ÿ�� �ʱ�ȭ
		}
	}
}
//----------------------------------------------------------- ��Ȳ ��� -------------------------

void output(){		
	int i=0,c=0,end=1,breaktime=0,input,numb=0,hall;
	while(1){
	system("cls");
	nowtime();
	for(i = 0 ; i < N ; i++){
		printf("����������������������������������������������������������\n");
		if(arr[i].hall==0){
			printf("��\t��   [  %d��  ]\t[  ������� ]\t\t\t��\n",i+1,arr[i].title);
			printf("����������������������������������������������������������\n");
			continue;
		}
		printf("��\t��   [  %d��  ]\t[  %8s ���� ]\t\t��\n",arr[i].hall,arr[i].title);
		printf("��[ȸ��] [���� �ð�]\t[���� �ð�]\t[�ܿ� �¼���]\t��\n");
		timetable(i,0);
		printf("����������������������������������������������������������\n");
	}

	
		printf("  ---- �¼�ǥ Ȯ�� ---- \n [ 0 ] . End \n [ 1 ] . Check \n");
		scanf_s("%d",&input);
		fflush(stdin);
		switch(input){
			case 0:
				return;	
			case 1:				//�̷��� Ȯ���Ҷ����� �ð����� �����Ǿ Ȯ�ε� �� �ְԲ� ��.
				printf("���� ȸ���� �Է��Ͻÿ�\n");
				scanf_s("%d %d",&input,&numb);
				if( input <= 0 || input > N ){			// �� �Է��� ��ȿ���� 
					printf(" �������� �ʴ� ���Դϴ�.");
					fflush(stdin);
					getchar();
					return;
				}
				if (arr[input-1].hall == 0){
					printf(" �Էµ� ������ ������ ��ȭ�� ã�� �� �����ϴ�.");
					fflush(stdin);
					getchar();
					return;
				}
				seattable(input-1,numb);
				printf("\n *  Enter �� Next Page  *");
				fflush(stdin);
				getchar();
				break;
		}
	}
}
//------------------------------------------------------------------------------------
void moviremove(){
	int input , i, k , m , o , z ;
	printf("�� ���� �ִ� ��ȭ�� �����Ұ���? \n");
	sampleprint();	// ���� ��ȭ ������ ���
	scanf_s("%d",&input);
	if( input <= 0 || input > N ){			// �� �Է��� ��ȿ���� 
		printf(" �������� �ʴ� ���Դϴ�.");
		fflush(stdin);
		getchar();
		return;
	}	
	if (arr[input-1].hall == 0 ){
		printf(" �Էµ� ������ ������ ��ȭ�� ã�� �� �����ϴ�.");	// �ش��ϴ� ���� �������
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
	printf("�� ���� �ִ� ��ȭ�� �����Ұ���?\n");
	sampleprint();
	scanf_s("%d",&input);
	if( input <= 0 || input > N ){			// �� �Է��� ��ȿ���� 
		printf(" �������� �ʴ� ���Դϴ�.\n");
		fflush(stdin);
		getchar();
		return;
	}
	if (arr[input-1].hall == 0 ){
		printf(" �Էµ� ������ ������ ��ȭ�� ã�� �� �����ϴ�.\n");
		fflush(stdin);
		getchar();
		return;
	}else{	
		system("cls");
		printf("\t      ������������������������������������������\n\t\tSystem�� ������ ��ȭ ������ �Է��ϼ���\n\t      ������������������������������������������\n");
		printf("�� �� �� : %d\n" , arr[input-1].hall);
	
		printf("������ : %s \n ���� ��  �� " , arr[input-1].title);
		scanf("%8s",&movititle);
		fflush(stdin);
		strcpy(arr[input-1].title,movititle);

		printf("���۽ð� :");
		printf("%2d��%2d�� \n",arr[input-1].recycle[0]/60,arr[input-1].recycle[0]%60);
		printf(" ���� ��  �� ");
		scanf_s("%d %d",&sumtime,&arr[input-1].starttime);
		arr[input-1].starttime = arr[input-1].starttime + sumtime * 60;	//������ ȯ���Ͽ� �Է�

		printf("�󿵽ð� : %d \n",arr[input-1].runingtime);
		printf(" ���� ��  �� ");
		scanf_s("%d",&arr[input-1].runingtime);

	//��ȭ �Է� �ִ� N�� ���ų�, 0�� �Է��Ͽ� ������.

		for(k = 0 ; k < 5 ; k++){
			arr[input-1].recycle[k] = arr[input-1].starttime+breaktime;
			breaktime = arr[input-1].runingtime + breaktime + 30;
		}
	}
	printf("\n *  Enter �� Next Page  *");
	fflush(stdin);
	getchar();
}

//---------------------------------------------------------------------------------------------------
void nowtime()
{
	time(&ltime);
	today = localtime(&ltime);
	printf("���� �ð� :%02d�� %02d�� %02d�� %02d�� \n", today->tm_mon+1,today->tm_mday, today ->tm_hour, today->tm_min );
}
//----------------------------------------------------------------------------------------------------
void seatchange(){
	int numb,i,o,k,j,input,input_2;
	while(1){
	nowtime();
	for(i = 0 ; i < N ; i++){
			printf("����������������������������������������������������������\n");
			if(arr[i].hall==0){
				printf("��\t��   [  %d��  ]\t[  ������� ]\t\t\t��\n",i+1,arr[i].title);
				printf("����������������������������������������������������������\n");
				continue;
			}
			printf("��\t��   [  %d��  ]\t[  %8s ���� ]\t\t��\n",arr[i].hall,arr[i].title);
			printf("��[ȸ��] [���� �ð�]\t[���� �ð�]\t[�ܿ� �¼���]\t��\n");
			timetable(i,1);
			printf("����������������������������������������������������������\n");
	}

	printf(" �¼��� ������ ���� ȸ���� �Է��Ͻÿ� ");
	scanf_s("%d %d",&input,&numb);
	if( input <= 0 || input > N ){			// �� �Է��� ��ȿ���� 
		printf(" �������� �ʴ� ���Դϴ�.");
		fflush(stdin);
		getchar();
		return;
	}
	if (arr[input-1].hall == 0 ){
		printf(" �Էµ� ������ ������ ��ȭ�� ã�� �� �����ϴ�.");
		fflush(stdin);
		getchar();
		return;
	}
	if((((today->tm_hour * 60)+today->tm_min) > arr[input-1].recycle[numb-1])|| numb>5){//�ð��� �����Ǹ� ���� ���� �� ����.
		printf("���� �󿵵� �� ���� ȸ���Դϴ�");
		fflush(stdin);
		getchar();
		return;
	}
		while(1){
			seattable(input-1,numb);
			printf(" ���� %d �� %d ȸ�� �¼� ������� �Դϴ�. \n ������ �¼��� ��ǥ�� �Է����ּ���\n ",input,numb);
			scanf_s("%d %d",&j,&k);
			fflush(stdin);
			if( ( j < 0 || j >= Col ) || ( k < 0 || k >= Row ) ){
				printf(" �߸��� �Է��Դϴ� ");
				getchar();
			}else{
				system("cls");
				arr[input-1].seat[numb-1][j][k] = ( arr[input-1].seat[numb-1][j][k] + 1 ) * -1 ; // �� ��ǥ ���� '��ȣȭ'�ϵ�, ���� ���������
				seattable(input-1,numb);
				printf(" ���� �¼��� ... \n [ 0 ] . check out \n [ 1 ] . check in\n" );
				scanf_s("%d",&input);
				fflush(stdin);
				if( input < 0 || input > 1 ){
					printf("�߸��� ���Դϴ�.");
					getchar();
				}else{
					if( input == 1 && arr[input-1].seat[numb-1][j][k] == 0 ){				// ���� �־��� ���� ���Ͽ� ���� �¼����� ����
						arr[input-1].seatsub[numb-1]++;
					}else if ( input == 0 && arr[input-1].seat[numb-1][j][k] == 1 ){ 
						printf(" check out �ϼ̽��ϴ�. \n �̵��Ͻðڽ��ϱ�? \n [ 0 ] No \n [ 1 ] Yes\n");
						scanf("%d",&input_2);
						if( input_2 == 0 ){
							arr[input-1].seatsub[numb-1]--; //������ �ܿ� �¼��� --;
						}else{
							while(1){
								printf(" ������ �¼��� ��ǥ�� �Է����ּ��� \n");
								scanf("%d %d",&i,&o);
								if( arr[input-1].seat[numb-1][i][o] == 0 ){
									arr[input-1].seat[numb-1][i][o] = 1;
									break;
								}else{
									printf(" �ԷµǾ� �ִ� �ڸ��Դϴ�. ");
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
	printf("\n�¼� ���� ���α׷� ...\n [ 0 ] . End \n [ 1 ] . And... \n");
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
			if( k == (Row-1) / 3){		//�¼� ����
				printf(" ");
			}
			if(arr[i].seat[numb-1][j][k] < 0){
				SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 12<<4 | 15);
				arr[i].seat[numb-1][j][k] = ( arr[i].seat[numb-1][j][k] +1 ) * -1; //������ ���� ���� ������� ������.'
			}
			if(arr[i].seat[numb-1][j][k] == 0 ){
				printf("��");
			}else{
				printf("��");
			}
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
			if( k == (Row-1) -  (Row-1) / 3){			//�¼� ����
				printf(" ");
			}
		}
		printf("\n");
	}
}

void sampleprint(){
	int i;
	for ( i = 0 ; i < N ; i++ ){						//������ ���ʴ�� ����ϱ� ���Ͽ�.
			if(arr[i].hall == i+1){
				printf("[ %d ] �� �� %s \n",arr[i].hall,arr[i].title);
			}
	}
}

void timetable(int in, int switch_){
	int k , colorsw=0;
		for(k = 0 ; k < 5 ; k++){
			if((((today->tm_hour * 60)+today->tm_min) < arr[in].recycle[k]) && (switch_)){ //���� �ð����� �󿵽ð��� ũ�� �ʷϻ�
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
				if( ((arr[in].recycle[k])/60) >= 24){// 24�ð� �������, ���� ���� �������� ���� �ٸ��� �ְ���� -------
					arr[in].recycle[k] = arr[in].recycle[k] - 1440 ;		//24 �ð��� ������ �ٲ� �ð� 1440.
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
					colorsw = 1;
				}
				if( (((arr[in].recycle[k]+arr[in].runingtime)/60 >= 24))){ //����ð��� 24�ð� �������
					printf("��%dȸ\t%2d��%2d��\t%2d��%2d��\t\t%d \t��\n",k+1,arr[in].recycle[k]/60,arr[in].recycle[k]%60,( (arr[in].recycle[k]+arr[in].runingtime) -1440)/60,((arr[in].recycle[k]+arr[in].runingtime) - 1440)%60,(Col*Row)-arr[in].seatsub[k]);
				}else{
				printf("��%dȸ\t%2d��%2d��\t%2d��%2d��\t\t%d \t��\n",k+1,arr[in].recycle[k]/60,arr[in].recycle[k]%60,(arr[in].recycle[k]+arr[in].runingtime)/60,(arr[in].recycle[k]+arr[in].runingtime)%60,(Col*Row)-arr[in].seatsub[k]);
				}
			}else if(switch_ == 0){
				if( ((arr[in].recycle[k])/60) >= 24){// 24�ð� �������, ���� ���� �������� ���� �ٸ��� �ְ���� -------
					arr[in].recycle[k] = arr[in].recycle[k] - 1440 ;		//24 �ð��� ������ �ٲ� �ð� 1440.
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
					colorsw = 1;
				}
				if( (((arr[in].recycle[k]+arr[in].runingtime)/60 >= 24))){ //����ð��� 24�ð� �������
					printf("��%dȸ\t%2d��%2d��\t%2d��%2d��\t\t%d \t��\n",k+1,arr[in].recycle[k]/60,arr[in].recycle[k]%60,( (arr[in].recycle[k]+arr[in].runingtime) -1440)/60,((arr[in].recycle[k]+arr[in].runingtime) - 1440)%60,(Col*Row)-arr[in].seatsub[k]);
				}else{
				printf("��%dȸ\t%2d��%2d��\t%2d��%2d��\t\t%d \t��\n",k+1,arr[in].recycle[k]/60,arr[in].recycle[k]%60,(arr[in].recycle[k]+arr[in].runingtime)/60,(arr[in].recycle[k]+arr[in].runingtime)%60,(Col*Row)-arr[in].seatsub[k]);
				}
			}
			if(colorsw==1){//���� �ٽ� �ǵ�������.
				arr[in].recycle[k] = arr[in].recycle[k] + 1440 ;
				colorsw = 0;
			}
		}
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);

}

