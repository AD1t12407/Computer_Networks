#include <stdio.h>
#include <string.h>

#define DATA_SIZE 16
#define CRC_WIDTH 16
#define POLYNOMIAL 0x11021

// Function to perform CRC calculation
unsigned short calculateCRC(char data[]) {
    unsigned short crc = 0;
    int i, j;

    // Iterate through each bit of the data
    for (i = 0; i < DATA_SIZE; i++) {
        // XOR the current CRC value with the next data bit
        crc ^= (data[i] << (CRC_WIDTH - 8));
        
        // Perform bitwise division
        for (j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ POLYNOMIAL;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int main() {
    char data[DATA_SIZE];
    unsigned short crcResult;

    // Input the data bits
    printf("Enter %d bits of data (0 or 1): ", DATA_SIZE);
    scanf("%s", data);

    // Ensure the input data has the correct size
    if (strlen(data) != DATA_SIZE) {
        printf("Error: Input data size should be %d bits.\n", DATA_SIZE);
        return 1;
    }

    // Calculate the CRC
    crcResult = calculateCRC(data);

    // Output the calculated CRC
    printf("Calculated CRC: %04X\n", crcResult);

    return 0;
}
