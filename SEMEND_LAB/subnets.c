#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void calculateSubnets(char ip[], char subnetMask[], int n)
{
    // Parse IP address and subnet mask
    uint32_t ipAddress, subnetMaskInt;
    sscanf(ip, "%u", &ipAddress);
    sscanf(subnetMask, "%u", &subnetMaskInt);

    // Calculate subnet size
    uint32_t subnetSize = (1 << (32 - __builtin_clz(subnetMaskInt))) / n;

    // Display subnets
    printf("Subnets:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Subnet %d: %u.%u.%u.%u/%s\n", i + 1,
               (ipAddress & subnetMaskInt) >> 24,
               (ipAddress & (subnetMaskInt << 8)) >> 16,
               (ipAddress & (subnetMaskInt << 16)) >> 8,
               ipAddress & (subnetMaskInt << 24),
               subnetMask);
        ipAddress += subnetSize;
    }
}

int main()
{
    char ip[16], subnetMask[16];
    int n;

    // Get input from the user
    printf("Enter IP address: ");
    scanf("%15s", ip);

    printf("Enter subnet mask: ");
    scanf("%15s", subnetMask);

    printf("Enter the number of subnets: ");
    scanf("%d", &n);

    // Display subnets
    calculateSubnets(ip, subnetMask, n);

    return 0;
}
