#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char NFA_FILE[100];
char buffer[100];

int zz=0;

struct DFA{
	char *states;
	int count;
	};

int last_index = 0;
	FILE *fp;
	int symbols;

	/*reset hash map*/
