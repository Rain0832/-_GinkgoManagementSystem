#include "common.h"
#include "tree.h"
#include "area.h"
void initTree(struct Tree* p)
{
	p->no.str[0] = '\0';
	p->indexArea = 0;
	initDate(&p->ztime);
	p->height = 0;
	p->perimeter = 0;
	initDate(&p->age);
	p->state = STATE_UNKOWN;//״̬δ֪
}

