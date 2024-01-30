#include <stdio.h>
#include <unistd.h>

#define BUCKET_SIZE 100 // Maximum capacity of the bucket
#define OUTPUT_RATE 10  // Rate of outgoing data

int main()
{
    int input_traffic[] = {20, 30, 50, 10, 25};               // Sample input traffic
    int n = sizeof(input_traffic) / sizeof(input_traffic[0]); // Number of elements in input_traffic
    int bucket_content = 0;                                   // Current content of the bucket

    for (int i = 0; i < n; i++)
    {
        // Simulating incoming traffic
        printf("Incoming traffic: %d\n", input_traffic[i]);

        // Adding incoming traffic to the bucket
        bucket_content += input_traffic[i];

        // If the bucket overflows, limit the content to the maximum size
        if (bucket_content > BUCKET_SIZE)
        {
            bucket_content = BUCKET_SIZE;
        }

        // Transmit data at the output rate
        int outgoing_data = (bucket_content > OUTPUT_RATE) ? OUTPUT_RATE : bucket_content;
        printf("Outgoing data: %d\n", outgoing_data);
        bucket_content -= outgoing_data;
    }

    return 0;
}