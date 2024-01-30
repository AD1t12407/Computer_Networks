#include <stdio.h>

void main()
{
    int n, frame[100], ack;

    // Input the frame size
    printf("Enter The Frame size : ");
    scanf("%d", &n);

    // Initialize and send frames
    for (int i = 0; i < n; i++)
    {
        frame[i] = i + 1;
        printf("Frame %d sent data : %d\n", i, frame[i]);
    }

    // Prompt user for the frame whose acknowledgment is not received
    printf("\nEnter the frame whose acknowledgment is not received : ");
    scanf("%d", &ack);

    // Resend the frame for which acknowledgment is not received
    printf("Frames sent again : \n");
    printf("Frame %d sent data : %d\n", ack, frame[ack]);
}
