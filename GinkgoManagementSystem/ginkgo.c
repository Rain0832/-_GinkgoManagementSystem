#include "ginkgo.h"
#include "common.h"
#include  <stdio.h>
#include  <stdlib.h>

struct Ginkgo ginkgo;//声明全局变量
struct Ginkgo* pginkgo = &ginkgo;

void initGinkgo(struct Ginkgo* p)
{
	p->tnum = 0;              //银杏树数量
	p->anum = 0;              //区域数量
	p->bmodify = 0;              //未修改
	p->filename.str[0] = '\0';
}

//保存
void save(struct Ginkgo* g)
{
    struct String filename = g->filename;
    //判断文件名是否存在
    if (isEmpty(&filename))
    {
        printf("请输入文件名: ");
        gets(filename.str);
    }
   
    if (isEmpty(&filename))
    {
        printf("文件名为空不能保存!");
        return;
    }
    //// 1.包含头文件
    //// 2.创建流对象
    FILE* fp = NULL;
    //// 3.指定打开的方式    
    fp = fopen(filename.str, "w+");
    if (fp == NULL)
    {
        printf("创建文件失败，保存不成功!");
        return;
    }
    //// 4.写内容
    fprintf(fp, "%s\n", FILE_CODE);//文件格式标记
    fprintf(fp, "%d\n",g->anum);//保存区域数
    for(int i = 0; i < g->anum; i++)//保存区域
        fprintf(fp, "%s %s %d\n", g->areas[i].no.str, g->areas[i].name.str, g->areas[i].useFlag);
    fprintf(fp, "%d\n", g->tnum);//保存树数
    for (int i = 0; i < g->tnum; i++) {
        fprintf(fp, "%s %d %d %d %d %f %f %d %d %d %d\n",
            g->trees[i].no.str,
            g->trees[i].indexArea,
            g->trees[i].ztime.year, g->trees[i].ztime.month, g->trees[i].ztime.day,
            g->trees[i].height,
            g->trees[i].perimeter,
            g->trees[i].age.year, g->trees[i].age.month, g->trees[i].age.day,
            g->trees[i].state);
    }
    //// 5.关闭文件
    fclose(fp);
    printf("文件保存成功!\n");
    g->bmodify = FALSE;

    g->filename = filename;
}

//打开文件
void open(struct Ginkgo* g)
{
    struct String temp;
    
    struct String filename = g->filename;
    //判断文件名是否存在
    if (isEmpty(&filename))
    {
        printf("请输入文件名: ");
        gets(filename.str);
    }

    if (isEmpty(&filename))
    {
        printf("文件名为空不能保存!");
        return;
    }
    //// 1.包含头文件
    //// 2.创建流对象
    FILE* fp = NULL;
    //// 3.指定打开的方式    
    fp = fopen(filename.str, "r+");
    if (fp == NULL)
    {
        printf("文件打开失败!");
        return;
    }
    //// 4.读内容
    fscanf(fp, "%s", temp.str);//文件标记
    if (strcmp(temp.str, FILE_CODE) != 0)
    {
        printf("不支持的文件格式!");
        fclose(fp);
        return;
    }
    scanf(fp, "%d", &g->anum);//保存区域数
    for (int i = 0; i < g->anum; i++)//保存区域
        fscanf(fp, "%s %s %d", g->areas[i].no.str, g->areas[i].name.str, &g->areas[i].useFlag);
    fscanf(fp, "%d", &g->tnum);//保存树数
    for (int i = 0; i < g->tnum; i++) {
        fscanf(fp, "%s %d %d %d %d %f %f %d %d %d %d",
            g->trees[i].no.str,
            &g->trees[i].indexArea,
            &g->trees[i].ztime.year, &g->trees[i].ztime.month, &g->trees[i].ztime.day,
            &g->trees[i].height,
            &g->trees[i].perimeter,
            &g->trees[i].age.year, &g->trees[i].age.month, &g->trees[i].age.day,
            &g->trees[i].state);
    }
    //// 5.关闭文件
    fclose(fp);
    printf("文件打开成功!\n");
    g->bmodify = FALSE;

    g->filename = filename;


}