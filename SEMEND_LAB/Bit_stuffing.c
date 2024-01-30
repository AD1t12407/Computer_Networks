#include <stdio.h>

int main()
{
    char in[100], out[100];
    int count = 0, i = 0, j = 0;
    printf("Enter the Input String : ");
    scanf("%s", in);

    while (in[i] != '\0')
    {
        if (in[i] == '1')
        {
            count++;
        }
        else
        {
            count = 0;
        }

        out[j++] = in[i++];

        if (count == 5)
        {
            out[j++] = '0';
            count = 0;
        }
    }

    out[j] = '\0'; // Ensure the output string is null-terminated

    printf("After Bit Stuffing : %s\n", out);
    return 0;
}