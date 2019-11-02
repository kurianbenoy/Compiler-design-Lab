/*Credits: xJ*/ 
#include<iostream>

int getindex(char c)
{
	switch(c)
	{
		case 'i': return 0;
		case '+' : return 1;
		case 'x' : return 2;
		case '$' : return 3;
	}
}


int main()
{
	char str[100];
	
	std::cout<<"Enter the string\n";	
	scanf("%s",&str);

	int top=0;	
	
	char prec[4][4] = {
			' ','>', '>', '>',
			'<', '>', '<', '>',
			'<', '>', '>', '>',
			'<', '<', '<', ' ',
	};

	std::stack<char> mstack; 	
	mstack.push('$');
	int i=0;
	
	while(str[i] != '\0')
	{

		
		if(prec[getindex(mstack.top())][getindex(str[i])] == '>')
		{
			mstack.push(str[i]);
		}
			std::cout<<mstack.top();
	
		else if (prec[getindex(mstack.top())][getindex(str[i])] == '<')
		{
			mstack.pop();
			mstack.pop();
		}			
			std::cout<<mstack;
	}

	return 0;
}						

