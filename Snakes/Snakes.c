#define _CRT_SECURE_NO_WARNINGS

#include"Snakes.h"

void Prepare()
{
	//��ȡ������Ϣ��ʹ���ǵ�һЩ���ķ��ſ��ԺϷ�ʹ�ã����ã�
	setlocale(LC_ALL, "");
	//���������������
	CONSOLE_CURSOR_INFO curinfo;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(handle, &curinfo);
	curinfo.bVisible = false;
	SetConsoleCursorInfo(handle, &curinfo);
	//�ѿ���̨��Ϊ150��40�� ����100 �� ��30 ��������ͼ
	system("mode con cols=150 lines=40");
}

void SetPos(short x, short y)//���ù�������
{
	COORD pos = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}


void Welcom()
{
	SetPos(60, 18);
	printf("��ӭ����̰������Ϸ");
	SetPos(60, 30);
	system("pause");
	system("cls");
	SetPos(60, 18);
	printf("�� �� �� �� �����ߵ��ƶ�");
	SetPos(60, 20);
	printf("F3���٣�F4���٣��ٶ�Խ�죬�÷�Խ��");
	SetPos(60, 30);
	system("pause");
	system("cls");


}

void CreatMap()
{
	int i = 0;
	//��
	SetPos(0, 0);
	while (i <= 98)
	{
		wprintf(L"%c", WALL);
		i += 2;
	}
	//��
	SetPos(0, 29);
	i = 0;
	while (i <= 98)
	{
		wprintf(L"%c", WALL);
		i += 2;
	}
	//��
	i = 1;
	while (i <= 28)
	{
		SetPos(0, i);
		wprintf(L"%c", WALL);
		++i;
	}
	//��
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

	//��ʼ������ڵ���Ϊ��
	game->snake = (Snake*)malloc(sizeof(Snake));//��һ���ֶ�����
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
	SetPos(pcur->x, pcur->y);//��β�ڵ��ǰһ���ڵ�λ�ñ��棬����ɾβ��
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
	//�ڵ�ͼ��Χ���������ʳ�
	//���ܺ͵�ͼ�ص�����������������
	//���ɵ�����λ�ñ�����ż������
	srand(time(NULL));
	int x, y;
	again:
	do
	{
		x = rand() % 95 + 2;//�����ɵ�����Ϊ2~96������ȡ0~94 �� +2
		y = rand() % 28 + 1;//1~28
	} while (!(x % 2 == 0 && (x != 0 && x != 98 && y != 0 && y != 29)));
	//����������
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
	printf("��ǰ�÷�Ϊ��%d", game->score);
	SetPos(115, 9);
	printf("���Ѿ�����%dǧ�׳��ˣ�", game->lenth);
	SetPos(115, 11);
	printf("��F3���١�F4���٣�");
	SetPos(115, 13);
	printf("�ո������ͣ�ͽ�����ͣ��");
	SetPos(111, 15);
	printf("����Ϸ�����˿�������Ϊ�㰴�˿ո�!");
	SetPos(111, 19);
	printf("̰���ߵ�����������Ҫ��˵����");
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
	jugdir(game);//�жϵ�ǰ�ƶ�����
	//�����������һ����ʳ���ûʳ��
	//�ж���һλ���Ƿ���ʳ��
	Snake* preptail = NULL;
	if (jugfood(game))//����ʳ�ͷ��
	{
		Snake* new = (Snake*)malloc(sizeof(Snake));
		new->x = game->food.x;
		new->y = game->food.y;
		new->next = game->snake;
		game->snake = new;
		PrintSnake(game);
		SetFood(game);//�Ե�������һ��ʳ��
	}
	else//��û��ʳ�ͷ�壬����β�ͷţ�����ӡ�ո񸲸�
	{
		Snake* new = (Snake*)malloc(sizeof(Snake));
		//��������
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
	//�÷����ã���ʾ���
	DisplayScore(game);
	do
	{
		//û��ʳ��������ʳ��
		if(game->food.YoN == false)
		SetFood(game);
		//�ߵ��ƶ�������\�Ե�ʳ��
		Sleep(game->speed);
		MoveSnake(game);
		//���١����١���ͣ ����
		OtherFunc(game);
		//��������
		//Suicide(game);
	} while (game->state);
}