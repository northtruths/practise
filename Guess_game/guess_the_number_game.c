#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bingan()//��ʼ����
{
	printf("**********************************\n");
	printf("**********************************\n");
	printf("************  1.play  ************\n");
	printf("************  0.exit  ************\n");
	printf("**********************************\n");
	printf("**********************************\n");
}

void game()
{
	//1.���������
	int r = rand()%100 + 1;
	//2..������
	printf("���һ������\n");
	int num = 0;
	int count = 1;
	while (1)
	{
		scanf("%d", &num);
		if (num > r)
			printf("�´���\n");
		else if (num < r)
			printf("��С��\n");
		else
		{
			printf("��ϲ�㣬�¶��ˣ�");
			break;
		}
		printf("�㻹��%d�λ���\n", 5 - count);
		count++;
		if (count == 6)
		{
			printf("�ܱ�Ǹ����ʧ����\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));//��������
	
	int a = 0;
	while (bingan(),printf("���������Ϸ������ 1 \n�˳������� 0\n "), scanf("%d", &a) != EOF)
	{
		switch (a)
		{
		case 1:game();
			break;
		case 0:printf("��л����");
			goto end;
		default:printf("�벻Ҫ���� 0 �� 1 ���������");
		}
	}
end:
	return 0;
}