digit [0-9]
letter [A-Za-z]

%{
    int count;
%}

%%

{letter}({letter}|{digit})* count++;
%%

int main(void) 
{
    yylex();
    printf("No of identifiers = %d", count);
}
