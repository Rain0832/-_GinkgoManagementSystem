#pragma once

#define TRUE 1 
#define FALSE 0
#define NULL 0 //¿ÕÖ¸Õë

#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)

enum MenuType { MENU_UNKOWN=-1,MENU_MAIN, MENU_AREA, MENU_TREES
};
extern char *menuNames[];
