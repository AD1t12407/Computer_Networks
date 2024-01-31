#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void classifyAddress(char ip[], char subnetMask[])
{
    // Display CIDR information
    printf("CIDR Notation: %s\n", subnetMask);

    // Convert CIDR notation to subnet mask
    unsigned long subnetMaskInt = 0;
    sscanf(subnetMask, "/%*d.%*d.%*d.%*d", &subnetMaskInt);

    // Calculate network and host portions
    unsigned long ipAddress;
    sscanf(ip, "%lu", &ipAddress);

    unsigned long networkPortion = ipAddress & subnetMaskInt;
    unsigned long hostPortion = ipAddress & ~subnetMaskInt;

    // Display information
    printf("Network Portion: %lu\n", networkPortion);
    printf("Host Portion: %lu\n", hostPortion);
    printf("Subnet Mask: %s\n", subnetMask);
}

int main()
{
    char ip[16], subnetMask[18]; // 16 for IP, 18 for CIDR notation (e.g., "/24")

    // Get input from the user
    printf("Enter IP address: ");
    scanf("%15s", ip);

    printf("Enter subnet mask in CIDR notation (e.g., /24): ");
    scanf("%17s", subnetMask);

    // Display classless information
    classifyAddress(ip, subnetMask);

    return 0;
}
