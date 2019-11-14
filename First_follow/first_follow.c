#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n,m,p,i=0,j=0;
char arr[100][100],f[10];
void first(char c){
    int k;
    if(!isupper(c))
        f[m++]=c;
    for(k=0;k<n;k++){
        if(arr[k][0]==c){
            if(islower(arr[k][2]))
                f[m++]=arr[k][2];
            else
                first(arr[k][2]);
        }
    }
}

void follow(char c){
    if(arr[0][0]==c)
        f[m++]='$';
    for(i=0;i<n;i++){
        for(j=2;j<strlen(arr[i]);j++){
            if(arr[i][j]==c){
                if(arr[i][j+1]!='\0')
                    first(arr[i][j+1]);
                if(arr[i][j+1]=='\0' && c!=arr[i][0])
                    follow(arr[i][0]);
                
            }
        }

    }
}
int main(){
    int i,z;
    char c,ch;
    printf("Enter the number of production:\n");
    scanf("%d",&n);
    
    printf("Enter the productions:\n");
    for(i=0;i<n;i++)
        scanf("%s%c",arr[i],&ch);
    do{
        m=0;
        printf("Enter the lements whose first and follow to be found");
        scanf("%c",&c);
        first(c);
        printf("First(%c)={",c);
        for(i=0;i<m;i++)
            printf("%c",f[i]);
        printf("}\n");
        strcpy(f," ");
        m=0;
        follow(c);
        printf("Follow(%c)={",c);
        for(i=0;i<m;i++)
            printf("%c",f[i]);
        printf("}\n");
        printf("Continue(0/1)?");
        scanf("%d%c",&z,&ch);
    }while(z==1);
}
