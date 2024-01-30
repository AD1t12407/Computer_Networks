#include <stdio.h>
#include <string.h>

void crc(char data[], char divisor[], char result[])
{
    int data_len = strlen(data);
    int divisor_len = strlen(divisor);
    int result_len = data_len + divisor_len - 1;

    // Copy data to result initially
    strcpy(result, data);

    for (int i = 0; i < data_len; i++)
    {
        if (result[i] == '1')
        {
            for (int j = 0; j < divisor_len; j++)
            {
                result[i + j] = result[i + j] == divisor[j] ? '0' : '1';
            }
        }
    }
}

int main()
{
    char data[100], divisor[10], encoded_data[110];
    printf("Enter the message: ");
    scanf("%s", data);
    printf("Enter the divisor: ");
    scanf("%s", divisor);

    crc(data, divisor, encoded_data);

    printf("\nEncoded Message (Data + CRC): %s\n", encoded_data);

    // Simulate reception with possible errors
    char received_data[110];
    printf("\nEnter the received message: ");
    scanf("%s", received_data);

    char remainder[10];
    crc(received_data, divisor, remainder);

    int error_detected = 0;
    for (int i = 0; i < strlen(remainder); i++)
    {
        if (remainder[i] == '1')
        {
            error_detected = 1;
            break;
        }
    }

    if (error_detected)
    {
        printf("Error detected in the received message!\n");
    }
    else
    {
        printf("No errors detected in the received message.\n");
    }

    return 0;
}