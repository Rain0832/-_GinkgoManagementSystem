#pragma once
#include <string.h>
#include <stdlib.h>

#define STRING_LENGTH 255//有效字符串最大数
#define MAX_STRING_LENGTH STRING_LENGTH+1//最大字符串占用内存
//短的字符串
struct String
{
	char str[MAX_STRING_LENGTH];
};

// 将int 转换成string
void itos(int i, struct String str);
// 将string 转换成int
int stoi(struct String str);
// 字符串拷贝
int mystrcpy(struct String *src, struct String *des);
//判断两个字符串是否相等,注意:只比较src1的长度
//完整匹配
int isEqualString(struct String *src1, struct String *src2);
//关键字匹配:查询src中是否包含key
int stringMatchKey(struct String* src, struct String* key);
//判断String是否为空
int isEmpty(struct String* src);

