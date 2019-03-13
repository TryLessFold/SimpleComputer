#include "stdio.h"
#include <stdlib.h>

#include "display.h"

int mt_clrscr(void)
{
	printf("\E[H\E[J");
	return 0;
}
int mt_gotoXY (int x, int y)
{
	return 0;
}
int mt_getscreensize (int *size_x, int *size_y)
{
	return 0;
}
int mt_setfgcolor (enum colors c)
{
	return 0;
}
int mt_setbgcolor (enum colors c)
{
	return 0;
}
