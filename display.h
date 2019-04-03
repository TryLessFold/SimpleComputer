#ifndef AAA
 #define AAA
	enum colors {black, red, green, yellow, blue, magenta, cyan, white};
	int mt_clrscr();
	int mt_gotoXY (int x, int y);
	int mt_getscreensize (int *size_x, int *size_y);
	int mt_setfgcolor (enum colors c);
	int mt_setbgcolor (enum colors c);
	int display_term();
 #endif
