#pragma once
#include "common.h"
#include "string.h"
#include "menuarea.h"
//函数声明
// 
//打印栽种区域操作菜单
void printAreaMenu();
//区域菜单处理
enum MenuType ProcessAreaMenu(struct String *op);

//检测区域数量
int chectAreasNum(enum AreaUseState use);
//按编号查找区域
struct Area* findAreaByNo(struct String* s);
//按编号查找区域编号
int findAreaIndexByNo(struct String* s,enum AreaUseState use);

//显示所有区域 *
void showAreas();
//输入区域编号
//use:-1所有区域0不使用的区域1使用的区域
static int inputAreaNo(enum AreaUseState use);
//输入区域
static void inputArea(struct Area* pa);
//添加栽种区域
void addAreas();
//修改栽种区域
void modifyArea();
//删除区域
void deleteArea();


