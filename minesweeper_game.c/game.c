#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//��ʼ�����̣������ɨ��������Ų����ΧһȦ�ķ�Χ������������Ҫ����һȦ����ֹ����Խ��
void initboard(char arr[100][100], int row, int col, char set)
{
	int i, j = 0;
	for (i = 1; i <= row; i++)//��
	{
		for (j = 1; j <= col; j++)//��
		{
			if (i == 1 && j == 1)//����λ�����⴦��
				arr[i - 1][j - 1] = '0';//����
			else if (i == 2 && j == 2)//����λ�����⴦��
				arr[i - 1][j - 1] == '+';
			else if (i == 1)
				arr[i - 1][j - 1] = j - 2;//������ʱ�ų������Ȧ
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
