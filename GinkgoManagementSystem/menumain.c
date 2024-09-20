#include<stdio.h>
#include "menumain.h"
#include "menutree.h"
#include "ginkgo.h"

extern struct Ginkgo ginkgo;//外部声明
extern struct Ginkgo* pginkgo;
void printMainMenu()
{
    printf("********************************************\n");
    printf("**             银杏树管理系统             **\n");
    printf("**                                        **\n");
    printf("**              功能主菜单                **\n");
    printf("**          1、显示银杏树列表             **\n");
    printf("**          2、输入编号查询银杏树         **\n");
    printf("**          3、修改银杏树信息             **\n");
    printf("**          4、输入编号删除银杏树         **\n");
    printf("**          5、保存银杏树信息文本文件     **\n");
    printf("**          6、打开银杏树信息文本文件     **\n");
    printf("**          7、统计各区域内银杏树         **\n");
    printf("**          8、统计各树龄银杏树           **\n");
    printf("**          9、银杏树信息管理             **\n");
    printf("**         10、银杏树栽种区域管理         **\n");
    printf("**          0、退出系统                   **\n");
    printf("**                                        **\n");
    printf("**    说明：请输入选项对应数字以进入选项。**\n");
    printf("********************************************\n");
}

enum MenuType ProcessMainMenu(struct String *select)
{
    enum MenuType state = MENU_MAIN;

    if (isEqualString(menuNames[0], select)  ||
        isEqualString(menuNames[21], select) ||
        isEqualString(menuNames[22], select) ||
        isEqualString(menuNames[23], select) ||
        isEqualString(menuNames[24], select) ||
        isEqualString(menuNames[25], select))
    {
        if (ginkgo.bmodify == 1)
        {
            struct String temp;
            printf("文件已发生修改,是否保存（y:保存，n:不保存）: ");
            gets(temp.str);
            if (temp.str[0] == 'y' || temp.str[0] == 'Y')
                save(pginkgo);
        }
        exit(0);
    }
    else if (isEqualString(menuNames[1], select)) {
        showTrees();
    }
    else if (isEqualString(menuNames[2], select)) {//find trees
        findTreesListByNo(NULL);
    }
    else if (isEqualString(menuNames[3], select)) {//修改
        modifyTree();
    }
    else if (isEqualString(menuNames[4], select)) {//删除
        deleteTree();
    }
    else if (isEqualString(menuNames[5], select))
    {
        save(pginkgo);
    }
    else if (isEqualString(menuNames[6], select))
    {        
        open(pginkgo);
    }
    else if (isEqualString(menuNames[7], select)) {
        findTreesListByArea(NULL);//todo
    }
    else if (isEqualString(menuNames[8], select)) {
        findTreesListByAge();
    }
    else if (isEqualString(menuNames[9], select)) {
        if (chectAreasNum(pginkgo))
            state = MENU_TREES;
    }
    else if (isEqualString(menuNames[10], select)) {
        state = MENU_AREA;
        printf("进入栽种区域管理\n");
    }
    else
        printf("不支持的功能，请重选!\n");

    return state;
}

