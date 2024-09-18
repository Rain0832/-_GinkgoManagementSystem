#pragma once
#include "tree.h"
//函数声明
// 
//打印栽种区域操作菜单
void printTreesMenu();
//菜单处理
enum MenuType ProcessTreesMenu(struct String* select);

//输入一颗树，内部调用
void inputTree(struct Tree* t);
//录入一颗银杏树,外部调用
void addTrees();
//显示一颗树，内部调用
void showTree(struct Tree* t, int i);
//显示所有银杏树,外部调用
void showTrees();

//查询
//输入参数:需要查询的编号
//返回值：数组序号
int findTreeByNo(struct String* pno);
//按编号模糊匹配查找Tree列表
int findTreesListByNo(struct String* pno);
//按地区模糊匹配查找Tree列表
int findTreesListByArea(struct String* pno);
//按树龄匹配查找Tree列表
int findTreesListByAge();
//修改
void modifyTree();
//删除
void deleteTree();