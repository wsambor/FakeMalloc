#include "memory.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

char memoryArea[1000];

int main()
{
    char* tab;

    memory_init(memoryArea, 1000);

	/*
	tab = (char* )memory_malloc(sizeof(char) * 2);
	tab[0] = 'a';
	tab[1] = 'b';

	int* tab2 = (int* )memory_malloc(sizeof(int) * 2);
	tab2[0] = 10;
	tab2[1] = 11;

	uint8_t* uint8_tab = (uint8_t*) memory_malloc(sizeof(uint8_t) * 4);
	uint8_tab[0] = 0xFF;
	uint8_tab[1] = 0x25;


	char* char_tab = (char* )memory_malloc(sizeof(char) * 4);
	char_tab[0] = 'x';
	char_tab[1] = 'y';
	char_tab[2] = 'z';
	char_tab[3] = 0x25;

	uint8_t* crash_it = (uint8_t* )memory_malloc(sizeof(uint8_t) * 1000);
	printf("\nBroken pointer: %p\n", crash_it);

    //memory_free(tab);

	memory_print();

	memory_free(char_tab);

	memory_print();

	char* char_tab_2 = (char* )memory_malloc(sizeof(char) * 2);
	char_tab_2[0] = 'x';
	char_tab_2[1] = 'y';

	memory_print();
	*/

	/*
	int* singleInt = (int* )memory_malloc(sizeof(int));
	singleInt[0] = 10;

	memory_print();

	char* doubleChar = (char* )memory_malloc(sizeof(char) * 2);
	doubleChar[0] = 'x';
	doubleChar[1] = 'y';

	memory_print();

	int* secSingleInt = (int* )memory_malloc(sizeof(int));
	secSingleInt[0] = 11;

	memory_print();

	memory_free(doubleChar);

	memory_print();

	char* dupa = (char* )memory_malloc(sizeof(char) * 2);
	dupa[0] = 'o';
	dupa[1] = 'p';

	memory_print();

	memory_free(secSingleInt);
	memory_free(dupa);

	int* kurwa = (int* )memory_malloc(sizeof(int));
	kurwa[0] = 255;

	memory_print();
	*/

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
