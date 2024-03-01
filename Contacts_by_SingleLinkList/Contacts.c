#define _CRT_SECURE_NO_WARNINGS

#include"Contacts.h"

//界面
void menu(void)
{
	printf("********************************************\n");
	printf("*******1.添加联系人******4.查找联系人*******\n");
	printf("*******2.删除联系人******5.查看通讯录*******\n");
	printf("*******3.修改联系人******0.退出*************\n");
	printf("********************************************\n");
}

struct SListNode
{
	PeoInfo peo;
	contact* next;
};

//节点的创建并初始化
contact* NodeCreat(contact** pprev)
{
	if (*pprev == NULL)
	{
		*pprev = (contact*)malloc(sizeof(contact));
		(*pprev)->next = NULL;
		memset((*pprev)->peo.name, ' ', NAME_MAX);
		memset((*pprev)->peo.sex, ' ', SEX_MAX);
		(*pprev)->peo.age = 0;
		memset((*pprev)->peo.tel, ' ', TEL_MAX);
		memset((*pprev)->peo.addr, ' ', ADDR_MAX);
		return *pprev;
	}
	contact* newnode = (contact*)malloc(sizeof(contact));
	(*pprev)->next = newnode;
	newnode->next = NULL;
	return newnode;
}

//初始化通讯录
void InitContact(contact** con)
{
	if (*con == NULL)
	{
		NodeCreat(con);

		return;
	}
	else
	{
		*con = (contact*)malloc(sizeof(contact));
		memset((*con)->peo.name, ' ', NAME_MAX);
		memset((*con)->peo.sex, ' ', SEX_MAX);
		(*con)->peo.age = 0;
		memset((*con)->peo.tel, ' ', TEL_MAX);
		memset((*con)->peo.addr, ' ', ADDR_MAX);
	}
}

//查找通讯录数据(指定人名)
void FindContact(contact* con)
{
	if (con == NULL)
	{
		printf("您并没有联系人！\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("请输入你要查找的人名：");
	scanf("%s", name);
	contact* pcur = con->next;
	while (pcur && strcmp(pcur->peo.name, name) != 0)
	{
		pcur = pcur->next;
	}
	//此时 pcur 位置要么为目标位置，要么没找到为尾空指针
	if (pcur == NULL)
	{
		printf("不存在此联系人！\n");
		return;
	}
	else
	{
		printf("找到了！\n");
		printf("名字    性别    年龄    电话    住址\n");
		printf("%s    %s    %d    %s    %s    \n", pcur->peo.name, pcur->peo.sex, pcur->peo.age, pcur->peo.tel, pcur->peo.addr);
	}

}

//添加通讯录数据(尾插实现)
void AddContact(contact** con)
{
	contact* pcur = *con;
	while (pcur != NULL && pcur->next != NULL)
	{
		pcur = pcur->next;
	}
	//此时 pcur 位置为尾
	contact* newnode = NodeCreat(&pcur);
	printf("请依次输入添加联系人的名字、性别、年龄、电话、住址。\n");
	scanf("%s %s %d %s %s", newnode->peo.name, newnode->peo.sex, &newnode->peo.age, newnode->peo.tel, newnode->peo.addr);
}

//删除通讯录数据(指定姓名)
void DelContact(contact** con)
{
	if (*con == NULL)
	{
		printf("您根本没有联系人！\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("请输入你要删除的人名：\n");
	scanf("%s", name);
	contact* pcur = *con;
	contact* prev = NULL;
	while (pcur && strcmp(pcur->peo.name, name) != 0)
	{
		prev = pcur;
		pcur = pcur->next;
	}
	//此时 pcur 位置要么为目标位置，要么没找到为尾后面的空指针
	if (pcur == NULL)
	{
		printf("不存在此联系人！\n");
		return;
	}
	else if(pcur == *con)//头删
	{
		*con = (*con)->next;
		free(pcur);
		pcur = NULL;
		printf("删除成功！\n");
	}
	else
	{
		prev->next = pcur->next;
		free(pcur);
		pcur = NULL;
		printf("删除成功！\n");
	}
}

//展示通讯录数据
void ShowContact(contact* con)
{
	if (con == NULL)
	{
		printf("啥也没有你看锤子！\n");
		return;
	}
	contact* pcur = con->next;
	printf("名字    性别    年龄    电话    住址\n");
	while (pcur)
	{
		printf("%s    %s    %d    %s    %s\n", pcur->peo.name, pcur->peo.sex, pcur->peo.age, pcur->peo.tel, pcur->peo.addr);
		pcur = pcur->next;
	}
}

//修改通讯录数据
void ModifyContact(contact** con)
{
	if (*con == NULL)
	{
		printf("您根本没有联系人！\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("请输入你要修改的联系人：\n");
	scanf("%s", name);
	contact* pcur = *con;
	while (pcur && strcmp(pcur->peo.name, name) != 0)
	{
		pcur = pcur->next;
	}
	//此时 pcur 位置要么为目标位置，要么没找到为尾后面的空指针
	if (pcur == NULL)
	{
		printf("不存在此联系人！\n");
		return;
	}
	else
	{
		printf("请依次输入要修改的名字、性别、年龄、电话、住址。\n");
		scanf("%s %s %d %s %s", pcur->peo.name, pcur->peo.sex, &pcur->peo.age, pcur->peo.tel, pcur->peo.addr);
		printf("修改成功！\n");
	}
}