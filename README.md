# Computer_Networks

# Computer Networks Lab Programs

This Git repository contains lab programs related to computer networks, covering various concepts such as bit stuffing, character stuffing, CRC, checksum, and the Go-Back-N protocol. Each program directory includes detailed explanations of the theoretical concepts, algorithm implementations, and usage instructions.

## Table of Contents

1. [Bit Stuffing](#bit-stuffing)
2. [Character Stuffing](#character-stuffing)
3. [CRC (Cyclic Redundancy Check)](#crc)
4. [Checksum](#checksum)
5. [Go-Back-N Protocol](#go-back-n-protocol)

## Bit Stuffing

### Theoretical Concept

Bit stuffing is a technique used in data communication to prevent the misinterpretation of control characters. The algorithm involves the insertion of a '0' bit after a predefined pattern of consecutive '1' bits. This ensures proper synchronization between the sender and receiver.

### Algorithm

1. **Input:** Binary data stream.
2. **Output:** Binary data stream with bit stuffing applied.

## Character Stuffing

### Theoretical Concept

Character stuffing is a method used in text-based data transmission to prevent the misinterpretation of control characters. It involves inserting an escape character before specific characters, ensuring data integrity.

### Algorithm

Input: Text data stream.
Output: Text data stream with character stuffing applied

## CRC (Cyclic Redundancy Check)

### Theoretical Concept

CRC is an error-detection technique that involves polynomial division. It is commonly used in network communication to ensure data integrity by appending a remainder (CRC) to the transmitted data.

### Algorithm

Input: Binary data stream, polynomial divisor.
Output: Binary data stream with CRC appended.

Predicted Input/Output
Example
Input:

11011010101110111100101
Polynomial Divisor:

1011
Output:

11011010101110111100101110

## Checksum

### Theoretical Concept

Checksum is a simple error-detection technique involving the addition of all data in a message to generate a fixed-size value. It is used in various communication protocols to ensure data integrity.

### Algorithm

Input: Binary data stream.
Output: Binary data stream with checksum appended.

Predicted Input/Output Example
Input:

11011010101110111100101
Output:

11011010101110111100101100

## Go-Back-N Protocol

### Theoretical Concept

Go-Back-N is a sliding window protocol for reliable communication in computer networks. It allows the sender to transmit multiple frames before receiving an acknowledgment, enhancing overall efficiency.

### Algorithm

Input: Frames to be transmitted.
Output: Acknowledgment and retransmission based on protocol rules.

Predicted Input/Output
Example
Input:

mathematica

Frame 1, Frame 2, Frame 3
Output:

mathematica

Frame 1 ACK, Frame 2 ACK, Frame 3 ACK
