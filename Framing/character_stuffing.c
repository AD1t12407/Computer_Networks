// importing libraries
#include<stdio.h>
#include<string.h>

//define max
#define MAX 10
#define FLAG '#'
#define ESC '@'

int main(){
    // initialization of variables, arrays
    int i,j,length;
    char input[MAX],stuff[MAX],destuff[MAX];

    printf("enter the input character array to be stuffed ");
    scanf("%s",input);
    length=strlen(input);

    //print the length of the input array
    printf("the length of the input string: %d\n",length);

    stuff[0]=FLAG;

    for(i=0,j=1;input[i]!='\0';i++){
        if(input[i]!=FLAG && input[i]!=ESC){
            stuff[j++]=input[i];
        }
        if(input[i]==FLAG ||input[i]==ESC){
            stuff[j++]=ESC;
            stuff[j++]=input[i];
        }
    }
    stuff[j++]=FLAG;
    stuff[j]='\0';

    printf("stuffed msg:%s\n",stuff);
    printf("destuffing the message");
    for(int i=0;i<8;i++)
        printf(".");
    length=strlen(stuff);
    printf("the length of the stuff string:%d",length);
    for(i=0,j=1;stuff[i]!='\0';i++){
        if(stuff[i]!=FLAG && stuff[i]!=ESC){
            destuff[j++]=stuff[i];
        }
        if(stuff[i]==ESC){
            i++;
            destuff[j++]=stuff[i];

        }
    }
    destuff[j]='\0';
    printf("destuffed msg:%s\n",destuff);


    
    

    return 0;   
    }
