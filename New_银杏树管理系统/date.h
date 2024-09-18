#pragma once
#include "string.h"

struct Date
{
	int year;//年
	int month;//月
	int day;//日
};
//用指针作为参数，避免内存拷贝，从而提高运行效率
void initDate(struct Date* p);
