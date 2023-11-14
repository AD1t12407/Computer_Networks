// importing libraries
#include<stdio.h>
#include<stdlib.h>

// defining max size
#define MAX 10

int main(){
    // declaring/initializing arrays: for input, stuffing, unstuffing
    char input[MAX], stuff[MAX], unstuff[MAX];
    // declaring iterative variables
    int count = 0, i = 0, j = 0;

    // inputting the string (character array: input)
    printf("Enter the input string with only 0's and 1's: \n");
    scanf("%s", input);

    // iterate until the null character
    while (input[i] != '\0'){
        if (input[i] == '0'){
            stuff[j] = input[i];
            i++;
            j++;
        }
        else{
            while (input[i] == '1' && count != 5){
                count++;
                stuff[j] = input[i];
                i++;
                j++;
            }
            if (count == 5){
                stuff[j] = '0';
                j++;
            }
            count = 0;
        }
    }
    stuff[j] = '\0';
    printf("\n The stuffed character string:\n %s", stuff);

    i = 0;
    j = 0;
    count = 0;

    while (stuff[i] != '\0'){
        if (stuff[i] == '0'){
            unstuff[j] = stuff[i];
            i++;
            j++;
        }
        else{
            while (stuff[i] == '1' && count != 5){
                count++;
                unstuff[j] = stuff[i];
                i++;
                j++;
            }
            if (count == 5){
                i++;
            }
            count = 0;
        }
    }
    unstuff[j] = '\0';
    printf("\n The unstuffed character string:\n %s", unstuff);

    return 0;
}
