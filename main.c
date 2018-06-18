#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "risc.h"


short int toDec (char *binaryCode){
    short int decValue = 0;
    for (int i = 0; i < 3; i ++){
        if (binaryCode[i] == '1'){
            decValue = (short) (decValue + pow(2, 2 - i));
        }
    }
    return decValue;
}

short int toDecForImm (char *binaryCode){
    short int decValue = 0;
    short int sign = -1;
    for (int i = 1; i < 7; i ++){
        if (binaryCode[i] == '1'){
            decValue = (short) (decValue + pow(2, 6 - i));
        }
    }
    if (binaryCode[0] == '1'){
        decValue = decValue * sign;
    }
    return decValue;
}

void outDebugF(int step, FILE* outFile, int opcode, short int regA, short int regB, short int regCI,
               short int *regMemory, short int *fixMemory){
    if (opcode == ADD){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "ADD reg[%d] reg[%d] 0000 reg[%d]\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (opcode == ADDI){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "ADDI reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (opcode == NAND){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "NAND reg[%d] reg[%d] 0000 reg[%d]\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (opcode == LUI){
    }else if(opcode == SW){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "sw reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (opcode == LW){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "lw reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (opcode == BEQ){
        fprintf(outFile, "Шаг номер %d \n", step);
        fprintf(outFile, "beg reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            fprintf(outFile, "Регистр[%d] = %d \n", i, regMemory[i]);
        }
        fprintf(outFile, "Данные в памяти машины RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            fprintf(outFile, "Адрес[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (opcode == JAIR){
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

void outDebugT(int step,int opcode, short int regA, short int regB, short int regCI,
               short int *regMemory, short int *fixMemory){
    if (opcode == ADD){
        printf("step %d \n", step);
        printf("ADD reg[%d] reg[%d] 0000 reg[%d]\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf( "reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf( "add[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (opcode == ADDI){
        printf( "step %d \n", step);
        printf("ADDI reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf( "reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf( "add[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (opcode == NAND){
        printf("step %d \n", step);
        printf("NAND reg[%d] reg[%d] 0000 reg[%d]\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf( "reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf("add[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (opcode == LUI){
    }else if(opcode == SW){
        printf("step %d \n", step);
        printf("sw reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf("reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf("add[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (opcode == LW){
        printf("step %d \n", step);
        printf("lw reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf("reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf("add[%d] = %d \n", i, fixMemory[i]);
        }

    }else if (opcode == BEQ){
        printf("step %d \n", step);
        printf("beg reg[%d] reg[%d]  imm = %d\n",regA, regB, regCI);
        for (int i = 0; i < REG; i++){
            printf("reg[%d] = %d \n", i, regMemory[i]);
        }
        printf("memory in RISC \n");
        for (int i = 0; i <= fixMemory[1]; i++){
            printf( "add[%d] = %d \n", i, fixMemory[i]);
        }
    }else if (opcode == JAIR){
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

void init (FILE* file, short int* fixMemory){
   int a;
   fscanf(file,"%d", &a);
   int maxSize = a;
   for (int i = 0; i <= maxSize; i++){
       fscanf(file,"%d", &a);
       fixMemory[i] = a;
   }
}
int simRISC(int countCom, int command, short int regA, short int regB, short int regCI,
             short int* fixMemory, short int* regMemory){
    switch (command){
        case ADD :{
            regMemory[regA] = regMemory[regB] + regMemory[regCI];
            countCom++;
            break;
        }
        case ADDI :{
            regMemory[regA] = regMemory[regB] + regCI;
            countCom++;
            break;
        }
        case NAND :{
            regMemory[regA] = (regMemory[regB] & regMemory[regCI]);
            countCom++;
            break;
        }
        case LUI :{
            break;
        }
        case SW :{
            fixMemory[regMemory[regB] + regCI] = regMemory[regA];
            countCom++;
            break;
        }
        case LW :{
            regMemory[regA] = fixMemory[regMemory[regB] + regCI];
            countCom++;
            break;
        }
        case BEQ :{
            if (regMemory[regA] == regMemory[regB]){
                countCom = countCom + 1 + regCI;
            } else{
                countCom++;
            }
            break;
        }
        case JAIR :{
            regMemory[regA] = countCom + 1;
            countCom = regMemory[regB];
            break;
        }
    };
    return countCom;
}
int nextStep(){
    int temp;
    while (true){
        printf("next step? \n");
        printf("1 - yes 0 - no \n");
        scanf("%d", &temp);
        break;
    }
    return temp;
}
int main(){
    printf("RISC machine simulator \n");
    //Инициализация входных файлов
    char tempStr1[MAXC];
    char tempStr2[MAXC];
    printf("input initFile name\n");
    scanf("%99s",tempStr1);*/
    inName = "initMachine.txt";
    printf("input commandFile name\n");
    scanf("%99s",tempStr2);*/
    fileName = "command.txt";
    short int *fixMemory = malloc(sizeof(short int) * MEMORY_SIZE);
    struct command* command = malloc(sizeof(struct command) * MAX_COMMAND);
    short int regMemory[REG];
    for (int i = 0; i < REG; i++){
        regMemory[i] = 0;
    }

    int countCommand = 0;
    char *opcode;
    char *arg1;
    char *arg2;
    char *arg3;
    int line = 0;
    _Bool workC = true;
    char inputCom[MAXLENGTHLINE];

    FILE *commandInput;
    commandInput = fopen(fileName, "rt");
    //считывание команд из файла и парсер их
    while (!feof(commandInput)){
        fgets(inputCom, sizeof(inputCom), commandInput);
        opcode= strtok(inputCom, " ");
        if (!strcmp(opcode, "000")){ //ADD
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = ADD;
            command[line].regA = toDec(arg1);
            command[line].regB = toDec(arg2);
            command[line].regCI = toDec(arg3);
            line++;

        }else if (!strcmp(opcode, "001")){ //ADDI
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = ADDI;
            command[line].regA = toDec(arg1);
            command[line].regB = toDec(arg2);
            command[line].regCI= toDecForImm(arg3);
            line++;
        }else if (!strcmp(opcode, "010")){ //NAND
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = NAND;
            command[line].regA = toDec(arg1);
            command[line].regB = toDec(arg2);
            command[line].regCI = toDec(arg3);
            line++;
        }else if (!strcmp(opcode, "011")){ //lui
            arg1 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = LUI;
            command[line].regA = toDec(arg1);
            command[line].regB = 0;
            command[line].regCI = toDec(arg3);
            line++;
        }else if(!strcmp(opcode, "101")){ //sw
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = SW;
            command[line].regA = toDec(arg1);
            command[line].regB = toDec(arg2);
            command[line].regCI= toDecForImm(arg3);
            line++;
        }else if (!strcmp(opcode, "100")){ //lw
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = LW;
            command[line].regA = toDec(arg1);
            command[line].regB = toDec(arg2);
            command[line].regCI= toDecForImm(arg3);
            line++;

        }else if (!strcmp(opcode, "110")){ //beg
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = BEQ;
            command[line].regA = toDec(arg1);
            command[line].regB = toDec(arg2);
            command[line].regCI= toDecForImm(arg3);
            line++;
        }else if (!strcmp(opcode, "111")){ //jair
            arg1 = strtok(NULL, " ");
            arg2 = strtok(NULL, " ");
            arg3 = strtok(NULL, "\n");
            command[line].command = JAIR;
            command[line].regA = toDec(arg1);
            command[line].regB = toDec(arg2);
            command[line].regCI= toDecForImm(arg3);
            line++;
        }else if (!strcmp(opcode, "exit")){
            countCommand = line;
        }
    }

    //Инициаизация памяти машины
    FILE *initInput;
    initInput = fopen(inName, "rt");
    init(initInput, fixMemory);

    countCom = 0;

    while (workC){
        switch (menu()){
            case 1: {//Full work machine
                while (countCom != countCommand){
                    countCom = simRISC(countCom, command[countCom].command,
                            command[countCom].regA, command[countCom].regB,command[countCom].regCI,
                            fixMemory, regMemory);
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
            case 2:{
                char *outDebugName = "outDebug.txt";
                FILE *outDebug;
                outDebug = fopen(outDebugName, "wt");
                int stepCount = 0;
                printf("Count Step \n");
                int temp;
                scanf("%d", &temp);
                stepCount = temp;
                countCom = 0;
                int stepCounter = 0;
                while (stepCounter != stepCount){
                    countCom = simRISC(countCom, command[countCom].command,
                                       command[countCom].regA, command[countCom].regB,command[countCom].regCI,
                                       fixMemory, regMemory);
                    outDebugF(stepCounter,outDebug,command[countCom].command, command[countCom].regA,
                              command[countCom].regB, command[countCom].regCI
                            ,regMemory,fixMemory);
                    stepCounter++;
                    if (countCom == countCommand){
                        break;
                    }
                }
                workC = false;
                break;
            }
            case 3:{
                printf("Excavate with \n");
                int temp;
                scanf("%d", &temp);
                int stepCounter = 0;
                while (countCom != temp){
                    countCom = simRISC(countCom, command[countCom].command,
                                       command[countCom].regA, command[countCom].regB,command[countCom].regCI,
                                       fixMemory, regMemory);
                }
                while (countCom != countCommand){
                    if (nextStep() == 1){
                        countCom = simRISC(countCom, command[countCom].command,
                                           command[countCom].regA, command[countCom].regB,command[countCom].regCI,
                                           fixMemory, regMemory);
                        outDebugT(stepCounter,command[countCom].command, command[countCom].regA,
                                  command[countCom].regB, command[countCom].regCI
                                ,regMemory,fixMemory);
                        stepCounter++;
                    }else{
                        break;
                    }
                    if (countCom == countCommand){
                        printf("STOP\n");
                        break;
                    }
                }
                workC = false;
                break;
            }
            case 4:{
                char *outDebugName = "outDebug.txt";
                FILE *outDebug;
                outDebug = fopen(outDebugName, "wt");
                int stepCount = 0;
                printf("Count Step \n");
                int temp;
                scanf("%d", &temp);
                stepCount = temp;
                countCom = 0;
                int stepCounter = 0;
                while (stepCounter != stepCount){
                    countCom = simRISC(countCom, command[countCom].command,
                                       command[countCom].regA, command[countCom].regB,command[countCom].regCI,
                                       fixMemory, regMemory);
                    stepCounter++;
                    if (countCom == countCommand){
                        break;
                    }
                }
                outDebugF(stepCounter,outDebug,command[countCom].command, command[countCom].regA,
                          command[countCom].regB, command[countCom].regCI
                        ,regMemory,fixMemory);
                workC = false;
                break;
            }
        }
    }
    free(fixMemory);
    free(command);
    return 0;
}

