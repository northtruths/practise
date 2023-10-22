#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bingan()//开始界面
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
	//1.生成随机数
	int r = rand()%100 + 1;
	//2..猜数字
	printf("请猜一个数字\n");
	int num = 0;
	int count = 1;
	while (1)
	{
		scanf("%d", &num);
		if (num > r)
			printf("猜大了\n");
		else if (num < r)
			printf("猜小了\n");
		else
		{
			printf("恭喜你，猜对了！");
			break;
		}
		printf("你还有%d次机会\n", 5 - count);
		count++;
		if (count == 6)
		{
			printf("很抱歉，你失败了\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));//设置种子
	
	int a = 0;
	while (bingan(),printf("玩猜数字游戏请输入 1 \n退出请输入 0\n "), scanf("%d", &a) != EOF)
	{
		switch (a)
		{
		case 1:game();
			break;
		case 0:printf("感谢游玩");
			goto end;
		default:printf("请不要输入 0 或 1 以外的数字");
		}
	}
end:
	return 0;
}