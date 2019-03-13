#ifndef AAA
 #define AAA
	enum colors {red, green, blue};
	int mt_clrscr(void);
	int mt_gotoXY (int x, int y);
	int mt_getscreensize (int *size_x, int *size_y);
	int mt_setfgcolor (enum colors c);
	int mt_setbgcolor (enum colors c);
 #endif
