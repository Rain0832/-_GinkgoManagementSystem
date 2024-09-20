//GinkgoManagementSystem.c : 此源文件文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include "common.h"
#include "ginkgo.h"
#include "menuarea.h"
#include "menumain.h"
#include "menutree.h"

//这是一个银杏树管理系统，能实现下面的各种功能：
//1、录入银杏树信息（编号 栽种地区 栽种时间 高 腰 树龄 是否存活）；
//2、按编号查询；
//3、修改信息；
//4、按编号删除；
//5、保存文件；
//6、打开文件；
//7、按地区统计；
//8、按树龄统计；
//0、退出系统

extern struct Ginkgo ginkgo;//外部声明

int main()
{
    enum MenuType state = MENU_MAIN;
    struct String select;
    //初始化
    initGinkgo(&ginkgo);
    
    while (1)
    {
        if (MENU_MAIN == state)
            printMainMenu();
        else if (MENU_TREES == state)
        {
            printTreesMenu();
        }
        else
        {
            printAreaMenu();
        }
        printf(  "请输入菜单选项: ");
        gets(select.str);

        if (MENU_MAIN == state)//主菜单处理
        {
            state = ProcessMainMenu(&select);
        }
        else if (MENU_TREES == state)//主菜单处理
        {
            state = ProcessTreesMenu(&select);
        }
        else //区域管理菜单处理
        {
            state = ProcessAreaMenu(&select);
        }
       
        system("pause");        //页面暂停，提示：按任意键继续
        system("cls");          //清屏并生成新的菜单
    }
    return 0;
}