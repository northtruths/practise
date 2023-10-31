#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//初始化棋盘，因后面扫雷需访问排查点周围一圈的范围，所以棋盘需要扩大一圈，防止访问越界
void initboard(char arr[100][100], int row, int col, char set)
{
	int i, j = 0;
	for (i = 1; i <= row; i++)//行
	{
		for (j = 1; j <= col; j++)//列
		{
			if (i == 1 && j == 1)//特殊位置特殊处理
				arr[i - 1][j - 1] = '0';//错误
			else if (i == 2 && j == 2)//特殊位置特殊处理
				arr[i - 1][j - 1] == '+';
			else if (i == 1)
				arr[i - 1][j - 1] = j - 2;//标坐标时排除多的两圈
			else if (j == 1)
				arr[i - 1][j - 1] = i - 2;
			else if (i == 2)
				arr[i - 1][j - 1] = '-';
			else if (j == 2)
				arr[i - 1][j - 1] = '|';
			else 
				arr[i - 1][j - 1] = '0';
		}
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++)
				printf("%c", arr[i][j]);
		printf("\n");
	}
}
