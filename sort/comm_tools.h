#ifndef COMM_TOOLS_H
#define COMM_TOOLS_H

#include <stdio.h>

void print_out(int* arr, int size)
{
  int i = 0;
  for(; i < size; ++i){
    printf("%d,", arr[i]);
  }
  printf("\n");
}



#endif