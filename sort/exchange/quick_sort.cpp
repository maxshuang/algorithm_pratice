/*
* 快速排序：交换排序，相对于冒泡排序需要的排序次数为n-1+n-2+n-2+...+1
* , 快速排序采用二分法的思想，每一轮排序需要比较n次，得到2部分具有大小
* 顺序的数列，再分别进行排序。由于每一轮都要比较n次，但是只要log(n)轮
* 即可达到每一部分都是一个元素，此时整体上已经有序。
*/
#include "comm_tools.h"

void quick_sort(int* arr, int start, int end)
{
  if(!arr || start >= end){
    return;
  }

  int i = start;
  int j = end;

  /*
  * 快排的实现的时候需要注意：
  * (1)如果先从后往前查找，那在分区的时候需要使用[start, i](i, end];
  * (2)如果先从前往后查找，那在分区的时候需要使用[start, i)[i, end];
  * 这样可以防止边界条件的时候出现无限循环的场景。
  */

  //选择开始的元素作为基准
  int pivot = arr[i];
  //partition函数
  while(i!=j){
    while(i != j && arr[j] <= pivot){ --j; }
    //找到一个大的,换给前面的位置
    arr[i] = arr[j];
    while(i != j && arr[i] >= pivot){ ++i; }
    //找到个小的，换给后面的位置
    arr[j] = arr[i];
  }

  //退出说明i==j, 基准值换到中间
  arr[i] = pivot;

  //左半部分和右半部分快排
  quick_sort(arr, start, i);
  quick_sort(arr, i+1, end);
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

