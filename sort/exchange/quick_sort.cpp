/*
* 快速排序：交换排序，相对于冒泡排序需要的排序次数为n-1+n-2+n-2+...+1
* , 快速排序采用二分法的思想，每一轮排序需要比较n次，得到2部分具有大小
* 顺序的数列，再分别进行排序。由于每一轮都要比较n次，但是只要log(n)轮
* 即可达到每一部分都是一个元素，此时整体上已经有序。
*/
#include "comm_tools.h"

void quick_sort(int* arr, int start, int end)
{
  if(!arr || start){
    return;
  }

  
  
}

#if 1
int main()
{
  int arr[] = {10, 5, 8, 0, 2, 11, 6, 7, 6, 1};
  int size = sizeof(arr)/sizeof(int);
  quick_sort(arr, 0, size-1);
  print_out(arr, size);
}
#endif

