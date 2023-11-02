#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//扫雷游戏实现
//1.开始菜单
//2.初始化布雷棋盘 与 玩家所能看见的棋盘
//3.布置雷,0 为非雷，1 为雷
//4.扫雷，是雷炸，不是雷显示九宫格范围内雷的个数(clr清除屏幕达到更好的效果)
//5.计算雷剩余个数判断胜利
//6.如果排查的不是雷，周围也没有雷，显示周围一片


void menu()
{
	printf("********************************");
	printf("*********    1.play    *********");
	printf("*********    0.exit    *********");
	printf("********************************");
}


int main()
{
	int row = 0;
	int col = 0;
	int count = 0;
	int start = 0;
	char mine[29][29] = { 0 };
	char show[29][29] = { 0 };
	char set = 0;
	srand((unsigned int)time(NULL));
	menu;
	do
	{
		printf("玩游戏请输入 1 ，退出游戏请输入 0 \n");
		scanf("%d", &start);
		switch (start)
		{
		case 1:
			printf("请选择难度(输入数字)：\n1.简单（9x9 *10）\n2.普通（16x16 *40）\n3.困难（25x25 *99)\n");
			int chose = 0;
			scanf("%d", &chose);
			switch (chose)
			{
			case 1:row = 9, col = 9,count = 10;
				break;
			case 2:row = 16, col = 16, count = 40;
				break;
			case 3:row = 25, col = 25, count = 99;
				break;
			}
			initboard(mine, row + 3, col + 3, '0');
			initboard(show, row + 3, col + 3, '*');
			display(show, row + 3, col + 3);
			setmine(mine, row + 3, col + 3, count);
			findmine(show, mine, row, col, count);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请正确输入！\n");
		}
	}
	while (start); 

	return 0;
}