#define _CRT_SECURE_NO_WARNINGS

#include"contacts.h"


contact test1;

int main()
{
	//��ʼ��
	InitContact(&test1);
	int cos = 0;
	do
	{
		//��ӡ�˵�
		menu();
		scanf("%d", &cos);
		switch (cos)
		{
		case 1://�����ϵ��
			AddContact(&test1);
			break;
		case 2://ɾ����ϵ��
			DelContact(&test1);
			break;
		case 3://�޸���ϵ��
			ModifyContact(&test1);
			break;
		case 4://������ϵ��
			FindContact(&test1);
			break;
		case 5://�鿴ͨѶ¼
			ShowContact(&test1);
			break;
		case 0:
			printf("�˳��ɹ���");
			break;
		default:
			printf("������ѡ��");
			break;
		}
	} while (cos);
	return 0;
}