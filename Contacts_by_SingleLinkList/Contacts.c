#define _CRT_SECURE_NO_WARNINGS

#include"Contacts.h"

//����
void menu(void)
{
	printf("********************************************\n");
	printf("*******1.�����ϵ��******4.������ϵ��*******\n");
	printf("*******2.ɾ����ϵ��******5.�鿴ͨѶ¼*******\n");
	printf("*******3.�޸���ϵ��******0.�˳�*************\n");
	printf("********************************************\n");
}

struct SListNode
{
	PeoInfo peo;
	contact* next;
};

//�ڵ�Ĵ�������ʼ��
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

//��ʼ��ͨѶ¼
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

//����ͨѶ¼����(ָ������)
void FindContact(contact* con)
{
	if (con == NULL)
	{
		printf("����û����ϵ�ˣ�\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("��������Ҫ���ҵ�������");
	scanf("%s", name);
	contact* pcur = con->next;
	while (pcur && strcmp(pcur->peo.name, name) != 0)
	{
		pcur = pcur->next;
	}
	//��ʱ pcur λ��ҪôΪĿ��λ�ã�Ҫôû�ҵ�Ϊβ��ָ��
	if (pcur == NULL)
	{
		printf("�����ڴ���ϵ�ˣ�\n");
		return;
	}
	else
	{
		printf("�ҵ��ˣ�\n");
		printf("����    �Ա�    ����    �绰    סַ\n");
		printf("%s    %s    %d    %s    %s    \n", pcur->peo.name, pcur->peo.sex, pcur->peo.age, pcur->peo.tel, pcur->peo.addr);
	}

}

//���ͨѶ¼����(β��ʵ��)
void AddContact(contact** con)
{
	contact* pcur = *con;
	while (pcur != NULL && pcur->next != NULL)
	{
		pcur = pcur->next;
	}
	//��ʱ pcur λ��Ϊβ
	contact* newnode = NodeCreat(&pcur);
	printf("���������������ϵ�˵����֡��Ա����䡢�绰��סַ��\n");
	scanf("%s %s %d %s %s", newnode->peo.name, newnode->peo.sex, &newnode->peo.age, newnode->peo.tel, newnode->peo.addr);
}

//ɾ��ͨѶ¼����(ָ������)
void DelContact(contact** con)
{
	if (*con == NULL)
	{
		printf("������û����ϵ�ˣ�\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("��������Ҫɾ����������\n");
	scanf("%s", name);
	contact* pcur = *con;
	contact* prev = NULL;
	while (pcur && strcmp(pcur->peo.name, name) != 0)
	{
		prev = pcur;
		pcur = pcur->next;
	}
	//��ʱ pcur λ��ҪôΪĿ��λ�ã�Ҫôû�ҵ�Ϊβ����Ŀ�ָ��
	if (pcur == NULL)
	{
		printf("�����ڴ���ϵ�ˣ�\n");
		return;
	}
	else if(pcur == *con)//ͷɾ
	{
		*con = (*con)->next;
		free(pcur);
		pcur = NULL;
		printf("ɾ���ɹ���\n");
	}
	else
	{
		prev->next = pcur->next;
		free(pcur);
		pcur = NULL;
		printf("ɾ���ɹ���\n");
	}
}

//չʾͨѶ¼����
void ShowContact(contact* con)
{
	if (con == NULL)
	{
		printf("ɶҲû���㿴���ӣ�\n");
		return;
	}
	contact* pcur = con->next;
	printf("����    �Ա�    ����    �绰    סַ\n");
	while (pcur)
	{
		printf("%s    %s    %d    %s    %s\n", pcur->peo.name, pcur->peo.sex, pcur->peo.age, pcur->peo.tel, pcur->peo.addr);
		pcur = pcur->next;
	}
}

//�޸�ͨѶ¼����
void ModifyContact(contact** con)
{
	if (*con == NULL)
	{
		printf("������û����ϵ�ˣ�\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("��������Ҫ�޸ĵ���ϵ�ˣ�\n");
	scanf("%s", name);
	contact* pcur = *con;
	while (pcur && strcmp(pcur->peo.name, name) != 0)
	{
		pcur = pcur->next;
	}
	//��ʱ pcur λ��ҪôΪĿ��λ�ã�Ҫôû�ҵ�Ϊβ����Ŀ�ָ��
	if (pcur == NULL)
	{
		printf("�����ڴ���ϵ�ˣ�\n");
		return;
	}
	else
	{
		printf("����������Ҫ�޸ĵ����֡��Ա����䡢�绰��סַ��\n");
		scanf("%s %s %d %s %s", pcur->peo.name, pcur->peo.sex, &pcur->peo.age, pcur->peo.tel, pcur->peo.addr);
		printf("�޸ĳɹ���\n");
	}
}