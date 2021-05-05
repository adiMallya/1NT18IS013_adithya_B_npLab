#include<stdio.h>
#include<string.h>

char poly[100], gen[100], code[50], error;
int poly_len,gen_len,i,j;


void crc(){
    for(i=0; i< gen_len; i++)
        code[i] = poly[i];
    
    //polynomial divison
    do{
        for(j=1;j<gen_len;j++){
            if(code[j] == gen[j])
                code[j] = '0';
            else
                code[j] = '1';
        }
        //copying remainder
        for(j = 0; j < gen_len-1; j++)
            code[j] = code[j+1];
        //adding 0 from top
        code[j] = poly[i++];
    }while(i < poly_len);
}

void main(){
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
    
    //coded polynomial
    for(i = poly_len; i < poly_len+gen_len-1; i++)
        poly[i] = code[i - poly_len];
        
    printf("CRC : %s\n", code);
    printf("Coded polynomial : %s\n", poly);

}
