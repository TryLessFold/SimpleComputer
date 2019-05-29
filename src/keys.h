#ifndef CCC
#define CCC

#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "display.h"

int curs;

enum keys {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    LOAD,
    SAVE,
    RUN,
    STEP,
    RESET,
    TRANS,
    F5,
    F6,
    QUIT,
    ENTER,
    NONE
};

int rk_readkey(enum keys *);
int rk_mytermsave();
int rk_mytermrestore();
int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);

#endif
