#pragma once
//#define row 9
//#define col 9
//#define rows row+2
//#define cols col+2
#include<stdio.h>

//³õÊ¼»¯ÆåÅÌ
void initboard(char arr[29][29], int row, int col, char set);
//´òÓ¡ÆåÅÌ
void display(char arr[29][29], int row, int col);
//²¼ÖÃÀ×
void setmine(char arr[29][29], int row, int col, int count);
//ÅÅ²éÀ×
void findmine(char show[29][29], char mine[29][29], int row, int col, int count);