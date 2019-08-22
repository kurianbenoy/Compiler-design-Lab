#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int isKeyword(char buffer[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	int i, flag = 0;
	
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}
	
	return flag;
}
 
int main(){
	char ch, buffer[15], operators[] = "+-*/%=";
	char cop[15], cke[100][1000], ccr[25][100];
	char *ckey[100], *cchar[100];
	FILE *fp;
	int i,j=0;
	static int il=0,ik=0,ii=0;

	fp = fopen("input.txt","r");

	if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}

	while((ch = fgetc(fp)) != EOF){
   		for(i = 0; i < 6; ++i){
   			if(ch == operators[i]){
					cop[++il]= ch;
//	   				printf("%c is operator\n", ch);
	   		}
   		}
   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;
   				if(isKeyword(buffer) == 1){
					ckey[++ik] = buffer;
   					printf("%s is keyword\n", buffer);
					}
   				else
				{
					cchar[++ii] = buffer;
   					printf("%s is identifier\n", buffer);
				}
			}
   		
	}
	printf("%d\n%d\n%d\n", il, ik, ii);
	printf("Operators of the input\n");
		for(int i=0;i<=il;i++){
		printf("%s",cop[i]);
		
	 }
printf("\nKerywords of a string\n");

for(int i=0;i<=ik;i++){
		printf("%s", *ckey[i]);	
	}
printf("Identifiers of string\n");
for(int i=0;i<=ii;i++)
	{
		printf("%s", *cchar[i]);
	}
	fclose(fp);
	
	return 0;
}
