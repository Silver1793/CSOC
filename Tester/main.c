#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include "main.h"
#include <ctype.h>
#include <math.h>
//#include <ctime>
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
    {
        if(n&i)
        {
            printf("1");
        }
        else
        printf("0");
    }
}
typedef struct{
    char t[10];
};
int foo(int x){

    int index = 31;
    unsigned int mask = (1<<31);
    while(index >= 0 && !(x & mask)){
        mask = mask >> 1;
        index--;
    }
    return index;
}
int main() //01100101
{      
    srand(time(NULL));
    printf("%d", rand());
}
/**
 * 1.00110011 e^132  0 1000 0100 0110 0110 0000 0000 0000 000
 * 
 * 1110100.01 3^135 1 1000 0110 1110 0111 0100 0000 0000 000
 * 
 */