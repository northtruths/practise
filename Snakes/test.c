#define _CRT_SECURE_NO_WARNINGS

#include"Snakes.h"

int main()
{
	char ret = 0;
	do
	{
		//��Ϸʵ�����̣���ͷ���桢��ͼ���ߵĳ�ʼ���� ��Ϸ���й��̣� ��Ϸ�����ƺ��ͷš���ʾ�
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