#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>
#include<stdbool.h>
#include<locale.h>
#include<time.h>

//贪吃蛇在控制台上的实现
//思路：
//1.要实现大体效果：贪吃蛇在一个地图上移动，地图上有食物，吃掉食物变长，撞墙或撞到自己死亡，
// 有加速、减速功能，可以暂停，有游戏开头欢迎，有游戏得分和提示语等

#define WALL L'■'
#define BODY L'◎'
#define FOOD L'●'

//判断是否按下了某键
#define GetAsyncKeyState(VK) ((GetAsyncKeyState(VK) & 0x01)?true:false)

//蛇节点的定义
typedef struct Snake
{
	int x;//在地图上的坐标
	int y;

	struct Snake* next;
}Snake;

//游戏状态
enum State
{
	OK = 1,
	ESC,
	KILL_BY_WALL,
	KILL_BY_SELF
};

//食物信息
typedef struct Food
{
	int x;
	int y;
	bool YoN;
}Food;

enum direction
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//整个游戏的维护
typedef struct AllGame
{
	Snake* snake;
	int score;
	enum state state;
	int speed;
	Food food;
	int lenth;
	enum direction dir;

}AllGame;

//提前准备，像读取地区化信息（），控制台的大小、名字
void Prepare();

//设置光标位置
void SetPos(short x, short y);

//游戏初始化
void InitGame(AllGame* game);

//开头界面、欢迎语,提示语
void Welcom();

//地图
void CreatMap();

//初始化蛇
void CreatSnake(AllGame* game);

//打印蛇
Snake* PrintSnake(AllGame* game);

//游戏过程
void RunGame(AllGame* game);

//设置食物
void SetFood(AllGame* game);

//得分展示，其他 tips
void DisplayScore(AllGame* game);

//蛇的移动
void MoveSnake(AllGame* game);

//其他功能：暂停、加减速等
void OtherFunc(AllGame* game);

//撞到自己，返回flag判断自杀还是他杀
int Suicide(game);
