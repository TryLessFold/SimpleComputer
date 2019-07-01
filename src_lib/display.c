#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <display.h>
#include <keys.h>
#include <processor.h>

void memoryShow()
{
    for(int i = 0; i < size; i++)
    {
        if(i == cursor)
        {
            mt_setbgcolor(CYAN);
            mt_setfgcolor(BLACK);
        }
        else
        {
            mt_setbgcolor(BLACK);
            mt_setfgcolor(WHITE);
        }
        if(i % 10 == 0)
        {
            mt_gotoXY(2,(i / 10) + 2);
        }
        printf("+%04X ", RAM[i]);
    }
}

void flagShow()
{
    int fl;
    mt_gotoXY(65, 11);
	sc_regGet(REG_OVERFLOW, &fl);
    if(fl)
    {
        printf("O ");
    }
    else
    {
        printf(" ");
    }
sc_regGet(REG_MEMORY, &fl);
    if(fl)
    {
        printf("M ");
    }
    else
    {
        printf(" ");
    }
sc_regGet(REG_INFINITY, &fl);
    if(fl)
    {
        printf("N ");
    }
    else
    {
        printf(" ");
    }
sc_regGet(REG_IGNORE, &fl);
    if(fl)
    {
        printf("I ");
    }
    else
    {
        printf(" ");
    }
sc_regGet(REG_ERROR, &fl);
    if(fl)
    {
        printf("C");
    }
    else
    {
        printf(" ");
    }
}
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
	mt_gotoXY(65, 2);
	printf("+%04X", accumulator);
        mt_gotoXY(65, 4);
        printf("InstructionCounter");
        mt_gotoXY(65, 5);
	printf("+%04X", inst_counter);
	mt_gotoXY(65, 7);
        printf("Operation");
	mt_gotoXY(65, 8);
	printf("+%02d : %02d", com, op);
        mt_gotoXY(65, 10);
        printf("Flags");
        mt_gotoXY(50, 13);
        printf("Keys");
}

void printBigChars()
{
    int value;
    int bigchar[2];
    char char_symbol[8];

    sc_memoryGet(cursor, &value);
    if(value >> 14)
    {
        sprintf(char_symbol, "-%04X", value);
    }
    else
    {
        sprintf(char_symbol, "+%04X", value);
    }
    for(int i = 0; i < 5; i++)
    {
	bc_initbigchar(bigchar, char_symbol[i]);
        bc_printbigchar(bigchar, 2 + (i * 9), 14, WHITE, BLACK);
    }
}

void window()
{
    draw_boxes();
    draw_keys();
    flagShow();
    memoryShow();
    printBigChars();
    printf("\n");
}

void settimer(struct itimerval * nval)
{
    nval->it_interval.tv_sec = 0;
    nval->it_interval.tv_usec = 0;
    nval->it_value.tv_sec = 0;
    nval->it_value.tv_usec = 155500;
}

void timer()
{
    window();
    inst_counter++;
    cursor = inst_counter;
    if (inst_counter == size) 
    {
        sc_regSet(REG_IGNORE, 1);
        cursor = inst_counter = 0;
    }
}

void reset()
{
    sc_memoryInit();
    sc_regInit();
    sc_regSet(REG_IGNORE, 1);
    cursor = inst_counter = accumulator = 0;
}

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
int mt_getscreensize (int *rows, int *cols)
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
        printf("\E[10%dm", c);
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
    }   bc_printA("k");
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
int bc_initbigchar(int * big, char value)
{
    switch(value)
    {
        case '-':
            big[0] = 4278190080;
            big[1] = 255;
            break;

        case '+':
            big[0] = 404232447;
            big[1] = 4279769112;
            break;

        case '0':
            big[0] = 4291019715;
            big[1] = 3284386815;
            break;

        case '1':
            big[0] = 50529027;
            big[1] = 50529027;
            break;

	case '2':
            big[0] = 4278387711;
            big[1] = 3233857791;
            break;

	case '3':
            big[0] = 4278387711;
            big[1] = 50529279;
            break;

	case '4':
            big[0] = 3284386815;
            big[1] = 50529027;
            break;

	case '5':
            big[0] = 4290822399;
            big[1] = 50529279;
            break;

	case '6':
            big[0] = 4290822399;
            big[1] = 3284386815;
            break;

	case '7':
            big[0] = 4278387459;
            big[1] = 50529027;
            break;

	case '8':
            big[0] = 4291019775;
            big[1] = 3284386815;
            break;

	case '9':
            big[0] = 4291019775;
            big[1] = 50529279;
            break;

        case 'A':
            big[0] = 406611558;
            big[1] = 3288318915;
            break;

        case 'B':
            big[0] = 4274243324;
            big[1] = 3267609598;
            break;

        case 'C':
            big[0] = 2143535296;
            big[1] = 3233858431;
            break;

        case 'D':
            big[0] = 4240688067;
            big[1] = 3284386812;
            break;

        case 'E':
            big[0] = 4290822399;
            big[1] = 3233857791;
            break;

        case 'F':
            big[0] = 4290822396;
            big[1] = 3233857728;
            break;

        default:
            break;
    }
    
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
    mt_setfgcolor(WHITE);
    mt_setbgcolor(BLACK);
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
