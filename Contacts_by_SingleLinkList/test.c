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
		case 1://添加联系人
			AddContact(&con);
			break;
		case 2://删除联系人
			DelContact(&con);
			break;
		case 3://修改联系人
			ModifyContact(&con);
			break;		
		case 4://查找联系人
			FindContact(con);
			break;
		case 5://查看通讯录
			ShowContact(con);
			break;
		case 0://退出
			printf("退出成功！\n");
			break;
		default:
			printf("不要乱输入！\n");
			break;
		}
	} while (opt);
	return 0;
}