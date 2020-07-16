/*
最长递增字串
描述：给定一个无序的定长数组，找出其中最长上升子序列的长度
例子：a[8] = {10,9,2,5,3,7,101,10}，最长上升字串为{2,3,7,101}, 输出4

O(n^2)解法思路：
动态规划解法，状态转移dp(i) = max(dp(j)+1|0=<j<i, a[j]>a[i]), dp[i]表示以a[i]为最大值的最长递增子序列。
相当于对于任意dp(i)，如果a[i]>a[j], 则可以直接将a[i]置于a[j]形成的子序列之后, 则出现状态转移a[i] = a[j]+1。
最后结果为max(dp[i]|0=<i<num)

O(nlogn)解法思路：
O(n^2)解法中，当a[j] < a[i]时，可以将a[i]置于a[j]形成的子序列之后，比如j=7,此时对应的7结尾的最长递增子序列为
{2,3,7}, i=8时，由于101>7, 所以对应此时对应序列为{2,3,7,101}。可以看出对于前面已经有序的递增子序列来说，O(n)的
遍历算法可以使用二分查找降成O(logn)。

对应的实现算法比较难想，采用分堆的思想，依次取数，当新数比堆顶小时可以放在堆顶，否则需要新建堆。当有多个堆顶都满足条件
时则放在最左边的堆，这样保证每个堆顶的元素是有序的，所以在确定新数应该放在哪个堆顶时就可以使用二分查找。最后的总堆数
就是最长上升子序列。
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

//O(n^2)解法
int get_longest_increasing_subseq(int seq[], size_t num)
{
	if(!num){
		return 0;
	}
	
	//初始化为1
	int* dp = new int[num];
	/*for(int i = 0; i < num; ++i){
		dp[i] = 1;
	}*/
	std::fill(dp, dp+num-1, 1);
	

    //O(n^2)时间复杂度
	//dp数组含义：比seq[i]小的最长子序列的长度
	for(int i = 0; i < num; ++i){
		for(int j = 0; j < i; ++j){
			if(seq[i] > seq[j]){
				dp[i] = std::max(dp[i], dp[j]+1);
			}
		}
	}

	//dp数组最大值就是整个序列的最长递增子序列的长度
	int res = 0;
	for(int i = 0; i < num; ++i){
		res = std::max(res, dp[i]);
	}
	
	delete[] dp;
	return res;
}

//找到第一个比obj大的堆
int get_first_bigger_heap_pos(int* heap, int size, int obj)
{
	if(size == 0){
		return -1;
	}
	
	if(heap[0] >= obj){
		return 0;
	}
	
	if(heap[size-1] < obj){
		return -1;
	}
		
	int low = 0;
	int high = size - 1;
	while(low < high){
		mid = (low+high)/2;
		if(heap[mid] >= obj){
			high = mid;
		}else if(heap[mid] < obj){
			low = mid+1;
		}
	}
	
	if(heap[low] >= obj){
		return low;
	}
	
	return high;
}

//O(nlogn)解法
int get_longest_increasing_subseq2(int seq[], size_t num)
{
	if(0 == num){
		return 0;
	}
	
	int *top = new int[num];
	int max_heap_size = 0;
	
	int pos = -1;
	for(int i = 0; i < num; ++i){
		pos = get_first_bigger_heap_pos(top, max_heap_size, seq[i]);
		if(-1 == pos){
			top[max_heap_size++] = seq[i];
		}else{
			top[pos] = seq[i];
		}
	}
	
	delete[] top;
	return max_heap_size;
}

int main()
{
	int seq[] = {10,9,2,5,3,7,101,10};	
	int res = get_longest_increasing_subseq(seq, sizeof(seq)/sizeof(int));
	printf("longest_increasing_subseq is %d\n", res);

	res = get_longest_increasing_subseq2(seq, sizeof(seq)/sizeof(int));
	printf("longest_increasing_subseq2 is %d\n", res);
	
	return 0;
}
