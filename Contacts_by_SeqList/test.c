#define _CRT_SECURE_NO_WARNINGS

#include"contacts.h"


contact test1;

int main()
{
	//初始化
	InitContact(&test1);
	int cos = 0;
	do
	{
		//打印菜单
		menu();
		scanf("%d", &cos);
		switch (cos)
		{
		case 1://添加联系人
			AddContact(&test1);
			break;
		case 2://删除联系人
			DelContact(&test1);
			break;
		case 3://修改联系人
			ModifyContact(&test1);
			break;
		case 4://查找联系人
			FindContact(&test1);
			break;
		case 5://查看通讯录
			ShowContact(&test1);
			break;
		case 0:
			printf("退出成功！");
			break;
		default:
			printf("请重新选择！");
			break;
		}
	} while (cos);
	return 0;
}