#pragma once
#include "string.h"
#include "date.h"
#include "area.h"

enum StateTree {STATE_DEATH = 0, STATE_LIVE = 1,STATE_UNKOWN = 2,
};
//银杏树信息（编号 栽种地区 栽种时间 高 腰 树龄 是否存活）
struct Tree
{
	struct String no;
	int indexArea;//所在区域序号,区域不会被物理删除，所以可以用数组下标
	struct Date ztime;
	float height;
	float perimeter;
	struct Date age;
	enum StateTree state;//1存活
};
//用指针作为参数，避免内存拷贝，从而提高运行效率
void initTree(struct Tree *p);