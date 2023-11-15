unsigned short calculateCRC(char data[]) {
    unsigned short crc = 0;
    int i, j;

    // Iterate through each bit of the data
    for (i = 0; i < DATA_SIZE; i++) {
        // XOR the current CRC value with the next data bit
        crc ^= (data[i] << (CRC_WIDTH - 8));

        // Perform bitwise division
        for (j = 0; j < 8; j++) {
            if (crc & 0x800) {
                crc = (crc << 1) ^ POLYNOMIAL;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}