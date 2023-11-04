#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//初始化棋盘，因后面扫雷需访问排查点周围一圈的范围，所以棋盘需要扩大一圈，防止访问越界
void initboard(char arr[29][29], int row, int col, char set)
{
	int i, j = 0;
	for (i = 0; i < row; i++)//行
	{
		for (j = 0; j < col; j++)//列
		{
			arr[i][j] = set;//初始化棋盘为 0 / *
 		}
		
	}
	
}

//玩家所看到的棋盘
void display(char arr[29][29], int row, int col)
{
	int i,j = 0;
	for (j = 0; j < col - 1; j++)//打印棋盘第一行
	{
		if (j == 0)
			printf("0");
		else
			printf("%d", j - 1);
	}
	printf("\n");
	for (j = 0; j < col - 1; j++)//打印棋盘第二行
	{
		if (j == 0)
			printf("0");
		else if (j == 1)
			printf("+");
		else
			printf("-");
	}
	printf("\n");
	for (i = 2; i < row - 1; i++)
	{
		printf("%d", i - 1);//打印坐标
		printf("|");//打印边界
		for (j = 2; j < col - 1; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

//布置雷
void setmine(char arr[29][29], int row, int col, int count)
{
	int i, j = 0;
	for (i = 0; i < count; count--)//设置雷的个数
	{
		int x = rand() % (row - 3) + 2;//生成随机坐标在棋盘里，布置雷
		int y = rand() % (col - 3) + 2;
		if (arr[x][y] == '0')//如果此处未布置雷则布置雷
			arr[x][y] = '1';
	}
}

//显示雷的个数
int count_mine(char arr[29][29], int x ,int y)
{
	int cot = 0;
	cot = arr[x - 1][y - 1] + arr[x - 1][y] + arr[x - 1][y + 1] + arr[x][y - 1]
		  + arr[x][y + 1] + arr[x + 1][y - 1] + arr[x + 1][y] + arr[x + 1][y + 1] - 8 * '0';//计算坐标周围雷的数量（因数组是字符所以要借助ASCII来计算）
	return cot;
}

//排查雷
void findmine(char show[29][29], char mine[29][29], int row, int col, int count)
{
	int x, y = 0;
	int win = 0;
	while (win < row * col - count)
	{
		printf("请输入想要排查的地方的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标是否在棋盘内
		{
			if (mine[x + 1][y + 1] == '1')
			{
				printf("你被炸死了!\n");
				display(mine, row + 3, col + 3);//展示雷
				break;
			}
			else//如果不是雷，显示周围一圈雷的个数
			{
				int num = 0;
				num = count_mine(mine, x + 1, y + 1);
				show[x + 1][y + 1] = num + '0';//整形加字符0将 count 转换为字符
				system("cls");//清除屏幕
				display(show, row + 3, col + 3);
				win++;//每排一个，离胜利就进一步
			}
		}
		else
			printf("请输入正确的坐标！\n");
	}
	if (win == row * col - count)
		printf("恭喜你，扫雷成功！");
}