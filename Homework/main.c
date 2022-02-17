#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "main.h"

unsigned int rotate(unsigned int num, unsigned int n)
{   
    int arr[n];
    for(int i = n-1; i >= 0; i--)
    {
        arr[i] = num&1;
        num = num >> 1;
    }
    int shift = 31;
    for(int i = 0; i < n; i++)
    {
       num = num | (arr[i] << shift);
        shift--;
    }
    return num;

}
int main()
{
    int size = 4;
    int p[4] =  {22,4,5,42};
    printf("%d", test(size, p));
    return 0;
}