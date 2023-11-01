#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//初始化棋盘，因后面扫雷需访问排查点周围一圈的范围，所以棋盘需要扩大一圈，防止访问越界
void initboard(char arr[29][29], int row, int col, char set)
{
	arr[29][29];
	int i, j = 0;
	for (i = 1; i <= row; i++)//行
	{
		for (j = 1; j <= col; j++)//列
		{
			arr[i][j] = set;//初始化棋盘为 0 / *
 		}
		
	}
	
}


//void display(char arr[29][29], int row, int col)
//{
//	int i, j = 0;
//	for(i = 0; i < row - 1; i++)
//		for (j = 0; j < col - 1; j++)
//		{
//			if (i == 0 && j == 0)
//				printf('0');
//			else if (i == 1 && j == 1)
//				printf('+');
//			else if (i == 0)
//				printf("%d", i - 1);
//			else if (j == 0)
//				printf()
//
//		}
//}