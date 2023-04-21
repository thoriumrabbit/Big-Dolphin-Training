#include "function.h"

void function(){
    printf("This is function in function.c\r\n");
}

void square(int num){
    num = num*num;
    printf("Square is %d\n",num);
}

void factorial(unsigned int num){
    int value = 1;
    for (int i = 1; i <= num; i++){
        value = value*i;
    }
    printf("Factorial is %d\n", value);
}