#define _CRT_SECURE_NO_WARNINGS

#include"contacts.h"

//����
void menu(void)
{
	printf("********************************************\n");
	printf("*******1.�����ϵ��******4.������ϵ��*******\n");
	printf("*******2.ɾ����ϵ��******5.�鿴ͨѶ¼*******\n");
	printf("*******3.�޸���ϵ��******0.�˳�*************\n");
	printf("********************************************\n");
}

//��ʼ��ͨѶ¼
void InitContact(contact* con)
{
	con->size = 0;
	con->vol = 0;
	con->arr = NULL;
}

//����
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
		perror("����ʧ�ܣ�\n");
		return;
	}
	con->arr = temp;
	con->vol = rea;
}

//���ͨѶ¼����
void AddContact(contact* con)
{
	if (con->size == con->vol)
		ConExpa(con);
	printf("������������Ҫ�����ϵ�˵����֡��Ա𡢵绰��סַ��\n");
	scanf("%s%s%s%s", con->arr[con->size].name, con->arr[con->size].sex, con->arr[con->size].tel, con->arr[con->size].addr);
	con->size++;
}

//ɾ��ͨѶ¼
void DelContact(contact* con)
{
	if (con->size == 0)
	{
		printf("������û����ϵ�ˣ�\n");
		return;
	}
	printf("��������Ҫɾ������ϵ�˵����֣�\n");
	char temp[NAME_MAX] = { 0 };
	scanf("%s", temp);
	int pos = 0;
	for(pos = 0; pos < con->size; ++pos)
	{
		if (strcmp(temp, con->arr[pos].name) == 0)
		{
			//��ʱ�±� pos ��λ�ü�ΪҪɾ����λ��
			memmove(con->arr + pos, con->arr + pos + 1, (con->size - (pos + 1)) * sizeof(PeoInfo));
			con->size--;
			return;
		}
	}
	printf("�����ڴ���ϵ�ˣ�\n");
	return;
}

//չʾͨѶ¼����
void ShowContact(contact* con)
{
	printf("����    �Ա�    �绰    סַ\n");
	int i = 0;
	for (i; i < con->size; ++i)
	{
		printf("%s    %s    %s    %s\n", con->arr[i].name, con->arr[i].sex, con->arr[i].tel, con->arr[i].addr);
	}
}

//������ϵ��
void FindContact(contact* con)
{
	if (con->size == 0)
	{
		printf("������û����ϵ�ˣ�\n");
		return;
	}
	printf("��������Ҫ���ҵ���ϵ�˵����֣�\n");
	char temp[NAME_MAX] = { 0 };
	scanf("%s", temp);
	int pos = 0;
	for (pos = 0; pos < con->size; ++pos)
	{
		if (strcmp(temp, con->arr[pos].name) == 0)
		{
			//��ʱ�±� pos ��λ�ü�ΪҪ���ҵ�λ��
			printf("�ҵ��ˣ�\n");
			printf("%s    %s    %s    %s\n", con->arr[pos].name, con->arr[pos].sex, con->arr[pos].tel, con->arr[pos].addr);
			return;
		}
	}
	//�Ҳ���
	printf("�����ڴ���ϵ�ˣ�\n");
	return;

}

//�޸���ϵ��
void ModifyContact(contact* con)
{
	printf("��������Ҫ�޸ĵ���ϵ�˵����֣�\n");
	char temp[NAME_MAX] = { 0 };
	scanf("%s", temp);
	int pos = 0;
	for (pos = 0; pos < con->size; ++pos)
	{
		if (strcmp(temp, con->arr[pos].name) == 0)
		{
			//��ʱ�±� pos ��λ�ü�ΪҪ�޸ĵ�λ��
			printf("��������Ҫ�޸ĵ����֡��Ա𡢵绰��סַ��\n");
			scanf("%s%s%s%s", con->arr[pos].name, con->arr[pos].sex, con->arr[pos].tel, con->arr[pos].addr);
			printf("�޸ĳɹ���\n");
			return;

		}
	}
	printf("�����ڴ���ϵ�ˣ�\n");
	return;
}

//����ͨѶ¼

void DestroyContact(contact* con)
{
	con->size = 0;
	con->vol = 0;
	free(con->arr);
	con->arr = NULL;
}