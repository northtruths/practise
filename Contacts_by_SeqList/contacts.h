#pragma once
#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//ǰ������


typedef struct SeqList contact;

//�û�����

typedef struct PersonInfo

{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//ͨѶ¼��ʽ
struct SeqList
{
	PeoInfo* arr;
	int size;
	int vol;
};

//��ʼ��ͨѶ¼

void InitContact(contact* con);

//���ͨѶ¼����

void AddContact(contact* con);

//ɾ��ͨѶ¼����

void DelContact(contact* con);

//չʾͨѶ¼����

void ShowContact(contact* con);

//����ͨѶ¼����

void FindContact(contact* con);

//�޸�ͨѶ¼����

void ModifyContact(contact* con);

//����ͨѶ¼����

void DestroyContact(contact* con);

//�˵�����
void menu(void);

//����
void ConExpa(contact* con);