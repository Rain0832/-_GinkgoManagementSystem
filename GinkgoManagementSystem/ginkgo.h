#pragma once
#include "tree.h"

#define MAX_NUM_OF_TREES  1000//最多录入数的数量
#define MAX_NUM_OF_AREAS  100
#define FILE_CODE "Ginkgo"

//银杏树
struct Ginkgo
{
	struct Tree trees[MAX_NUM_OF_TREES];//银杏树数组	
	int tnum;              //银杏树数量

	struct Area areas[MAX_NUM_OF_AREAS];     //栽种区域名称
	int anum;              //区域数量

	int bmodify;              //是否发生了修改1修改

	struct String filename;
};

//用指针作为参数，避免内存拷贝，从而提高运行效率
void initGinkgo(struct Ginkgo *p);

//保存
void save(struct Ginkgo *g);
//打开文件
void open(struct Ginkgo *g);

