#include "ginkgo.h"
#include "menutree.h"
#include "common.h"
#include "menuarea.h"
#include <stdio.h>

extern struct Ginkgo ginkgo;//外部声明

//打印栽种区域操作菜单
void printTreesMenu()
{
	printf("            银杏树管理系统          \n");
	printf("*************银杏树树木主菜单*******\n");
	printf("*********** 1、显示所有树木 ********\n");
	printf("*********** 2、增加树木   **********\n");
	printf("*********** 3、修改树木   **********\n");
	printf("*********** 4、删除树木   **********\n");
	printf("*********** 0、退出栽种树木管理 ****\n");
}
//菜单处理
//输入值：菜单选项
//返回值：菜单类型
enum MenuType ProcessTreesMenu(struct String* select)
{
	enum MenuType state = MENU_TREES;//当前处理菜单
	if (isEqualString(menuNames[1], select))
	{//显示所有树木
		showTrees();
	}
	else if (isEqualString(menuNames[2], select)) {//添加
		addTrees();
	}
	else if (isEqualString(menuNames[3], select)) {//修改
		modifyTree();
	}
	else if (isEqualString(menuNames[4], select)) {//删除
		deleteTree();
	}
	else if (isEqualString(menuNames[0], select)) {//退出
		state = MENU_MAIN;//返回主菜单
		printf("退出树木管理");
	}
	else
		printf("不支持的功能，请重选!");

	return state;
}

void inputTree(struct Tree* t)
{
	struct String no;
	printf("请输入编号(0000): ");
	gets(t->no.str); //编号不能重复
	printf("请输入栽种时间(2000 12 12): ");
	scanf("%d%d%d", &t->ztime.year, &t->ztime.month, &t->ztime.day);//日期格式检查
	while (TRUE)
	{
		printf("请输入栽种区域编号:");
		gets(no.str);
		if ((t->indexArea = findAreaIndexByNo(&no, AREA_USE_STATE)) != -1)
			break;
		printf("未找到栽种区域编号,请重新输入!");
	}
	printf("请输入树高: ");
	scanf("%f", &t->height);
	printf("请输入树腰围: ");
	scanf("%f", &t->perimeter);
	printf("请输入树龄(2000 12 12): ");
	scanf("%d%d%d", &t->age.year, &t->age.month, &t->age.day);
	t->state = STATE_LIVE;
	return t;
}

//录入一颗银杏树
void addTrees()
{
	if (ginkgo.tnum >= MAX_NUM_OF_TREES)
	{
		puts("数据达到上线1000,不能再录入数据!!!\n");
		return;
	}
	inputTree(&ginkgo.trees[ginkgo.tnum]);

	ginkgo.tnum++;
}
//显示一颗树
void showTree(struct Tree* t, int i)
{
	printf("%d %s %s %d-%d-%d %f %f %d-%d-%d %d\n",
		i,
		t->no,
		ginkgo.areas[t->indexArea].name.str,
		t->ztime.year, t->ztime.month, t->ztime.day,
		t->perimeter,
		t->height,
		t->age.year, t->age.month, t->age.day,
		t->state
	);
}

//显示所有银杏树
void showTrees()
{
	printf("共有银杏树 %d  颗\n", ginkgo.tnum);
	
	for (int i = 0; i < ginkgo.tnum; i++)
		showTree(&ginkgo.trees[i], i);
}

//查询：精确查找
//输入参数:需要查询的编号
//返回值：数组序号
int findTreeByNo(struct String *pno)
{
	struct String no;
	if (pno != NULL)
	{
		no = *pno;
	}
	if (isEmpty(&no))//如果没有输入，需要输入
	{
		puts("请输入银杏树编号: ");
		gets(no.str);
	}
	if (isEmpty(&no))
	{
		puts("无效的银杏树编号！");
		return -1;
	}
	for (int i = 0; i < ginkgo.tnum; i++)
	{
		if (isEqualString(&ginkgo.trees[i].no, &no)) {
			showTree(&ginkgo.trees[i], i);
			return i;
		}
	}
	printf("没查到银杏树!\n");
	return -1;
}
//模糊匹配查找Tree列表
int findTreesListByNo(struct String* pno)
{
	int n = 0;
	struct String no;
	no.str[0] = '\0';
	if (pno != NULL)
		no = *pno;
	if (isEmpty(&no))//如果没有输入，需要输入
	{
		puts("请输入银杏树编号: ");
		gets(no.str);
	}
	if (isEmpty(&no))
	{
		puts("无效的银杏树编号！\n");
		return -1;
	}
	for (int i = 0; i < ginkgo.tnum; i++)
	{
		if (stringMatchKey(&ginkgo.trees[i].no, &no)) {
			showTree(&ginkgo.trees[i], i);
			n++;
		}
	}
	printf("共查询到银杏树 %d 颗\n",n);
	return n;
}

//按地区模糊匹配查找Tree列表
int findTreesListByArea(struct String* pno)
{
	printf("该功能未实现，请重选!\n");
}
//按树龄匹配查找Tree列表
int findTreesListByAge()
{
	printf("该功能未实现，请重选!\n");
}
//修改
//todo
void modifyTree()
{
	printf("该功能未实现，请重选!\n");
}

//删除
void deleteTree()
{
	int index = findTreeByNo(NULL);//查询需要删除的树
	if (index > 0)
	{
		for (int i = index + 1; i < ginkgo.tnum; i++)//将后面的数据向前移动
			ginkgo.trees[i - 1] = ginkgo.trees[i];
		ginkgo.tnum--;//更新树木总数
		if (ginkgo.tnum < 0)
			ginkgo.tnum = 0;
		printf("删除成功\n");
	}
}
