#include <stdio.h>
#include <display.h>
#include <processor.h>
#include <keys.h>

int main() {
	sc_memoryInit();
    sc_regInit();
    sc_regSet(REG_IGNORE, 1);
    int x, y, z, acc, inst, value, code;
    char f;
    char t;
    signal(SIGALRM, timer);
    signal(SIGUSR1, reset);
    settimer(&nval);
	enum keys K;
	K = NONE;
	inst_counter = 0;
        while (K!=QUIT)
	{
                mt_clrscr();
                window();
          //      printf("\n");
		mt_gotoXY(1, 23);
		sc_regGet(REG_IGNORE, &value);
		if (value)
		{
		rk_readkey(&K);
	//	printf("%d",K);
		switch(K)
		{
			case SAVE:
		        	sc_memorySave("Memory.dat");
		        	break;
		        case LOAD:
		        	sc_memoryLoad("Memory.dat");
				break;
			case F5:
		    		scanf("%d", &acc);
			    	accumulator = acc;
				break;
			case F6:
		                scanf("%d", &inst);
			        inst_counter = inst;
	      	                break;
			case UP:
			        if(cursor/10 >= 1)
				cursor -= 10;
		        	break;
			case DOWN:
			        if (cursor/10<=8)
				cursor += 10;
			        break;
			case LEFT:
		        	if(cursor%10 >= 1)
				cursor--;
		        	break;
			case RIGHT:
			        if(cursor%10 <= 8)
				cursor++;
		        	break;
			case RUN:
                    		sc_regSet(REG_IGNORE, 0);
	                        cursor = 0;
            		        break;
                	case ENTER:
	            		scanf("%d", &y);
                    		sc_memorySet(cursor, y);
                    		break;
                	case STEP:
	                        printf("Coming soon\n");
            		        getchar();
	                        break;
            		case RESET:
                    		raise(SIGUSR1);
                    		break;
		}
		}
		else
		{
		setitimer(ITIMER_REAL, &nval, NULL);
            	pause();
		}
	}
        return 0;
}
