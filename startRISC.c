#include "risc.h"

int menu()
{
	int end = 4;
	int start = 1;
	int temp ;
    int  answer;
	printf( "1. FULL work RISC \n"
            "2. excuvate exact steps() \n"
			"3. excuvate step by step \n"
            "4. excuvate exact steps without outDebugFile \n"
			);
	while (true)
	{
		printf ("\n Input command: ");
		answer = scanf("%d", &temp);
        if (answer == 1 && (temp >= start && temp <= end))
            break;
        fflush(stdin);
		printf("Error\n");
	}
	return temp;
}

