#include "area.h"

char* areaUseStateNames[] = {"不可用","可使用","无效状态"};
void initArea(struct Area* p)
{
	p->name.str[0] = '\0';
	p->no.str[0] = '\0';
	p->useFlag = 0;
}
