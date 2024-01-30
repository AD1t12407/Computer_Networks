#include <stdio.h>
int main()
{
    char msg[100];
    int i, size, count = 0;
    printf("Enter the Message: ");
    scanf("%99s", msg); // Limit input size to avoid buffer overflow
    printf("Enter the Frame Size: ");
    scanf("%d", &size);

    printf("\nMessage =\n ");

    for (i = 0; msg[i] != '\0'; i++, count++)
    {
        if (count == size)
        {
            printf("\n\n");
            count = 0;
        }
        printf("%c", msg[i]);
    }

    printf("\n\n");

    return 0;
} // Indicate successful execution
