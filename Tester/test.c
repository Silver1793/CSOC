#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include "main.h"
#include <ctype.h>
#include <limits.h>
#include <math.h>

int randomize(){
    srand(time(NULL));
    int x = rand()%6;
    return x;
}
int find_least(int* array, int length, int num, int* err){
    int set = 1;
    signed int count = INT_MAX;
    for(int i =0; i < length; i++){
        if(array[i] > num){
            set = 0;
            if(array[i]<count){
                count = array[i];
            }
        }
    }
    if(set == 1){
        *err = 1;
        return 0;
    }
    return count;
}
int main(){
    int array[] = {10,11,20,30,40,50};
    int length = 6;
    int num = 11;
    int err = 0;
    int check = find_least(array, length, num, &err);
    printf("CHECK HERE %d\n", check );

    return 0;
}