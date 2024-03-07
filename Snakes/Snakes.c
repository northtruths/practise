#define _CRT_SECURE_NO_WARNINGS

#include"Snakes.h"

void Prepare()
{
	//读取地域化信息，使我们的一些中文符号可以合法使用（适用）
	setlocale(LC_ALL, "");
	//消除光标增加美观
	CONSOLE_CURSOR_INFO curinfo;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(handle, &curinfo);
	curinfo.bVisible = false;
	SetConsoleCursorInfo(handle, &curinfo);
	//把控制台设为150：40， 其中100 列 、30 行来做地图
	system("mode con cols=150 lines=40");
}

void SetPos(short x, short y)//设置光标的坐标
{
	COORD pos = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}


void Welcom()
{
	SetPos(60, 18);
	printf("欢迎来到贪吃蛇游戏");
	SetPos(60, 30);
	system("pause");
	system("cls");
	SetPos(60, 18);
	printf("↑ ↓ ← → 控制蛇的移动");
	SetPos(60, 20);
	printf("F3加速，F4减速，速度越快，得分越高");
	SetPos(60, 30);
	system("pause");
	system("cls");


}

void CreatMap()
{
	int i = 0;
	//上
	SetPos(0, 0);
	while (i <= 98)
	{
		wprintf(L"%c", WALL);
		i += 2;
	}
	//下
	SetPos(0, 29);
	i = 0;
	while (i <= 98)
	{
		wprintf(L"%c", WALL);
		i += 2;
	}
	//左
	i = 1;
	while (i <= 28)
	{
		SetPos(0, i);
		wprintf(L"%c", WALL);
		++i;
	}
	//右
	i = 1;
	while (i <= 28)
	{
		SetPos(98, i);
		wprintf(L"%c", WALL);
		++i;

	}
}

void CreatSnake(AllGame* game)
{

	//初始化五个节点作为蛇
	game->snake = (Snake*)malloc(sizeof(Snake));//第一节手动创建
	assert(game->snake);
	game->snake->next = NULL;
	game->snake->x = 2;
	game->snake->y = 1;
	game->lenth = 5;
	Snake* pcur = 0;
	for (int i = 0; i < 4; ++i)
	{
		pcur = (Snake*)malloc(sizeof(Snake));
		assert(pcur);
		pcur->next = game->snake;
		pcur->x = game->snake->x + 2;
		pcur->y = game->snake->y;
		game->snake = pcur;
	}
}

Snake* PrintSnake(AllGame* game)
{
	Snake* pcur = game->snake;
	while (pcur->next->next)
	{
		SetPos(pcur->x, pcur->y);
		wprintf(L"%c", BODY);
		pcur = pcur->next;
	}
	SetPos(pcur->x, pcur->y);//把尾节点的前一个节点位置保存，后面删尾用
	wprintf(L"%c", BODY);
	SetPos(pcur->next->x, pcur->next->y);
	wprintf(L"%c", BODY);
	return pcur;
}

void InitGame(AllGame* game)
{
	game->snake = NULL;
	game->score = 0;
	game->speed = 200;
	game->state = OK;
	game->food.YoN = false;
	game->dir = RIGHT;
	Welcom();
	CreatMap();
	CreatSnake(game);
	PrintSnake(game);
}

void SetFood(AllGame* game)
{
	//在地图范围内随机生成食物，
	//不能和地图重叠、不能生成在蛇上
	//生成的坐标位置必须在偶数点上
	srand(time(NULL));
	int x, y;
	again:
	do
	{
		x = rand() % 95 + 2;//能生成的坐标为2~96，所以取0~94 再 +2
		y = rand() % 28 + 1;//1~28
	} while (!(x % 2 == 0 && (x != 0 && x != 98 && y != 0 && y != 29)));
	//不能在蛇上
	Snake* pcur = game->snake;
	while (pcur)
	{
		if (x == pcur->x && y == pcur->y)
			goto again;
		pcur = pcur->next;
	}
	SetPos(x, y);
	game->food.x = x;
	game->food.y = y;
	game->food.YoN = true;
	wprintf(L"%c", FOOD);
}

