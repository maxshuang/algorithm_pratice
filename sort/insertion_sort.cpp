/*
* 插入排序：原理上类似选择排序，不过是将新元素插入到前面已经排序好的
* 元素中，将其他元素后移。时间复杂度O(n^2), 空间复杂度O(1)。
* 内排序，稳定排序(遇到相等的直接插到后面，不再比较)
*/
#include "comm_tools.h"

void insertion_sort(int* arr, int size)
{
  if(!arr || !size){
    return;
  }

  int i = 1;
  int cur_tmp = 0;
  int cur_idx = 0;
  int insert_idx = 0;
  for(; i < size; ++i){
    cur_tmp = arr[i];
    cur_idx = i;
    insert_idx = 0;
    int j = i-1;
    for(; j >= 0; --j){
      //找到第一个大于等于就停止
      if(arr[j] >= arr[i]){
        insert_idx = j+1;
        break;
      }
    }

    //++j;
    //后移其他元素
    for(; cur_idx > j; --cur_idx){
      arr[cur_idx] = arr[cur_idx-1];
    }
    arr[insert_idx] = cur_tmp;
  }
}

#if 1
int main()
{
  int arr[] = {10, 5, 8, 0, 2, 11, 6, 7, 6, 1};
  int size = sizeof(arr)/sizeof(int);
  insertion_sort(arr, size);
  print_out(arr, size);
}
#endif

