#define _CRT_SECURE_NO_WARNINGS

#include"contacts.h"

//界面
void menu(void)
{
	printf("********************************************\n");
	printf("*******1.添加联系人******4.查找联系人*******\n");
	printf("*******2.删除联系人******5.查看通讯录*******\n");
	printf("*******3.修改联系人******0.退出*************\n");
	printf("********************************************\n");
}

//初始化通讯录
void InitContact(contact* con)
{
	con->size = 0;
	con->vol = 0;
	con->arr = NULL;
}

//扩容
void ConExpa(contact* con)
{
	int rea = con->vol;
	if (rea == 0)
		rea = 4;
	else
		rea *= 2;
	PeoInfo* temp = NULL;
	temp = (PeoInfo*)realloc(con->arr, sizeof(PeoInfo) * rea);
	if (temp == NULL)
	{
		perror("扩容失败！\n");
		return;
	}
	con->arr = temp;
	con->vol = rea;
}

//添加通讯录数据
void AddContact(contact* con)
{
	if (con->size == con->vol)
		ConExpa(con);
	printf("请依次输入你要添加联系人的名字、性别、电话和住址：\n");
	scanf("%s%s%s%s", con->arr[con->size].name, con->arr[con->size].sex, con->arr[con->size].tel, con->arr[con->size].addr);
	con->size++;
}

//删除通讯录
void DelContact(contact* con)
{
	if (con->size == 0)
	{
		printf("您根本没有联系人！\n");
		return;
	}
	printf("请输入你要删除的联系人的名字：\n");
	char temp[NAME_MAX] = { 0 };
	scanf("%s", temp);
	int pos = 0;
	for(pos = 0; pos < con->size; ++pos)
	{
		if (strcmp(temp, con->arr[pos].name) == 0)
		{
			//此时下标 pos 的位置即为要删除的位置
			memmove(con->arr + pos, con->arr + pos + 1, (con->size - (pos + 1)) * sizeof(PeoInfo));
			con->size--;
			return;
		}
	}
	printf("不存在此联系人！\n");
	return;
}

//展示通讯录数据
void ShowContact(contact* con)
{
	printf("名字    性别    电话    住址\n");
	int i = 0;
	for (i; i < con->size; ++i)
	{
		printf("%s    %s    %s    %s\n", con->arr[i].name, con->arr[i].sex, con->arr[i].tel, con->arr[i].addr);
	}
}

//查找联系人
void FindContact(contact* con)
{
	if (con->size == 0)
	{
		printf("您根本没有联系人！\n");
		return;
	}
	printf("请输入你要查找的联系人的名字：\n");
	char temp[NAME_MAX] = { 0 };
	scanf("%s", temp);
	int pos = 0;
	for (pos = 0; pos < con->size; ++pos)
	{
		if (strcmp(temp, con->arr[pos].name) == 0)
		{
			//此时下标 pos 的位置即为要查找的位置
			printf("找到了！\n");
			printf("%s    %s    %s    %s\n", con->arr[pos].name, con->arr[pos].sex, con->arr[pos].tel, con->arr[pos].addr);
			return;
		}
	}
	//找不到
	printf("不存在此联系人！\n");
	return;

}

//修改联系人
void ModifyContact(contact* con)
{
	printf("请输入你要修改的联系人的名字：\n");
	char temp[NAME_MAX] = { 0 };
	scanf("%s", temp);
	int pos = 0;
	for (pos = 0; pos < con->size; ++pos)
	{
		if (strcmp(temp, con->arr[pos].name) == 0)
		{
			//此时下标 pos 的位置即为要修改的位置
			printf("请输入你要修改的名字、性别、电话、住址：\n");
			scanf("%s%s%s%s", con->arr[pos].name, con->arr[pos].sex, con->arr[pos].tel, con->arr[pos].addr);
			printf("修改成功！\n");
			return;

		}
	}
	printf("不存在此联系人！\n");
	return;
}

//销毁通讯录

void DestroyContact(contact* con)
{
	con->size = 0;
	con->vol = 0;
	free(con->arr);
	con->arr = NULL;
}