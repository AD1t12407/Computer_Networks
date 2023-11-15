#include<stdio.h>
//#include<conio.h>
int add(int, int);
int com(int);
int main()
{
    int i, j, dl, dil;
    int data1[10], data2[10], newdata[10], comp[10], checksum[10];
    printf("\n Enter the data length=");
    scanf("%d", &dl);
    printf("\n Enter the data1 : \n");
    for (i = 0; i < dl; i++)
        scanf("%d", &data1[i]);
    printf("\n Enter the data2 : \n");
    for (i = 0; i < dl; i++)
        scanf("%d", &data2[i]);
    for (i = dl - 1; i >= 0; i--)
    {
        newdata[i] = add(data1[i], data2[i]);
    }
 
    printf("\n\n Data 1        : ");
    for (i = 0; i < dl; i++)
        printf("%d", data1[i]);
    printf("\n Data 2        : ");
    for (i = 0; i < dl; i++)
        printf("%d", data2[i]);
 
    printf("\n\n The new data is : ");
    for (i = 0; i < dl; i++)
    {
        printf("%d", newdata[i]);
    }
    printf("\n Checksum : ");
    for (i = 0; i < dl; i++)
    {
        checksum[i] = com(newdata[i]);
        printf("%d", checksum[i]);
    }
 
    printf("\n\n Receiver Side : \n");
    printf("\n Data : ");
    for (i = 0; i < dl; i++)
        printf("%d", data1[i]);
    printf(" ");
    for (i = 0; i < dl; i++)
        printf("%d", data2[i]);
    printf(" ");
    for (i = 0; i < dl; i++)
        printf("%d", checksum[i]);
 
    printf("\n Addition : ");
    for (i = dl - 1; i >= 0; i--)
    {
        newdata[i] = add(newdata[i], checksum[i]);
    }
    for (i = 0; i < dl; i++)
    {
        printf("%d", newdata[i]);
    }
    printf("\n  Compliment : ");
    for (i = 0; i < dl; i++)
    {
        comp[i] = com(newdata[i]);
        printf("%d", comp[i]);
    }
}
 
int add(int x, int y)
{
    static int carry = 0;
    if (x == 1 && y == 1 && carry == 0)
    {
        carry = 1;
        return 0;
    }
    else if (x == 1 && y == 1 && carry == 1)
    {
        carry = 1;
        return 1;
    }
    else if (x == 1 && y == 0 && carry == 0)
   {
        carry = 0;
        return 1;
    }
    else if (x == 1 && y == 0 && carry == 1)
    {
        carry = 1;
        return 0;
    }
    else if (x == 0 && y == 1 && carry == 0)
    {
        carry = 0;
        return 1;
    }
    else if (x == 0 && y == 1 && carry == 1)
    {
        carry = 1;
        return 0;
    }
    else if (x == 0 && y == 0 && carry == 0)
    {
        carry = 0;
        return 0;
    }
    else
    {
        carry = 0;
        return 1;

    }
    return 0;
}
int com(int a)
{
    if (a == 0)
        return 1;
    else
        return 0;
}