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
int mt_getscreensize (int *cols, int *rows)
{
 	struct winsize w;
   	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	*cols = w.ws_row;
	*rows = w.ws_col;
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

int bc_printA(char* str)
{	
	printf("\E(0%s\E(B",str);
	return 0;
}

int bc_box(int x1, int y1, int x2, int y2)
{
    mt_gotoXY(x1, y1);
    bc_printA("l");
    for (int i = 1; i < x2; i++) {
        bc_printA("q");
    }
    bc_printA("k");
    for (int i = 1; i < y2; i++) {
        mt_gotoXY(x1, y1 + i);
        bc_printA("x");
        mt_gotoXY(x1 + x2, y1 + i);
        bc_printA("x");
    }
    mt_gotoXY(x1, y1 + y2);
    bc_printA("m");
    for (int i = 1; i < x2; i++) {
        bc_printA("q");
    }
    bc_printA("j");
    return 0;
}

int bc_printbigchar(unsigned int d[2], int x, int y, enum colors f, enum colors b)
{
    mt_setfgcolor(f);
    mt_setbgcolor(b);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int k = (i%4)*8 + j;
            mt_gotoXY(x+(7-j), y + (i/4*4)+3-(i%4));
            if (d[(i / 4)] & (1 << k)){
                bc_printA("a");
            } else {
                printf(" ");
            }
        }
    }
    mt_gotoXY(x+8,y+8);
    mt_setfgcolor(non);
    mt_setbgcolor(non);
    return 0;
}

int bc_setbigcharpos(unsigned int* big, int x, int y, int value)
{
    if (x < 0 || x > 7 || y < 0 || y > 7 || value > 1 || value < 0) {
        return -1;
    }
    int i = 0;
    if (x > 3)
        i = 1;
    if (value) {
        big[i] |= 1 << (x * 8 + y);
    } else {
        big[i] &= ~(1 << (x * 8 + y));
    }
    return 0;
}

int bc_getbigcharpos(unsigned int* big, int x, int y, int* value)
{
    if (x < 0 || x > 7 || y < 0 || y > 7 || *value > 1 || *value < 0) {
        return -1;
    }
    int i = 0;
    if (x > 3)
        i = 1;
    *value = ((big[i] >> (x * 8)) >> y) & 1;
    return 0;
}

int bc_bigcharwrite(int fd, unsigned int* big, int count)
{
    if (!big || fd < 0) {
        return -1;
    }
    while (count > 0) {
        int result;
        if ((result = write(fd, big, sizeof(int) * 2)) == -1)
            return -1;
        count--;
    }
    return 0;
}

int bc_bigcharread(int fd, unsigned int** big, int need_count, int* count)
{
    if (fd < 0) {
        return -1;
    }
    while (need_count > 0) {
        int result;
	char buf[40];
        if ((result = read(fd, buf, 10*4)) == -1)
            return -1;
	else
	{
		
	}
        need_count--;
        *count = *count + 1;
    }
    return 0;
}
