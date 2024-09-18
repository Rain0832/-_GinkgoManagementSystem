#include "string.h"
#include <string.h>
#include <stdlib.h>
#include "common.h"

// 将int 转换成string
void itos(int i, struct String str)
{
	_itoa(i, str.str, 10);
}

// 将string 转换成int
int stoi(struct String str)
{
	return atoi(str.str);
}

// 字符串拷贝
int mystrcpy(struct String *src, struct String *des)
{
	int i;
	int n = MIN(strlen(src->str), STRING_LENGTH);
	for (i = 0; i < n; i++)
		des->str[i] = src->str[i];
	des->str[n] = '\0';
}

//判断两个字符串是否相等,注意:只比较src1的长度
int isEqualString(struct String *src1, struct String *src2)
{
	if (src1 == NULL || src2 == NULL)
		return FALSE;

	if(strcmp(src1->str, src2->str) == 0)
		return TRUE;
	return FALSE;
}

//关键字匹配:查询src中是否包含key
int stringMatchKey(struct String* src, struct String* key)
{
	int is = FALSE;
	if (src == NULL || key == NULL)
		return is;
	char* psrc = src->str;
	char* pkey = key->str;
	int i,j,n = strlen(psrc), m = strlen(pkey);
	for (i = 0; i < n - m + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (psrc[i+j] != pkey[j])//有不匹配提前终止匹配
				break;
		}
		if (j == m)//找到匹配不再继续匹配提前退出
		{
			is = TRUE;
			break;
		}
	}
	return is;
}

//判断String是否为空
//空或不存在：TRUE
//其它（有效或有值）：FALSE不为空
int isEmpty(struct String* src)
{
	if (src != NULL && src->str[0] != '\0')
		return FALSE;
	return TRUE;
}