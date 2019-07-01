#ifndef BBB
 #define BBB
	#include <signal.h>
	#include <sys/time.h>
	#include <unistd.h>
	static unsigned int bigint[17][2]={
	{
	        4291019715,
	        3284386815
	},
	{
	        50529027,
	        50529027
	},
	{
	        4278387711,
	        3233857791
	},
	{
	        4278387711,
	        50529279
	},
	{
	        3284386815,
	        50529027
	},
	{
	        4290822399,
	        50529279
	},
	{
	        4290822399,
	        3284386815
	},
	{
	        4278387459,
	        50529027
	},
	{
	        4291019775,
	        3284386815
	},
	{
	        4291019775,
	        50529279
	},
	{
	        406611558,
	        3288318915
	},
	{
	        4274243324,
	        3267609598
	},
	{
	        2143535296,
	        3233858431
	},
	{
	        4240688067,
	        3284386812
	},
	{
	        4290822399,
	        3233857791
	},
	{
	        4290822396,
	        3233857728
	},
	{
	        404232447,
	        4279769112
	}
	};

	int cursor;
	enum colors {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, NON};
	struct itimerval nval;
	int accumulator, inst_counter, com, op;
	void memoryShow();
	void CPUshow();
	void flagShow();
	void keysShow();
	void printBoxes();
	void printBigChars();
	void window();
	void settimer(struct itimerval * nval);
	void timer();
	void reset();
	int mt_clrscr();
	int mt_gotoXY (int x, int y);
	int mt_getscreensize (int *cols, int *rows);
	int mt_setfgcolor (enum colors c);
	int mt_setbgcolor (enum colors c);
	int bc_printA(char * str);
	int bc_box(int x1, int y1, int x2, int y2);
	int bc_initbigchar(int *a, char b);
	int bc_printbigchar (unsigned int [2], int x, int y, enum colors, enum colors);
	int bc_setbigcharpos (unsigned int * big, int x, int y, int value);
	int bc_getbigcharpos(unsigned int * big, int x, int y, int *value);
	int bc_bigcharwrite (int fd, unsigned int * big, int count);
	int bc_bigcharread (int fd, unsigned int ** big, int need_count, int * count);
 #endif
