#pragma once
//#define row 9
//#define col 9
//#define rows row+2
//#define cols col+2
#include<stdio.h>

//��ʼ������
void initboard(char arr[29][29], int row, int col, char set);
//��ӡ����
void display(char arr[29][29], int row, int col);
//������
void setmine(char arr[29][29], int row, int col, int count);
//�Ų���
void findmine(char show[29][29], char mine[29][29], int row, int col, int count);