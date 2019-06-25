#ifndef AAA
 #define AAA
	#define size 100

	#define REG_OVERFLOW 0b0000001
	#define REG_INFINITY 0b0000010
	#define REG_MEMORY 0b0000100
	#define REG_IGNORE 0b0001000
	#define REG_ERROR 0b0010000
	
	 int RAM[size];
	 int flag;
	int sc_memoryInit();
	int sc_memorySet(int address, int value);
	int sc_memoryGet(int address, int* value);
	int sc_memorySave(char* filename);
	int sc_memoryLoad(char* filename);
	int sc_regInit();
	int sc_regSet(int regist, int value);
	int sc_regGet(int regist, int* value);
	int sc_commandEncode(int command, int operand, int* value);
	int sc_commandDecode(int value, int *command, int *operand);
 #endif