void DisplayScore(AllGame* game)
{
	SetPos(115, 7);
	printf("当前得分为：%d", game->score);
	SetPos(115, 9);
	printf("您已经长到%d千米长了！", game->lenth);
	SetPos(115, 11);
	printf("按F3加速、F4减速！");
	SetPos(115, 13);
	printf("空格可以暂停和结束暂停！");
	SetPos(111, 15);
	printf("若游戏不动了可能是因为你按了空格!");
	SetPos(111, 19);
	printf("贪吃蛇的其他规则还需要我说？！");
} 

void jugdir(AllGame* game)
{
	if (GetAsyncKeyState(VK_UP) && game->dir != DOWN)
		game->dir = UP;
	if (GetAsyncKeyState(VK_DOWN) && game->dir != UP)
		game->dir = DOWN;
	if (GetAsyncKeyState(VK_LEFT) && game->dir != RIGHT)
		game->dir = LEFT;
	if (GetAsyncKeyState(VK_RIGHT) && game->dir != LEFT)
		game->dir = RIGHT;
}

bool jugfood(AllGame* game)
{
	if (game->dir == UP &&
		game->snake->x == game->food.x &&
		game->snake->y + 1 == game->food.y)
		return true;
	if (game->dir == DOWN &&
		game->snake->x == game->food.x &&
		game->snake->y - 1 == game->food.y)
		return true;
	if (game->dir == LEFT &&
		game->snake->x - 2 == game->food.x &&
		game->snake->y == game->food.y)
		return true;
	if (game->dir == RIGHT &&
		game->snake->x + 2 == game->food.x &&
		game->snake->y == game->food.y)
		return true;
	return false;
}


void MoveSnake(AllGame* game)
{
	jugdir(game);//判断当前移动方向
	//两种情况，下一步有食物和没食物
	//判断下一位置是否有食物
	Snake* preptail = NULL;
	if (jugfood(game))//若有食物，头插
	{
		Snake* new = (Snake*)malloc(sizeof(Snake));
		new->x = game->food.x;
		new->y = game->food.y;
		new->next = game->snake;
		game->snake = new;
		PrintSnake(game);
		SetFood(game);//吃掉再设置一个食物
	}
	else//若没有食物，头插，并将尾释放，并打印空格覆盖
	{
		Snake* new = (Snake*)malloc(sizeof(Snake));
		//修正方向
		switch(game->dir)
		{
		case UP:
			new->x = game->snake->x;
			new->y = game->snake->y - 1;
			break;
		case DOWN:
			new->x = game->snake->x;
			new->y = game->snake->y + 1;
			break;
		case LEFT:
			new->x = game->snake->x - 2;
			new->y = game->snake->y;
			break;
		case RIGHT:
			new->x = game->snake->x + 2;
			new->y = game->snake->y;
			break;
		}
		new->next = game->snake;
		game->snake = new;
		preptail = PrintSnake(game);
		SetPos(preptail->next->x, preptail->next->y);
		printf("  ");
		free(preptail->next);
		preptail->next = NULL;
	}
}	

void OtherFunc(AllGame* game)
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		do
		{
			Sleep(170);
		} while (!GetAsyncKeyState(VK_SPACE));
	}
	if (GetAsyncKeyState(VK_F3))
	{
		game->speed /= 2;
	}
	if (GetAsyncKeyState(VK_F4))
	{
		game->speed *= 2;
	}
}

int Suicide()
{
	;
}
void RunGame(AllGame* game)
{
	int state = OK;
	//得分设置，提示语等
	DisplayScore(game);
	do
	{
		//没有食物则设置食物
		if(game->food.YoN == false)
		SetFood(game);
		//蛇的移动：正常\吃到食物
		Sleep(game->speed);
		MoveSnake(game);
		//加速、减速、暂停 功能
		OtherFunc(game);
		//判输条件
		//Suicide(game);
	} while (game->state);
}