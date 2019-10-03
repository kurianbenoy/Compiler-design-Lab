#include<stdio.h>
#include<stdlib.h>

struct State
{
	int st;
	struct State *link;
};

static int e_closure[20][20] = {0};
static int set[20], n_alpha, n_states, n_transition, c,r,s, buffer[20];
char alphabet[20];
struct State* transition[20][20] = {NULL};

void Findclosure(int x, int sta)
{
	struct State *temp;
	//write function later
	int i;
	if(buffer[x])
		return;
	e_closure[sta][c++] = x;
	buffer[x] = 1;
	if(alphabet[n_alpha-1]=='e' && transition[x][n_alpha-1]!=NULL)
	{
		temp = transition[x][n_alpha-1];
		while(temp != NULL)
		{
			Findclosure(temp->st, sta);
			temp = temp->link;
		}
	}
}

int findalpha(char c)
{
        int i;
        for(i=0;i<n_alpha;i++)
        if(alphabet[i]==c)
                return i;
        return(999);
}


void insert_t(int r, char c, int s)
{
	int j;
	struct State *temp;
	j = findalpha(c);// what is Find alpha??
	if(j==999)
	{
		printf("ERRROr what");
		exit(0);
	}
	temp = (struct State*)malloc(sizeof(struct State));
	temp->st = s;
	temp->link = transition[r][j];
	transition[r][j] = temp;
}


 void print_e_closure(int i)
{
        int j;
        printf("{");
        for(j=0;e_closure[i][j]!=0;j++)
        printf("q%d,",e_closure[i][j]);
        printf("}");
}

void main()
{
	int i, j, k;
	struct State *temp;
	
	static int set[20], n_alpha, n_states, n_transition, c,r,s, buffer[20];
	char alphabet[20];

	// Take the input ALPHABET
	printf("Enter the no of Alphabets\n");
	scanf("%d", &n_alpha);
	

	// Enter the alphabets for transition
	printf("Enter the alphabets\n");
	for(int i=0;i<n_alpha; i++)
	{
		alphabet[i] = getchar();
		getchar();
	}

	printf("Enter the no of states\n");
	scanf("%d", &n_states);

	printf("Enter the no of Transitions\n");
	scanf("%d",&n_transition);
	
	printf("ENter transitions\n");
	for(int i=0;i<n_transition; i++)
	{
		scanf("%d%c%d", &r, &c,&s);
		insert_t(r, c, s);
	}

	printf("\n E-closures of States \n");
	for(i=1;i<n_states;i++)
	{
		c = 0;
		for(int j=0;j<20;j++)
		{
			buffer[j] = 0;
			e_closure[i][j] = 0;
		}
		Findclosure(i,i);
		printf("E- closure(q%d): ",i);
		print_e_closure(i);
	}
}


