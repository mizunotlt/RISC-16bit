#ifndef RISC_MACHINE_H
#define RISC_MACHINE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int menu();


#define MAXC 100
#define ADD 0
#define ADDI 1
#define NAND 2
#define LUI 3
#define SW 4
#define LW 5
#define BEQ 6
#define JAIR 7
#define MAXLENGTHLINE 32
#define MAX_COMMAND 100
#define REG 8
#define MEMORY_SIZE 1000

char *fileName;
char *inName;
int countCom;
struct command{
    int command;
    short int regA;
    short int regB;
    short int regCI;
};

#endif