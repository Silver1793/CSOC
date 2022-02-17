#include <stdio.h>

int add_array(int a[], int size);  // implemented in add_array.s

int main()
{
  int a[5] = { 2, 4, 6, 8, 10};
  int res = add_array(a, 5);
  printf("result = %d\n", res);
}
    /*1011
      1010
    --------
      0000
     1011  
    0000
   1011
   -------
        1101110
  */
