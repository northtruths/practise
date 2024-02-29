#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"


int main()
{
	//创建一个顺序表并初始化
	SL sl;
	SLInit(&sl);
	//增添
	SLAddHead(&sl, 1);//1
	SLAddHead(&sl, 2);//21
	SLAddTail(&sl, 3);//213
	SLAddTail(&sl, 4);//2134
	//删减
	//SLDelHead(&sl);//134
	//SLDelTail(&sl);//13
	//SLDelHead(&sl);//3
	//SLDelTail(&sl);// 
	//SLDelTail(&sl);//没有东西可以删了！
	//指定位置删减
	SLDelPoint(&sl, 2);//214
	//查看一个数据
	SLCheck(&sl, 2);//4
	//展示整个顺序表
	SLShow(&sl);//214
	//修改一个数据
	SLRvise(&sl, 1, 5);//254
	SLShow(&sl);//254
	SLDelAll(&sl);
	return 0;
}