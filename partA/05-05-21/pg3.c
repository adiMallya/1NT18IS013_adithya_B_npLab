#include<stdio.h>
#include<string.h>

char poly[100], gen[100], code[50];
int poly_len,gen_len,i,j, err, flag = 0 ;


void crc(){
    for(i=0; i< gen_len; i++)
        code[i] = poly[i];
    
    //polynomial divison
    do{ 
        if(code[0] == '1'){
            for(j=1;j<gen_len;j++){
                if(code[j] == gen[j])
                    code[j] = '0';
                else
                    code[j] = '1';
            }
        }
        //copying remainder
        for(j = 0; j < gen_len-1; j++)
            code[j] = code[j+1];
        //adding next bit from top
        code[j] = poly[i++];
    }while(i <= poly_len+gen_len-1);
}

void receiver(){
    printf("Data received : %s\n", poly);
    //perform polynomial division with coded polynomial
    crc();
    //check for error
    for(i=0; i< strlen(code); i++)
        if(code[i]=='1')
            flag = 1;
    flag == 1 ? printf("Received data has error !\n"): printf("No errors in data.\n");
}

void main(){
    printf("Sender... \n\n");
    printf("Enter the polynomial : \n");
    scanf("%s",poly);
    
    printf("Enter the generator polynomial : \n");
    scanf("%s",gen);
    
    //calculate lengths
    poly_len = strlen(poly);
    gen_len = strlen(gen);
    
    //appending gen_len-1(L-1) 0's
    for(i=poly_len; i< poly_len+gen_len-1;i++)
       poly[i] = '0';
    
    //perform polynomial division
    crc();
    
    //Senders coded polynomial
    for(i = poly_len; i < poly_len+gen_len-1; i++)
        poly[i] = code[i - poly_len];
        
    printf("CRC : %s\n", code);
    printf("Coded polynomial : %s\n\n", poly);
    
    //introduce error
    printf("Want to add error ? [1/0] : \n");
    scanf("%d", &err);
    if(err == 1){
        printf("At which bit ? (0 - %d) : \n", poly_len+gen_len-1);
        scanf("%d",&i);
        poly[i] = (poly[i] == '0')? '1':'0';
        printf("Message to be sent : %s\n", poly);
    }
    
    //send coded polynomial to receiver
    printf("Receiver... \n\n");
    receiver();

}
