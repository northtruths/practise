#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//��ʼ�����̣������ɨ��������Ų����ΧһȦ�ķ�Χ������������Ҫ����һȦ����ֹ����Խ��
void initboard(char arr[29][29], int row, int col, char set)
{
	arr[29][29];
	int i, j = 0;
	for (i = 1; i <= row; i++)//��
	{
		for (j = 1; j <= col; j++)//��
		{
			arr[i][j] = set;//��ʼ������Ϊ 0 / *
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