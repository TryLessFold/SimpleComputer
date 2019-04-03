#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "display.h"


int mt_clrscr()
{
	printf("\E[H\E[J");
	return 0;
}
int mt_gotoXY (int x, int y)
{
	printf("%c[%d;%df",0x1B,y,x);
	return 0;
}
int mt_getscreensize (int *size_x, int *size_y)
{
 	struct winsize w;
   	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	*size_y = w.ws_row;
	*size_x = w.ws_col;
	return 0;
}
int mt_setcreeensize (int size_x, int size_y)
{
	return 0;
}
int mt_setfgcolor (enum colors c)
{
	printf("\E[3%dm", c);
	return 0;
}
int mt_setbgcolor (enum colors c)
{
        printf("\E[4%dm", c);
	return 0;
}

int display_term()
{
	int *size_x, *size_y;
	mt_getscreensize (size_x, size_y);
	mt_clrscr();
	//for(int i=0; i<size_x; i++)
	{
		printf("1");
	}
	return 0;
}
