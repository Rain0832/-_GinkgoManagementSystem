#pragma once
#include "string.h"

enum AreaUseState {AREA_NOUSE_STATE=0, AREA_USE_STATE =1,AREA_ALL_STATE=2,
};
struct Area
{
	struct String no;
	struct String name;
	int useFlag;//删除标志0删除1使用
};
extern char* areaUseStateNames[];
//用指针作为参数，避免内存拷贝，从而提高运行效率
void initArea(struct Area *p);


