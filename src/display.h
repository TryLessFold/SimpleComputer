#ifndef BBB
 #define BBB
	enum colors {black, red, green, yellow, blue, magenta, cyan, white, non};
	int accumulator, inst_counter, command, operand;
	int mt_clrscr();
	int mt_gotoXY (int x, int y);
	int mt_getscreensize (int *cols, int *rows);
	int mt_setfgcolor (enum colors c);
	int mt_setbgcolor (enum colors c);
	int display_term();
	int bc_printA(char * str);
	int bc_box(int x1, int y1, int x2, int y2);
	int bc_printbigchar (unsigned int [2], int x, int y, enum colors, enum colors);
	int bc_setbigcharpos (unsigned int * big, int x, int y, int value);
	int bc_getbigcharpos(unsigned int * big, int x, int y, int *value);
	int bc_bigcharwrite (int fd, unsigned int * big, int count);
	int bc_bigcharread (int fd, unsigned int ** big, int need_count, int * count);
 #endif
