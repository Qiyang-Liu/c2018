#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define ROW 10
#define COL 10

int maze[ROW][COL]={										//�Թ����� 
	43,35,43,43,43,43,43,43,43,43,
	43,35,35,35,43,43,43,35,43,43,
	43,43,43,35,43,43,43,35,43,43,
	43,43,43,35,35,35,35,43,43,43,
	43,35,35,35,35,43,35,43,43,43,
	43,35,43,43,35,43,35,43,43,43,
	43,35,35,43,43,43,35,43,35,43,
	43,35,35,35,35,43,35,35,35,43,
	43,35,43,43,43,43,43,43,35,35,
	43,43,43,43,43,43,43,43,43,43
	};

int main(){
	void output(int (*p)[COL],int x,int y,char ch);			//�������� 
	void move(int (*p)[COL],char ch,int *px,int *py);
	void print(int *p);
	void goto_xy(int,int);
	
	int x = 0,y = 1;										//������� 
	int *px = &x,*py = &y;
	int (*p)[COL] = maze;
	char m;
	
	output(p,x,y,'w');										//�Թ�ʵ�� 

	m = getchar();
	while (maze[ROW-2][COL-1] != 64){
		move(p,m,px,py);
		m = getchar();
	}
	printf("Congratulations!");
	system("pause");
	return 0;
}

void print(int *p){											//����Թ����� 
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			//if (*p == 35 || *p == 64){
				printf(" ");
			//}
			printf("%c",*p);
		}
		printf("\n");
	}
		
	printf("�Թ�С��Ϸ\n");
	printf("����w, a, s, d�ƶ�����\n");
	printf("w -- ����, a -- ����, s -- ����, d -- ����\n");
	
}

void goto_xy(int x,int y){									//��λ���λ�õ�ָ������
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(hOut,pos);
}

void output(int (*p)[COL],int x,int y,char ch){				//ʵ������ƶ� 
	if (ch == 'w'){
		*(*(p+x)+y) = 64;
		system("cls");
		print(&maze[0][0]);
		goto_xy(0,15);
	}
	else {
		*(*(p+x)+y) = 35;
		system("cls");
		print(&maze[0][0]);
		goto_xy(0,15);
	}
}

int isWall(int (*p)[COL],int x,int y){						//�ж�����ƶ�λ���Ƿ�Ϊǽ�� 
	if (*(*(p+x)+y) == 35){
		return 0;
	}
	else return 1;
}

void move(int (*p)[COL],char ch,int *px,int *py){			//ʵ������ƶ� 
	int x = *px, y = *py;
	switch (ch){
		case 'w':
			if (isWall(p,x-1,y) == 0){
				output(p,x,y,'b');
				output(p,x-1,y,'w');
				*px = x-1;
			}
			break;
		case 'a':
			if (isWall(p,x,y-1) == 0){
				output(p,x,y,'b');
				output(p,x,y-1,'w');
				*py = y-1;
			}
			break;
		case 's':
			if (isWall(p,x+1,y) == 0){
				output(p,x,y,'b');
				output(p,x+1,y,'w');
				*px = x+1;
			}
			break;
		case 'd':
			if (isWall(p,x,y+1) == 0){
				output(p,x,y,'b');
				output(p,x,y+1,'w');
				*py = y+1;
			}
			break;
		default:;
	}
}


