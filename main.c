#include "stdio.h"
#include "iostream"
#include "display.h"
#include "processor.h"

using namespace std;

//enum colors {black, red, green, yellow, blue, magenta, cyan, white};

int main()
{
mt_setfgcolor (black);
mt_setbgcolor (white);
mt_clrscr();
 bc_printA("b");
//display_term();
return 0;
}
