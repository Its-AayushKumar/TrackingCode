#include<stdio.h>

int main(){
    // int a ; b=a;  --> This is invalid 
    int a ; int b=a ;   //This does not give any error 
    
    
    int v = 3^3;     // This is valid but does not give the desired output
    printf("%d",v); 

    // char dt = '21'; --> char only stores single charater value
    char dt = '3';  //This is valid
   
    return 0;
}