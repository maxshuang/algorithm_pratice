/*
* 选择排序，通过每轮遍历的方式找出最大(小)值进行排序，适用于
* 各类数据，算法时间复杂度O(n^2)，空间复杂度O(1)。算法原理简单
*
*/
#include "comm_tools.h"


void selection_sort(int* arr, int size)
{
  if(!arr || !size){
    return;
  }

  int max = 0;
  int max_idx = 0;
  int i = 0;
  for(; i < size-1; ++i){
    int j = i;
    max = 0;
    max_idx = 0;
    for(; j < size; ++j){
      if(arr[j] > max){
        max = arr[j];
        max_idx = j;
      }
    }
    arr[max_idx] = arr[i];
    arr[i] = max;
  }

}

#if 1
int main()
{
  int arr[] = {10, 5, 8, 0, 2, 11, 6, 7, 6, 1};
  int size = sizeof(arr)/sizeof(int);
  selection_sort(arr, size);
  print_out(arr, size);
}
#endif
