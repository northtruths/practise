#define _CRT_SECURE_NO_WARNINGS

#include"Contacts.h"

int main()
{
	contact* con = NULL;
	InitContact(&con);

	int opt = 0;
	do
	{
		menu();
		scanf("%d", &opt);
		switch (opt)
		{
		case 1://�����ϵ��
			AddContact(&con);
			break;
		case 2://ɾ����ϵ��
			DelContact(&con);
			break;
		case 3://�޸���ϵ��
			ModifyContact(&con);
			break;		
		case 4://������ϵ��
			FindContact(con);
			break;
		case 5://�鿴ͨѶ¼
			ShowContact(con);
			break;
		case 0://�˳�
			printf("�˳��ɹ���\n");
			break;
		default:
			printf("��Ҫ�����룡\n");
			break;
		}
	} while (opt);
	return 0;
}