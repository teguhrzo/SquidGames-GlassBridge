#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int progress, lvl;

struct data{
	char nama[100];
	int score;
}board;

void map(int *n, int *m, char move){
	int i, j,b=11;
	if(lvl==2){
		b=21;
	}
	srand(time(NULL));
	int trap = rand()%2+1;
	char over;
	system("cls");
	if(trap == 1){
		over='a';
	}else{
		over='d';
	}
	if(over==move){
		progress=0;
	}else{
		progress=1;
	}
	for(i=0; i<b; i++){
		for(j=0; j<7; j++){
			if(j==0 || j==6){
			printf("|");
			}else if(*n==i && *m==j){
				if(progress==1){
					printf("O");
				}else if(progress==0 && i==b-1){
					printf("O");
				}else{
					printf("X");
				}
			}else if(j==2 && i%2==0 || j==4 && i%2==0 ){
				if(i==b-1){
					printf(" ");
				}else{
					printf("#");
				}
			}else if(i==b-2){
				printf("-");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(){
	char ulang, ulang2, move;
	int highscore=0;
	printf("Input your name: ");
	gets(board.nama);
	do{
		int n=10, m=3, win;
		if(lvl==2){
			n=20;
		}
		win=n/2;
		board.score=0;
		system("cls");
		map(&n,&m, move);
		printf("\nPress a or d to control");
		do{
		move=getch();
			if(move=='a'){
			n-=2;
			m -=1;
			map(&n,&m, move);
			m+=1;
			}else if(move=='d'){
			n-=2;
			m+=1;
			map(&n,&m, move);
			m-=1;
			}
			if(progress==1 && move=='a'|| progress==1 && move=='d'){
				board.score+=1;
			}
		}while(progress==1 && board.score!=win);
		if(highscore<=board.score){
			highscore = board.score;
		}
		
		if(board.score != win){
			printf("\nYou lose!\n");
			printf("\nYour Highscore: %d\n",highscore);
			printf("%s | Score: %d\n", board.nama, board.score);
			printf("\nPress r to play again\nPress q to quit");
			do{
				ulang=getch();
			}while(ulang!='r'&& ulang!='q');
			if(ulang=='q'){
				break;
			}
		}else{
			printf("\nYou Win!\n");
			printf("\nYour Highscore: %d\n",highscore);
			printf("%s | Score: %d\n", board.nama, board.score);
			if(lvl==2){
				break;
			}else{
				printf("Press 1 to continue to the next level\nPress 2 to quit"); 
				do{
				ulang2 = getch();	
				}while(ulang2 != '1' && ulang2 != '2');
				if(ulang2 == '1'){
					ulang='r';
					lvl=2;
					highscore=0;
				}else if(ulang2 == '2'){
					break;
				}
			}
		}		
	}while(ulang=='r');
	return 0;
}
