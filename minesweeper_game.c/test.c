#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//ɨ����Ϸʵ��
//1.��ʼ�˵�
//2.��ʼ���������� �� ������ܿ���������
//3.������,0 Ϊ���ף�1 Ϊ��
//4.ɨ�ף�����ը����������ʾ�Ź���Χ���׵ĸ���(clr�����Ļ�ﵽ���õ�Ч��)
//5.������ʣ������ж�ʤ��
//6.����Ų�Ĳ����ף���ΧҲû���ף���ʾ��ΧһƬ


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
		printf("����Ϸ������ 1 ���˳���Ϸ������ 0 \n");
		scanf("%d", &start);
		switch (start)
		{
		case 1:
			printf("��ѡ���Ѷ�(��������)��\n1.�򵥣�9x9 *10��\n2.��ͨ��16x16 *40��\n3.���ѣ�25x25 *99)\n");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����ȷ���룡\n");
		}
	}
	while (start); 

	return 0;
}