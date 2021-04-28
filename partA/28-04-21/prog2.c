#include<stdio.h>
#include<string.h>

char packet[100];

void receiver(){
//     printf("\nReceiver....");
    printf("\n\nReceived are..\n");
    int i=0;
    
    for(i=0;packet[i]!='\0';i++)
        printf("%c",packet[i]);
}

int main(){
    
    int len,n,i;
    char frames[100];
    printf("Enter no. of frames : \n");
    scanf("%d",&n);
    
    printf("\nEnter the frames(in 0's & 1's) : \n");
    for(i=0;i<n;i++){
        scanf("%s",&frames);
        printf("length of the frame is %d\n", strlen(frames));
        strcat(packet,frames);
    }
    
    for(i=0;packet[i]!='\0';i++)
        printf("%c",packet[i]);
    
    receiver();
    return 0;
}
