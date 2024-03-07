#define _CRT_SECURE_NO_WARNINGS

#include"Snakes.h"

int main()
{
	char ret = 0;
	do
	{
		//游戏实现流程：开头界面、地图、蛇的初始化， 游戏进行过程， 游戏结束善后（释放、提示语）
		AllGame game;

		Prepare();

		InitGame(&game);

		RunGame(&game);
		EndGame(&game);
		ret = getchar();
		getchar();
	} while (ret == 'Y' || ret == 'y');

	SetPos(0, 31);
	return 0;
}