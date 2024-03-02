#pragma once
//contact.h
#pragma once
#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ǰ������
typedef struct SListNode contact;

//�û�����
typedef struct PersonInfo
{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    int age;
    char tel[TEL_MAX];
    char addr[ADDR_MAX];
}PeoInfo;

//��ʼ��ͨѶ¼
void InitContact(contact** con);
//����ͨѶ¼����
void AddContact(contact** con);
//ɾ��ͨѶ¼����
void DelContact(contact** con);
//չʾͨѶ¼����
void ShowContact(contact* con);
//����ͨѶ¼����
void FindContact(contact* con);
//�޸�ͨѶ¼����
void ModifyContact(contact** con);
//����ͨѶ¼����
void DestroyContact(contact** con);
//����
void menu(void);
//�ڵ�Ĵ���
contact* NodeCreat(contact* prev);