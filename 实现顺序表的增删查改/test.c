#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"


int main()
{
	//����һ��˳�����ʼ��
	SL sl;
	SLInit(&sl);
	//����
	SLAddHead(&sl, 1);//1
	SLAddHead(&sl, 2);//21
	SLAddTail(&sl, 3);//213
	SLAddTail(&sl, 4);//2134
	//ɾ��
	//SLDelHead(&sl);//134
	//SLDelTail(&sl);//13
	//SLDelHead(&sl);//3
	//SLDelTail(&sl);// 
	//SLDelTail(&sl);//û�ж�������ɾ�ˣ�
	//ָ��λ��ɾ��
	SLDelPoint(&sl, 2);//214
	//�鿴һ������
	SLCheck(&sl, 2);//4
	//չʾ����˳���
	SLShow(&sl);//214
	//�޸�һ������
	SLRvise(&sl, 1, 5);//254
	SLShow(&sl);//254
	SLDelAll(&sl);
	return 0;
}