#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "display.h"
#include "processor.h"

using namespace std;
static unsigned int bigint0[2] = {4291019715, 3284386815};
static unsigned int bigint1[2] = {50529027, 50529027};
static unsigned int bigint2[2] = {4278387711, 3233857791};
static unsigned int bigint3[2] = {4278387711, 50529279};
static unsigned int bigint4[2] = {3284386815, 50529027};
static unsigned int bigint5[2] = {4290822399,50529279};
static unsigned int bigint6[2] = {4290822399,3284386815};
static unsigned int bigint7[2] = {4278387459,50529027};
static unsigned int bigint8[2] = {4291019775,3284386815};
static unsigned int bigint9[2] = {4291019775,50529279};
static unsigned int bigint10[2] = {406611558,3288318915};
static unsigned int bigint11[2] = {4274243324,3267609598};
static unsigned int bigint12[2] = {2143535296,3233858431};
static unsigned int bigint13[2] = {4240688067,3284386812};
static unsigned int bigint14[2] = {4290822399,3233857791};
static unsigned int bigint15[2] = {4290822396,3233857728};
static unsigned int bigint16[2] = {404232447,4279769112}; // todo
//enum colors {black, red, green, yellow, blue, magenta, cyan, white};
void display()
{
	mt_setfgcolor(white);
	mt_setbgcolor(black);
 	int x, y;
mt_getscreensize(&x,&y);
for(int i = 0; i<=x; i++)
for(int j=0; j<=y;j++)
{
mt_gotoXY(i,j);
printf(" ");
}
    bc_box(1, 1, 60, 11);
    
    bc_box(62, 1, 21, 2);
    bc_box(62, 4, 21, 2);
    bc_box(62, 7, 21, 2);
    bc_box(62, 10, 21, 2);
    bc_box(1, 13, 45, 9);
    bc_box(47, 13, 36, 9);
    mt_gotoXY(4,1);
printf("Memory");
  mt_gotoXY(65,1);
printf("Accumulator");
  mt_gotoXY(65,4);
printf("InstructionCounter");
  mt_gotoXY(65,7);
printf("Operation");
  mt_gotoXY(65,10);
printf("Flags");
mt_gotoXY(50,13);
printf("Keys");
bc_printbigchar(bigint0, 2,14 , white, black);
bc_printbigchar(bigint0, 11,14 , white, black);
bc_printbigchar(bigint0, 20,14 , white, black);
bc_printbigchar(bigint0, 29,14 , white, black);
bc_printbigchar(bigint0, 38,14 , white, black);
mt_gotoXY(1, 23);
}
int main()
{
while(getchar()!='0')
{
mt_clrscr();
display();
}
return 0;
}
