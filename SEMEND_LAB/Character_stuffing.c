#include <stdio.h>
#define flag '$'
#define esc '@'

int main()
{
    char in[100], out[100];
    int i = 0, j = 0;
    printf("Enter the Input String : ");
    scanf("%99s", in); // Limit input size to avoid buffer overflow

    out[j++] = flag; // Starting of string

    while (in[i] != '\0')
    {
        if (in[i] == flag || in[i] == esc)
        {
            out[j++] = esc; // Add escape character before flag or esc
        }

        out[j++] = in[i++];
    }

    out[j++] = flag; // For end of the string
    out[j] = '\0';   // Ensure the output string is null-terminated

    printf("After Character Stuffing : %s\n", out);
    return 0;
}
