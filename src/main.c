#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "display.h"
#include "processor.h"

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
void draw_keys()
{   
	mt_gotoXY(49, 14);
	printf("l - load");
	mt_gotoXY(49, 15);
	printf("s - save");
	mt_gotoXY(49, 16);
	printf("r - run");
	mt_gotoXY(49, 17);
	printf("t - step");
	mt_gotoXY(49, 18);
	printf("i - reset");
	mt_gotoXY(49, 19);
	printf("f5 - accumulator");
	mt_gotoXY(49, 20);
	printf("f6 - instructionCounter");
}
void draw_boxes()
{
	bc_box(1, 1, 61, 11);
	bc_box(63, 1, 21, 2);
        bc_box(63, 4, 21, 2);
        bc_box(63, 7, 21, 2);
        bc_box(63, 10, 21, 2);
        bc_box(1, 13, 45, 9);
        bc_box(47, 13, 37, 9);
        mt_gotoXY(4, 1);
        printf("Memory");
        mt_gotoXY(65, 1);
        printf("Accumulator");
        mt_gotoXY(65, 4);
        printf("InstructionCounter");
        mt_gotoXY(65, 7);
        printf("Operation");
        mt_gotoXY(65, 10);
        printf("Flags");
        mt_gotoXY(50, 13);
        printf("Keys");	
}
void display() {
        mt_setfgcolor(white);
        mt_setbgcolor(black);
        int x, y;
	int value_ram;
        mt_getscreensize( & x, & y); 
        for (int i = 0; i <= x; i++)           //Fill screen
                for (int j = 0; j <= y; j++) {
                        mt_gotoXY(i, j);
                        printf(" ");
                }
	draw_boxes();
        for (int i = 0; i < 100; i++) {
		if (i%10==0){
			mt_gotoXY(2, (i/10)+2);
		}
		sc_memoryGet(i, &value_ram);
		printf("+%04X ",value_ram);
        }
	draw_keys();
        bc_printbigchar(bigint[0], 2, 14, white, black);
        bc_printbigchar(bigint[0], 11, 14, white, black);
        bc_printbigchar(bigint[0], 20, 14, white, black);
        bc_printbigchar(bigint[0], 29, 14, white, black);
        bc_printbigchar(bigint[0]
, 38, 14, white, black);
        mt_gotoXY(1, 23);
}
int main() {
	sc_memoryInit();
        while (getchar() != '0') {
                mt_clrscr();
                display();
        }
        return 0;
}
