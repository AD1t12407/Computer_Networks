#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void classifyAddress(char ip[])
{
    // Parse the first octet of the IP address
    int firstOctet;
    sscanf(ip, "%d", &firstOctet);

    // Determine the class based on the first octet
    if (firstOctet >= 1 && firstOctet <= 126)
    {
        printf("Class A\n");
        printf("Default Subnet Mask: 255.0.0.0\n");
    }
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        printf("Class B\n");
        printf("Default Subnet Mask: 255.255.0.0\n");
    }
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        printf("Class C\n");
        printf("Default Subnet Mask: 255.255.255.0\n");
    }
    else
    {
        printf("Invalid IP address\n");
    }
}

int main()
{
    char ip[16];

    // Get input from the user
    printf("Enter IP address: ");
    scanf("%15s", ip);

    // Display classful information
    classifyAddress(ip);

    return 0;
}
