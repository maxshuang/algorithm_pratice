/*
* 冒泡排序：交换排序，时间复杂度O(n^2), 空间复杂度O(1)。
*
*/
#include "comm_tools.h"

void bubble_sort(int* arr, int size)
{
  if(!arr || !size){
    return;
  }
  
  bool bSeq = true;
  int tmp = 0;
  int i = 0;
  for(; i < size-1; ++i){
     int j = size -1;
     for(; j > i; --j){
       if(arr[j] > arr[j-1]){
         tmp = arr[j];
         arr[j] = arr[j-1];
         arr[j-1] = tmp;
         bSeq = false;
       }
     }
  
    if(bSeq){
      break;
    }
  }
}

#if 1
int main()
{
  int arr[] = {10, 5, 8, 0, 2, 11, 6, 7, 6, 1};
  int size = sizeof(arr)/sizeof(int);
  bubble_sort(arr, size);
  print_out(arr, size);
}
#endif
