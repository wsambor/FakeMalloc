#include "memory.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

char memoryArea[1000];

int main()
{
    char* tab;

    memory_init(memoryArea, 1000);

	
	int* dupa1 = (int* )memory_malloc(sizeof(int));
	dupa1[0] = 255;

	char* dupa2 = (char* )memory_malloc(sizeof(char) * 2);
	dupa2[0] = 'c';
	dupa2[1] = 'h';

	char* dupa3 = (char* )memory_malloc(sizeof(char) * 2);
	dupa3[0] = 'x';
	dupa3[1] = 'y';

	char* dupa4 = (char* )memory_malloc(sizeof(char) * 2);
	dupa4[0] = 'a';
	dupa4[1] = 'b';

	char* dupa5 = (char* )memory_malloc(sizeof(char) * 2);
	dupa5[0] = 'o';
	dupa5[1] = 'o';

	char* dupa6 = (char* )memory_malloc(sizeof(char) * 2);
	dupa6[0] = 'v';
	dupa6[1] = 'v';

	char* dupa7 = (char* )memory_malloc(sizeof(char) * 2);
	dupa7[0] = 'q';
	dupa7[1] = 'w';

	memory_print();


	memory_free(dupa4);
	memory_free(dupa6);
	memory_free(dupa5);
	memory_free(dupa1);


	uint8_t* dupa8 = (uint8_t* )memory_malloc(sizeof(uint8_t) * 6);
	dupa8[0] = 0xFF;
	dupa8[5] = 0xFE;

	memory_print();

	int* dupa9 = (int* )memory_malloc(sizeof(int));
	dupa9[0] = 1000;

	char* dupa10 = (char* )memory_malloc(sizeof(char) * 300);
	dupa10[145] = 'X';
	dupa10[146] = 'Y';
	dupa10[147] = 'Z';

	memory_print();

    return 0;
}
