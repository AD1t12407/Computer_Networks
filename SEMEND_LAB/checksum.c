#include <stdio.h>

void calculateChecksum(char data[], char checksum[], int blockLength)
{
    int carry = 0;
    for (int i = 0; data[i] != '\0'; ++i)
    {
        int bitSum = (data[i] - '0') + (checksum[i] - '0') + carry;
        checksum[i] = (bitSum % 2) + '0';
        carry = bitSum / 2;
    }
    if (carry)
    {
        checksum[blockLength] = '1';
        checksum[blockLength + 1] = '\0';
    }
}

int main()
{
    char message[100], checksum[10] = "0000000000";
    int blockLength;
    printf("Enter the binary message: ");
    scanf("%s", message);

    printf("Enter the block length: ");
    scanf("%d", &blockLength);

    int i = 0;
    while (message[i] != '\0')
    {
        calculateChecksum(&message[i], checksum, blockLength);
        i += blockLength;
    }

    printf("Checksum: %s\n", checksum);

    return 0;
}