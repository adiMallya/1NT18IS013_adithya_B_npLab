#include<stdio.h>
#define SIZE 50
// #include<string.h>
void main(){
    int count = 0, p, n, i, j;
    char frame[SIZE];
    
    printf("\nEnter size of string : ");
    scanf("%d",&n);
    
    printf("\nEnter the string(in 0's & 1's) : ");
    for(i=0;i<n;i++)
        scanf("%s",&frame[i]);
    
    for(i=0;i<n;i++){
        for(j=i;j<=(i+5);j++){
            if(frame[j]=='1'){
                count++;
            }
        }
        
        if(count==5){
            frame[j+1]='0';
        }
        count = 0;
    }
    
    printf("\nStuffed string is... ");
    for(i=0;i<n;i++)
        printf(frame[i]+"\t");

    
}
