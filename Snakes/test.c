#define _CRT_SECURE_NO_WARNINGS

#include"Snakes.h"

int main()
{
	AllGame game;
	//��Ϸʵ�����̣���ͷ���桢��ͼ���ߵĳ�ʼ���� ��Ϸ���й��̣� ��Ϸ�����ƺ��ͷš���ʾ�
	
	Prepare();

	InitGame(&game);

	RunGame(&game);
	//EndGame();
	
	return 0;
}