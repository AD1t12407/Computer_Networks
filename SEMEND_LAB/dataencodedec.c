#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    int i, ch, lp;
    char cipher[50], plain[50], key[50];
    while (1)
    {
        printf("\n-----MENU ----\n");
        printf("\n1:Data Encryption\t\n\n2:Data Decryption\t\n\n3:Exit");
        printf("\n\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nData Encryption");
            printf("\nEnter the plain text:");
            fflush(stdin);
            scanf("%s", &plain);
            printf("\nEnter the encryption key:");
            scanf("%s", &key);
            lp = strlen(key);
            for (i = 0; plain[i] != '\0'; i++)
                cipher[i] = plain[i] ^ lp;
            cipher[i] = '\0';
            printf("\nThe encrypted text is:");
            puts(cipher);
            break;
        case 2:
            printf("\nData decryption");
            for (i = 0; cipher[i] != '\0'; i++)
                plain[i] = cipher[i] ^ lp;
            printf("\nDecrypted text is:");
            puts(plain);
            break;
        case 3:
            exit(0);
        }
    }
}