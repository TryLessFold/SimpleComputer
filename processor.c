#include <stdio.h>
#include <stdlib.h>
#include "processor.h"

int mass[size];
int flag;

int sc_memoryInit()
{
	for(int i = 0; i<size; i++)
	{
		mass[i] = 0;		
	}
	return 0;
}

int sc_memorySet(int address, int value)
{
	if ((address<0)||(address>=size)) return 1;
	mass[address] = value;
	return 0; 
}

int sc_memoryGet(int address, int* value)
{
	if ((address<0)||(address>=size)) return 1;
	*value = mass[address];
	return 0;
}

int sc_memorySave(char* filename)
{
	FILE* f = fopen(filename, "w");
	fwrite(mass, sizeof(int), 100, f);
	fclose(f);
	return 0;
}

int sc_memoryLoad(char* filename)
{
	FILE* f = fopen(filename, "r");
	if (f==NULL) return 1;
	fread(mass, sizeof(int), 100, f);
	fclose(f);
	return 0;
}

int sc_regInit()
{
	flag = 0;
	return 0;
}

int sc_regSet(int regist, int value)
{
	if (flag >= 0b0000000 && flag <= 0b0010000)
	{
		if(value == 0) 
		{
			regist = ~regist;
			flag = flag & regist;
		}
		else if(value == 1)
		{
			flag = flag | regist;
		}
		else
		{
			return 1;
		}
		return 0;
	}
	return 1;
}

int sc_regGet(int regist, int* value)
{
	if (flag >= 0b0000000 && flag <= 0b0010000)
	{
		if ((flag&regist)==0) *value = 0;
		else *value = 1;
		return 0;	
	}	
	return 1;
}

int sc_commandEncode(int command, int operand, int* value)
{
	if ((command >= 0b0001010 && command <= 0b0001011) || 
	    (command >= 0b0010100 && command <= 0b0010101) || 
	    (command >= 0b0011110 && command <= 0b0100001) || 
	    (command >= 0b0101000 && command <= 0b0101011) ||
	    (command >= 0b0110011 && command <= 0b1001100) ||
	    (operand >= 0b0000000 && operand <= 0b1111111)) 
		{
			*value = ((*value | command) << 7) | operand;
			return 0;		
		}
	return 1;
}

int sc_commandDecode(int value, int *command, int *operand)
{
	if ((value >= 0b00010100000000 && value <= 0b00010111111111) ||
	    (value >= 0b00101000000000 && value <= 0b00101011111111) ||
	    (value >= 0b00111100000000 && value <= 0b01000011111111) ||
	    (value >= 0b01010000000000 && value <= 0b01010111111111) ||
	    (value >= 0b01100110000000 && value <= 0b10011001111111)) 
		{
			*operand = value & 0b1111111;
			*command = (value >> 7) & 0b1111111;
			return 0;
		}
	return 1;
}



