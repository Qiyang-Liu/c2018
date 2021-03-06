#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 
#define ROW 10
#define COL 10



int main(){
	void output(int (*p)[COL],int x,int y,char ch);			//函数声明 
	void move(int (*p)[COL],char ch,int *px,int *py);
	void print(int *p);
	void goto_xy(int,int);
	
	int maze[ROW][COL]={										//迷宫数组 
	35,43,35,35,35,35,35,35,35,35,
	35,43,43,43,35,35,35,43,35,35,
	35,35,35,43,35,35,35,43,35,35,
	35,35,35,43,43,43,43,35,35,35,
	35,43,43,43,43,35,43,35,35,35,
	35,43,35,35,43,35,43,35,35,35,
	35,43,43,35,35,35,43,35,43,35,
	35,43,43,43,43,35,43,43,43,35,
	35,43,35,35,35,35,35,35,43,43,
	35,35,35,35,35,35,35,35,35,35
	};
	
	int x = 0,y = 1;										//定义变量 
	int *px = &x,*py = &y;
	int (*p)[COL] = maze;
	char m;
	
	output(p,x,y,'w');										//迷宫实现 

	m = getch();
	while (1){
		move(p,m,px,py);
		if (maze[ROW-2][COL-1] == 64){
			break;
		}
		m = getch();
	}
	printf("Congratulations!\n");
	system("pause");
	return 0;
}

void print(int *p){											//输出迷宫数组 
	printf("\n");
	for (int i = 0; i<ROW; i++){
		for (int j = 0; j<COL; j++,p++){
			//if (*p == 43 || *p == 64){
				printf(" ");
			//}
			printf("%c",*p);
		}
		printf("\n");
	}
		
	printf("迷宫小游戏\n");
	printf("图例：\n");
	printf("%c --墙壁, %c --道路, %c --人物\n",35,43,64);
	printf("输入w, a, s, d移动人物\n");
	printf("w -- 向上, a -- 向左, s -- 向下, d -- 向右\n");
	
}

void goto_xy(int x,int y){									//定位光标位置到指定坐标
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(hOut,pos);
}

void output(int (*p)[COL],int x,int y,char ch){				//实现玩家移动 
	
	if (ch == 'w'){
		*(*(p+x)+y) = 64;
		system("cls");
		print((int *) p);
		goto_xy(0,20);
	}
	else {
		*(*(p+x)+y) = 43;
		system("cls");
		print((int *) p);
		goto_xy(0,20);
	}
}

int isWall(int (*p)[COL],int x,int y){						//判断玩家移动位置是否为墙壁 
	if (*(*(p+x)+y) == 43){
		return 0;
	}
	else return 1;
}

void move(int (*p)[COL],char ch,int *px,int *py){			//实现玩家移动 
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



