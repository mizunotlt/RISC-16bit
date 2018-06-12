#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mem.h>
#include <math.h>
#include "risc.h"

 int toDec (char *binaryCode){
    int decValue = 0;
    for (int i = 0; i < 3; i ++){
        if (binaryCode[i] == '1'){
            decValue = decValue + pow(2, 2 - i);
        }
    }
    return decValue;
}
int toDecForImm (char *binaryCode){
    int decValue = 0;
    int sign = -1;
    for (int i = 1; i < 7; i ++){
        if (binaryCode[i] == '1'){
            decValue = decValue + pow(2, 6 - i);
        }
    }
    if (binaryCode[0] == '1'){
        decValue = decValue * sign;
    }
    return decValue;
}
void outDebugF(int step, FILE* outFile, char *opcode, short int regA, short int regB, short int regCI,
               short int *regMemory, short int *fixMemory, int REG){
    if (!strcmp(opcode, "ADD")){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "ADD reg[%d] reg[%d] 0000 reg[%d]\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (!strcmp(opcode, "ADDI")){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "ADDI reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (!strcmp(opcode, "NAND")){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "NAND reg[%d] reg[%d] 0000 reg[%d]\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (!strcmp(opcode, "lui")){

    }else if(!strcmp(opcode, "sw")){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "sw reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (!strcmp(opcode, "lw")){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "lw reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (!strcmp(opcode, "beg")){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "beg reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (!strcmp(opcode, "jair")){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "jair reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }
    }
}

void outDebugT(int step,char *opcode, short int regA, short int regB, short int regCI,
               short int *regMemory, short int *fixMemory, int REG){
    if (!strcmp(opcode, "ADD")){
        printf("step %d \n", step);
        printf("ADD reg[%d] reg[%d] 0000 reg[%d]\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf( "reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf( "add[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (!strcmp(opcode, "ADDI")){
        printf( "step %d \n", step);
        printf("ADDI reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf( "reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf( "add[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (!strcmp(opcode, "NAND")){
        printf("step %d \n", step);
        printf("NAND reg[%d] reg[%d] 0000 reg[%d]\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf( "reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf("add[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (!strcmp(opcode, "lui")){

    }else if(!strcmp(opcode, "sw")){
        printf("step %d \n", step);
        printf("sw reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf("reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf("add[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (!strcmp(opcode, "lw")){
        printf("step %d \n", step);
        printf("lw reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf("reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf("add[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (!strcmp(opcode, "beg")){
        printf("step %d \n", step);
        printf("beg reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf("reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf( "add[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (!strcmp(opcode, "jair")){
        printf("step  %d \n", step);
        printf("jair reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf( "reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf("add[%d] = %d \n", i, fixMemory[i]);
        }
    }
}



int main(){
    printf("Static MEmory RISC machine simulator\n");

    const int MAXLENGTHLINE = 32;
    const int MAX_COMMAND = 100; // максимально число команд во вхдном файле
    const int REG = 8; //число регистров
    short int *fixMemory = malloc(sizeof(short int) * 1000);
    short int regMemory[REG];
    int countCommand = 0;
    char *opcode;
    char *arg1;
    char *arg2;
    char *arg3;
    char *workCode;
    int line = 0;
    _Bool workC = true;
    for (int i = 0; i < REG; i++){
        regMemory[i] = 0;
    }
    //в зависимости от типа комнды будет обращать к тому или иному типу структуры
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
    struct command* command = malloc(sizeof(struct command) * 100);

    char inputCom[MAXLENGTHLINE];

    char *fileName = "command.txt";
    FILE *commandInput;
    commandInput = fopen(fileName, "rt");
    //считывание команд из файла и парсер их
    while (!feof(commandInput)){
        fgets(inputCom, sizeof(inputCom), commandInput);
        opcode= strtok(inputCom, " ");
        if (!strcmp(opcode, "000")){ //ADD
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            workCode = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = "ADD";
            command[line].rrrCom.regA = toDec(arg1);
            command[line].rrrCom.regB = toDec(arg2);
            command[line].rrrCom.regC = toDec(arg3);
            line++;

        }else if (!strcmp(opcode, "001")){ //ADDI
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = "ADDI";
            command[line].rriCom.regAA = toDec(arg1);
            command[line].rriCom.regBB = toDec(arg2);
            command[line].rriCom.imm = toDecForImm(arg3);
            line++;
        }else if (!strcmp(opcode, "010")){ //NAND
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = "NAND";
            command[line].rrrCom.regA = toDec(arg1);
            command[line].rrrCom.regB = toDec(arg2);
            command[line].rrrCom.regC = toDec(arg3);
            line++;
        }else if (!strcmp(opcode, "011")){ //lui
            arg1 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = "lui";
            command[line].riCom.reA = toDec(arg1);
            command[line].riCom.im = toDec(arg3);
            line++;
        }else if(!strcmp(opcode, "101")){ //sw
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = "sw";
            command[line].rriCom.regAA = toDec(arg1);
            command[line].rriCom.regBB = toDec(arg2);
            command[line].rriCom.imm = toDecForImm(arg3);
            line++;
        }else if (!strcmp(opcode, "100")){ //lw
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = "lw";
            command[line].rriCom.regAA = toDec(arg1);
            command[line].rriCom.regBB = toDec(arg2);
            command[line].rriCom.imm = toDecForImm(arg3);
            line++;

        }else if (!strcmp(opcode, "110")){ //beg
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = "beg";
            command[line].rriCom.regAA = toDec(arg1);
            command[line].rriCom.regBB = toDec(arg2);
            command[line].rriCom.imm = toDecForImm(arg3);
            line++;
        }else if (!strcmp(opcode, "111")){ //jair
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = "jair";
            command[line].rriCom.regAA = toDec(arg1);
            command[line].rriCom.regBB = toDec(arg2);
            command[line].rriCom.imm = toDecForImm(arg3);
            line++;
        }else if (!strcmp(opcode, "exit")){
            countCommand = line;
        }
    }

    //реализовать выполнение самой программы
    int countCom = 0;
    //функция initialOrder или начальная загрузка в память
    fixMemory[0] = 0; //для обнуления
    fixMemory[1] = 4; //для счета индексов массива адресов
    fixMemory[2] = 2;
    fixMemory[3] = 0;
    fixMemory[4] = 4;

    while (workC){
        switch (menu()){
            case 1: { //Full work machine
                while (countCom != countCommand){
                    if (!strcmp(command[countCom].command, "ADD")){
                        regMemory[command[countCom].rrrCom.regA] = regMemory[command[countCom].rrrCom.regB]
                                                                   + regMemory[command[countCom].rrrCom.regC];
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "ADDI")){
                        regMemory[command[countCom].rriCom.regAA] = regMemory[command[countCom].rriCom.regBB] + command[countCom].rriCom.imm;
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "NAND")){
                        regMemory[command[countCom].rrrCom.regA] = (regMemory[command[countCom].rrrCom.regB]
                                                                    & regMemory[command[countCom].rrrCom.regC]);
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "lui")){

                    }else if(!strcmp(command[countCom].command, "sw")){
                        fixMemory[regMemory[command[countCom].rriCom.regBB] + command[countCom].rriCom.imm] = regMemory[command[countCom].rriCom.regAA];
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "lw")){
                        regMemory[command[countCom].rriCom.regAA] = fixMemory[regMemory[command[countCom].rriCom.regBB] + command[countCom].rriCom.imm];
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "beg")){
                        if (regMemory[command[countCom].rriCom.regAA] == regMemory[command[countCom].rriCom.regBB]){
                            countCom = countCom + 1 + command[countCom].rriCom.imm;
                        } else{
                            countCom++;
                        }
                    }else if (!strcmp(command[countCom].command, "jair")){
                        regMemory[command[countCom].rriCom.regAA] = countCom + 1;
                        countCom = regMemory[command[countCom].rriCom.regBB];
                    }
                }
                char *outName = "out.txt";
                FILE *outF;
                outF = fopen(outName, "wt");
                fwrite("Данные в регистрах машины RISC \n", strlen("Данные в регистрах машины RISC \n"), 1, outF);
                //вывод результата работы программы
                for (int i = 0; i < REG; i++){
                    fprintf(outF, "Регистр[%d] = %d \n", i, regMemory[i]);
                }
                fprintf(outF, "Данные в памяти машины RISC \n");
                for (int i = 0; i <= fixMemory[1]; i++){
                    fprintf(outF, "Адрес[%d] = %d \n", i, fixMemory[i]);
                }
                workC = false;
                break;
            }
            case 2:{ //step By step
                char *outDebugName = "outDebug.txt";
                FILE *outDebug;
                outDebug = fopen(outDebugName, "wt");
                int stepCount = 2;
                countCom = 0;
                while (countCom != stepCount){
                    if (!strcmp(command[countCom].command, "ADD")){
                        regMemory[command[countCom].rrrCom.regA] = regMemory[command[countCom].rrrCom.regB]
                                                                   + regMemory[command[countCom].rrrCom.regC];
                        outDebugF(countCom,outDebug,command[countCom].command, command[countCom].rrrCom.regA,
                                  command[countCom].rrrCom.regB, command[countCom].rrrCom.regC
                                ,regMemory,fixMemory,REG);
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "ADDI")){
                        regMemory[command[countCom].rriCom.regAA] = regMemory[command[countCom].rriCom.regBB] + command[countCom].rriCom.imm;
                        outDebugF(countCom,outDebug,command[countCom].command, command[countCom].rriCom.regAA,
                                  command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                ,regMemory,fixMemory,REG);
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "NAND")){
                        regMemory[command[countCom].rrrCom.regA] = (regMemory[command[countCom].rrrCom.regB]
                                                                    & regMemory[command[countCom].rrrCom.regC]);
                        outDebugF(countCom,outDebug,command[countCom].command, command[countCom].rrrCom.regA,
                                  command[countCom].rrrCom.regB, command[countCom].rrrCom.regC
                                ,regMemory,fixMemory,REG);
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "lui")){

                    }else if(!strcmp(command[countCom].command, "sw")){
                        fixMemory[regMemory[command[countCom].rriCom.regBB] + command[countCom].rriCom.imm] = regMemory[command[countCom].rriCom.regAA];
                        outDebugF(countCom,outDebug,command[countCom].command, command[countCom].rriCom.regAA,
                                  command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                ,regMemory,fixMemory,REG);
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "lw")){
                        regMemory[command[countCom].rriCom.regAA] = fixMemory[regMemory[command[countCom].rriCom.regBB] + command[countCom].rriCom.imm];
                        outDebugF(countCom,outDebug,command[countCom].command, command[countCom].rriCom.regAA,
                                  command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                ,regMemory,fixMemory,REG);
                        countCom++;
                    }else if (!strcmp(command[countCom].command, "beg")){
                        if (regMemory[command[countCom].rriCom.regAA] == regMemory[command[countCom].rriCom.regBB]){
                            outDebugF(countCom,outDebug,command[countCom].command, command[countCom].rriCom.regAA,
                                      command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                    ,regMemory,fixMemory,REG);
                            countCom = countCom + 1 + command[countCom].rriCom.imm;
                        } else{
                            outDebugF(countCom,outDebug,command[countCom].command, command[countCom].rriCom.regAA,
                                      command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                    ,regMemory,fixMemory,REG);
                            countCom++;
                        }
                    }else if (!strcmp(command[countCom].command, "jair")){
                        regMemory[command[countCom].rriCom.regAA] = countCom + 1;
                        outDebugF(countCom,outDebug,command[countCom].command, command[countCom].rriCom.regAA,
                                  command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                ,regMemory,fixMemory,REG);
                        countCom = regMemory[command[countCom].rriCom.regBB];
                    }
                }
                workC = false;
                break;
            }
            case 3:{
                while (countCom != countCommand || workC != false){
                    if (!strcmp(command[countCom].command, "ADD")){
                        regMemory[command[countCom].rrrCom.regA] = regMemory[command[countCom].rrrCom.regB]
                                                                   + regMemory[command[countCom].rrrCom.regC];
                        outDebugT(countCom,command[countCom].command, command[countCom].rrrCom.regA,
                                  command[countCom].rrrCom.regB, command[countCom].rrrCom.regC
                                ,regMemory,fixMemory,REG);
                        while (true){
                            printf("next step? \n");
                            printf("1 - yes 0 - no \n");
                            int temp;
                            temp = scanf("%d", &temp);
                            if (temp == 1){
                                countCom++;
                            }
                            else{
                                workC = false;
                            }
                            break;
                        }

                    }else if (!strcmp(command[countCom].command, "ADDI")){
                        regMemory[command[countCom].rriCom.regAA] = regMemory[command[countCom].rriCom.regBB] + command[countCom].rriCom.imm;
                        outDebugT(countCom,command[countCom].command, command[countCom].rriCom.regAA,
                                  command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                ,regMemory,fixMemory,REG);
                        while (true){
                            printf("next step? \n");
                            printf("1 - yes 0 - no \n");
                            int temp;
                            temp = scanf("%d", &temp);
                            if (temp == 1){
                                countCom++;
                            }
                            else{
                                workC = false;
                            }
                            break;
                        }
                    }else if (!strcmp(command[countCom].command, "NAND")){
                        regMemory[command[countCom].rrrCom.regA] = (regMemory[command[countCom].rrrCom.regB]
                                                                    & regMemory[command[countCom].rrrCom.regC]);
                        outDebugT(countCom,command[countCom].command, command[countCom].rrrCom.regA,
                                  command[countCom].rrrCom.regB, command[countCom].rrrCom.regC
                                ,regMemory,fixMemory,REG);
                        while (true){
                            printf("next step? \n");
                            printf("1 - yes 0 - no \n");
                            int temp;
                            temp = scanf("%d", &temp);
                            if (temp == 1){
                                countCom++;
                            }
                            else{
                                workC = false;
                            }
                            break;
                        };
                    }else if (!strcmp(command[countCom].command, "lui")){

                    }else if(!strcmp(command[countCom].command, "sw")){
                        fixMemory[regMemory[command[countCom].rriCom.regBB] + command[countCom].rriCom.imm] = regMemory[command[countCom].rriCom.regAA];
                        outDebugT(countCom,command[countCom].command, command[countCom].rriCom.regAA,
                                  command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                ,regMemory,fixMemory,REG);
                        while (true){
                            printf("next step? \n");
                            printf("1 - yes 0 - no \n");
                            int temp;
                            temp = scanf("%d", &temp);
                            if (temp == 1){
                                countCom++;
                            }
                            else{
                                workC = false;
                            }
                            break;
                        }
                    }else if (!strcmp(command[countCom].command, "lw")){
                        regMemory[command[countCom].rriCom.regAA] = fixMemory[regMemory[command[countCom].rriCom.regBB] + command[countCom].rriCom.imm];
                        outDebugT(countCom,command[countCom].command, command[countCom].rriCom.regAA,
                                  command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                ,regMemory,fixMemory,REG);
                        while (true){
                            printf("next step? \n");
                            printf("1 - yes 0 - no \n");
                            int temp;
                            temp = scanf("%d", &temp);
                            if (temp == 1){
                                countCom++;
                            }
                            else{
                                workC = false;
                            }
                            break;
                        }
                    }else if (!strcmp(command[countCom].command, "beg")){
                        if (regMemory[command[countCom].rriCom.regAA] == regMemory[command[countCom].rriCom.regBB]){
                            outDebugT(countCom,command[countCom].command, command[countCom].rriCom.regAA,
                                      command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                    ,regMemory,fixMemory,REG);
                            while (true){
                                printf("next step? \n");
                                printf("1 - yes 0 - no \n");
                                int temp;
                                temp = scanf("%d", &temp);
                                if (temp == 1){
                                    countCom = countCom + 1 + command[countCom].rriCom.imm;
                                }
                                else{
                                    workC = false;
                                }
                                break;
                            }
                        } else{
                            outDebugT(countCom,command[countCom].command, command[countCom].rriCom.regAA,
                                      command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                    ,regMemory,fixMemory,REG);
                            while (true){
                                printf("next step? \n");
                                printf("1 - yes 0 - no \n");
                                int temp;
                                temp = scanf("%d", &temp);
                                if (temp == 1){
                                    countCom++;
                                }
                                else{
                                    workC = false;
                                }
                                break;
                            }
                    }
                    }else if (!strcmp(command[countCom].command, "jair")){
                        regMemory[command[countCom].rriCom.regAA] = countCom + 1;
                        outDebugT(countCom,command[countCom].command, command[countCom].rriCom.regAA,
                                  command[countCom].rriCom.regBB, command[countCom].rriCom.imm
                                ,regMemory,fixMemory,REG);
                        while (true){
                            printf("next step? \n");
                            printf("1 - yes 0 - no \n");
                            int temp;
                            temp = scanf("%d", &temp);
                            if (temp == 1){
                                countCom = regMemory[command[countCom].rriCom.regBB];
                            }
                            else{
                                workC = false;
                            }
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    return 0;
}