#include <stdio.h>
int main()
{
    char msg[100];
    int i = 0, j, size;
    printf("Enter the Message: ");
    scanf("%99s", msg); // Limit input size to avoid buffer overflow

    while (msg[i] != '\0')
    {
        printf("Enter the Frame Size: ");
        scanf("%d", &size);

        printf("Message = \n");
        for (j = i; j < i + size && msg[j] != '\0'; j++)
        {
            printf("%c", msg[j]);
        }
        printf("\n");

        i += size;
    }

    printf("\n\n");

    return 0;
}
