#define _CRT_SECURE_NO_WARNINGS

#include"Snakes.h"

int main()
{
	AllGame game;
	//游戏实现流程：开头界面、地图、蛇的初始化， 游戏进行过程， 游戏结束善后（释放、提示语）
	
	Prepare();

	InitGame(&game);

	RunGame(&game);
	//EndGame();
	
	return 0;
}