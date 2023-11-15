#include<stdio.h>
int main(){
    int ws,sent=0,ack,i;
    printf("enter the window size:\n");
    scanf("%d",&ws);
    while(1){
        for(i=0;i<ws;i++){
            printf("Frame %d has been transmitted",sent);
            sent++;
            if(sent==ws)
            break;
        }
        printf("\n enter the last acknowledgment\n");
        scanf("%d",&ack);
        if(ack==ws)
        break;
        else
        sent=ack;

    }
    return 0;
}