#include "menuarea.h"
#include "ginkgo.h"
#include "string.h"
#include "common.h"

extern struct Ginkgo ginkgo;//外部声明

//打印栽种区域操作菜单
void printAreaMenu()
{
    printf("            银杏树栽种管理系统         \n");
    printf("*************栽种功能主菜单************\n");
    printf("*********** 1、显示所有区域 **********\n");
    printf("*********** 2、增加栽种区域 **********\n");
    printf("*********** 3、修改栽种区域 **********\n");
    printf("*********** 4、删除栽种区域 **********\n");
    printf("*********** 0、退出栽种区域管理 ******\n");
}
//菜单处理
enum MenuType ProcessAreaMenu(struct String *select)
{
    enum MenuType state = MENU_AREA;
    if (isEqualString(menuNames[1],select)) 
    {//显示所有区域
        showAreas();
    }
    else if (isEqualString(menuNames[2],select)) {//添加
        addAreas();
    }
    else if (isEqualString(menuNames[3],select)) {//修改
		if (chectAreasNum(AREA_ALL_STATE))
			modifyArea();
    }
    else if (isEqualString(menuNames[4],select)) {//删除
		if (chectAreasNum(AREA_USE_STATE))
			deleteArea();
		printf("区域不存在,请先配置栽种区域！！！");
    }
    else if (isEqualString(menuNames[0],select)) {//退出
        state = MENU_MAIN;
        printf("退出栽种区域管理，");
    }
    else
        printf("不支持的功能，请重选!");

    return state;
}

//检测区域数量
int chectAreasNum(enum AreaUseState use)
{
	int i = 0, n0 = 0, n1 = 0;	
	for (i = 0; i < ginkgo.anum; i++)
	{
		if (ginkgo.areas[i].useFlag == AREA_NOUSE_STATE)
		{
			n0++;
		}
		else if (ginkgo.areas[i].useFlag == AREA_USE_STATE)
		{
			n1++;
		}
	}
	if (use == AREA_NOUSE_STATE)
		return n0;
	else if (use == AREA_USE_STATE)
		return n1;

	return n0+n1;
}

//显示栽种区域
void showAreas()
{
	printf("栽种区域共 %d 个\n", ginkgo.anum  );
	for (int i = 0; i < ginkgo.anum; i++)
	{
		printf("%d %s %s %s\n",i , 
			ginkgo.areas[i].no, 
			ginkgo.areas[i].name, 
			areaUseStateNames[ginkgo.areas[i].useFlag]);
	}
}

//输入区域编号
static int inputAreaNo(enum AreaUseState use)
{
	int n = -1;
	if (!chectAreasNum(use))
		return n;
	struct Area a;
	while (TRUE)
	{
		printf("请输入栽种区域编号: ");
		gets(a.no.str);
		if ((n = findAreaIndexByNo(&a.no, use)) != -1)
			break;
		printf("请输入合法的编号!");
	}
	printf("%s %s\n", ginkgo.areas[n].no, ginkgo.areas[n].name);
	return n;
}

void inputArea(struct Area* pa)
{
	struct Area a;
	do {
		printf("请输入栽种区域编号: ");
		gets(a.no.str);
		if (findAreaByNo(&a.no) == NULL)//todo唯一性检查
		{
			break;
		}
		printf("编号已存在，请重新输入!\n");
	} while (1);
	printf("请输入栽种区域名称: ");
	gets(a.name.str);
	a.useFlag = 1;
	*pa = a;
}

//添加栽种区域
void addAreas()
{
	inputArea(&ginkgo.areas[ginkgo.anum]);//新增在尾部
	ginkgo.anum++;//栽种区域数量更新
}

//按编号查找区域
struct Area* findAreaByNo(struct String* s)
{
	int n;
	struct Area* p = NULL;
	for (n = 0; n < ginkgo.anum; n++) {
		p = &ginkgo.areas[n];
		if (isEqualString(s, &p->no) == TRUE)
			return p;
	}
	return NULL;
}

//按编号查找区域编号
int findAreaIndexByNo(struct String* s, enum AreaUseState use)
{
	int n;
	for (n = 0; n < ginkgo.anum; n++)
	{
		if (use != AREA_ALL_STATE)
		{
			if (ginkgo.areas[n].useFlag != use)
				continue;
		}
		
		if (isEqualString(s, &ginkgo.areas[n].no) == TRUE)
			return n;
	}
	return -1;
}

//修改栽种区域
void modifyArea()
{
	int n = 0;
	struct Area a;
	n = inputAreaNo(AREA_ALL_STATE);
	ginkgo.areas[n].no.str[0] = '\0';//将编号清空
	inputArea(&ginkgo.areas[n]);
}

//删除区域
void deleteArea()
{
	int n = -1,i = 0;

	//输入要删除的区域no
	n = inputAreaNo(AREA_USE_STATE);
	//判断区域是否在引用
	for (i = 0; i < ginkgo.tnum; i++)
	{
		if (n == ginkgo.trees[i].indexArea)
		{
			printf("该区域已被使用，不能删除!\n");
			//todo show tree
			return;
		}
	}
	////如果没有引用则删除
	//for (i = n + 1; i < ginkgo.anum; i++)
	//{
	//	ginkgo.areas[i - 1] = ginkgo.areas[i];//向前移
	//}
	ginkgo.areas[i].useFlag = 0;
	printf("删除成功!\n");
}

