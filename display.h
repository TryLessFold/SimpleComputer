#ifndef AAA
 #define AAA
	enum colors {black, red, green, yellow, blue, magenta, cyan, white};
	int mt_clrscr();
	int mt_gotoXY (int x, int y);
	int mt_getscreensize (int *size_x, int *size_y);
	int mt_setfgcolor (enum colors c);
	int mt_setbgcolor (enum colors c);
	int display_term();
	int bc_printA(char * str);
	int bc_box(int x1, int y1, int x2, int y2);
	int bc_printbigchar (int [2], int x, int y, enum colors, enum colors);
	int bc_setbigcharpos (int * big, int x, int y, int value);
	int bc_getbigcharpos(int * big, int x, int y, int *value);
	int bc_bigcharwrite (int fd, int * big, int count);
	int bc_bigcharread (int fd, int * big, int need_count, int * count);
 #endif
