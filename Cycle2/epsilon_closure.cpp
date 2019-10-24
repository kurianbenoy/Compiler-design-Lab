#include<stdio.h>
#include<stdlib.h>

struct state
{
	int input;
	int next_input;
};

int main()
{
	int na, t, st;
  	char alphabet[25];	
	
	printf("Enter no of Alphabets \n Enter no of states \n Enter no of transition\n");
	scanf("%d%d%d", &na, &t, &st); 
	printf("Enter the alphabets\n");
	for(int i=0;i<na;i++)
	{
		alphabet[i] = getchar();
		getchar();
	}

}	
