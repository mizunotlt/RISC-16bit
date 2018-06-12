#ifndef RISC_MACHINE_H
#define RISC_MACHINE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mem.h>
#include <math.h>

int menu();

struct command{
    char *command;
    struct commandRRR{
        short int regA;
        short int regB;
        short int regC;
    };
    struct commandRRI{
        short int regAA;
        short int regBB;
        short int imm;
    };
    struct commandRI{
        short int reA;
        short int im;
    };
    struct commandRRR rrrCom ;
    struct commandRRI rriCom;
    struct commandRI riCom;
};


#endif