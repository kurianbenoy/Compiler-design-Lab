/*Credits: xJ*/ #include<iostream>

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

	stack<char> mstack; 	
	mstack.push('$');
	int i=0;
	
	while(str[i] != '\0')
	{
		if(pred[mstack.top()]:w
		

		std::cout<<getindex(str[i]);
		if(stack[top] == prec 

		i++;
	}

	return 0;
}						

