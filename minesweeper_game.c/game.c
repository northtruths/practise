#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//��ʼ�����̣������ɨ��������Ų����ΧһȦ�ķ�Χ������������Ҫ����һȦ����ֹ����Խ��
void initboard(char arr[29][29], int row, int col, char set)
{
	int i, j = 0;
	for (i = 0; i < row; i++)//��
	{
		for (j = 0; j < col; j++)//��
		{
			arr[i][j] = set;//��ʼ������Ϊ 0 / *
 		}
		
	}
	
}

//���������������
void display(char arr[29][29], int row, int col)
{
	int i,j = 0;
	for (j = 0; j < col - 1; j++)//��ӡ���̵�һ��
	{
		if (j == 0)
			printf("0");
		else
			printf("%d", j - 1);
	}
	printf("\n");
	for (j = 0; j < col - 1; j++)//��ӡ���̵ڶ���
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
		printf("%d", i - 1);//��ӡ����
		printf("|");//��ӡ�߽�
		for (j = 2; j < col - 1; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

//������
void setmine(char arr[29][29], int row, int col, int count)
{
	int i, j = 0;
	for (i = 0; i < count; count--)//�����׵ĸ���
	{
		int x = rand() % (row - 3) + 2;//������������������������
		int y = rand() % (col - 3) + 2;
		if (arr[x][y] == '0')//����˴�δ������������
			arr[x][y] = '1';
	}
}

//��ʾ�׵ĸ���
int count_mine(char arr[29][29], int x ,int y)
{
	int cot = 0;
	cot = arr[x - 1][y - 1] + arr[x - 1][y] + arr[x - 1][y + 1] + arr[x][y - 1]
		  + arr[x][y + 1] + arr[x + 1][y - 1] + arr[x + 1][y] + arr[x + 1][y + 1] - 8 * '0';//����������Χ�׵����������������ַ�����Ҫ����ASCII�����㣩
	return cot;
}

//�Ų���
void findmine(char show[29][29], char mine[29][29], int row, int col, int count)
{
	int x, y = 0;
	int win = 0;
	while (win < row * col - count)
	{
		printf("��������Ҫ�Ų�ĵط�������\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж������Ƿ���������
		{
			if (mine[x + 1][y + 1] == '1')
			{
				printf("�㱻ը����!\n");
				display(mine, row + 3, col + 3);//չʾ��
				break;
			}
			else//��������ף���ʾ��ΧһȦ�׵ĸ���
			{
				int num = 0;
				num = count_mine(mine, x + 1, y + 1);
				show[x + 1][y + 1] = num + '0';//���μ��ַ�0�� count ת��Ϊ�ַ�
				system("cls");//�����Ļ
				display(show, row + 3, col + 3);
				win++;//ÿ��һ������ʤ���ͽ�һ��
			}
		}
		else
			printf("��������ȷ�����꣡\n");
	}
	if (win == row * col - count)
		printf("��ϲ�㣬ɨ�׳ɹ���");
}