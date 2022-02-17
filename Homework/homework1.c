#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
    //  1A) unsigned int x = 0xCCCCCCCC;
    //  1B) unsigned int x = 0b11000010101111011100000000000000;
   /*
        2)
        54.5                                    .5x2 = 1  1
                            54/2 = 27  0
                            27/2 = 13  1
                            13/2 = 6   1
                            6/2 = 3    0
                            3/2 = 1    1
                            1/2 = 0    1  
                            110110.1
                            exp = 132 = 10000100
                            sign = positive = 0
                            mantissa = 101101  
                            0 10000100 10110100000000000000000
        
        -294.25                                 .25x2 = .5 0
                                                .5x2 = 1 1
                            294/2 = 147 0
                            147/2 = 73  1
                            73/2 = 36   1
                            36/2 = 18   0
                            18/2 = 9    0
                            9/2 = 4     1
                            4/2 = 2     0
                            2/2 = 1     0
                            1/2 = 0     1
                            100100110.01
                            exp = 135 = 10000111
                            sign = negative = 1
                            mantissa = 0010011001
                            1 10000111 001001100100000000000000


        -294.25 = 1 10000111 001001100100
        54.5 =    0 10000100 101101000000

        Normalize
        
        1 10000111 1.00100110010000000000000
    -   0 10000111 0.00110110100000000000000
        ---------------------------
        1 10000111 0.11101111110000000000000

        Renormalize
        1 10000110 11011111100000000000000 = -239.75
   */
    /*
        3A)
        typedef struct cell
        {
            int value;
            struct cell *next;
            struct cell *prev;
        }CELL;
    */
   /*
        3B) p->next->next->prev = p;
            p->next = p->next->next;
   */
  /*
        4)
         Assuming that the register %rbx contains the address of an array of 32-bit integers and the
register %ecx contains the size of the array, write some x86-64 assembly code that computes
the index of the largest element of the array. The result should be placed in the %eax register.
For example, if the array A pointed to by %rbx contains the values 3, 7 15, 6, 0, and 10, then
your code should place 2 in %eax since A[2] is the largest value in A. You don’t need to write
an entire function, just enough code to put the result in %eax.

  */
  /*
        5A) You are not allocating memory to the node. As a result the node will not be saved. Also the node should be a 
        pointer and the left, right and value fields should be used with a ->
        5B) 
            NODE *new_node(int val)
            {       
                NODE *n = (NODE*)malloc(sizeOf(NODE));
                n->left = NULL;
                n->right = NULL;
                n->value = val;
                return n;  
            }
    /*  6A)
            positive 2^4-1 = 16-1 = 15(decimal)  01111(binary)
            negative -2^4 = -16(decimal) 10001(binary)
    */
//      6B)
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
    return 0;
}