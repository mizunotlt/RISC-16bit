all: kurs
kurs : main.o startRISC.o 
	gcc  -pedantic -Wall -Wextra  -o kurs main.o startRISC.o 

main.o : main.c
	gcc -std=c11  -pedantic -Wall -Wextra -c -o main.o main.c

startRISC.o : startRISC.c
	gcc -std=c11  -pedantic -Wall -Wextra -c -o startRISC.o startRISC.c


