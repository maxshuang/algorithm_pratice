//给定一个整数数组，请找出和最大的连续子数组
#include <string.h>
#include <strings.h>
#include <algorithm>

int find_biggest_sub_array(int[] nums, int len)
{
	int* dp = new int[len]; 
	bzero((void*)dp, len*sizeof(int));
	
	dp[0] = nums[0];	
	for(int i = 1; i < len； ++i){
		dp[i] = std::max(dp[i-1]+nums[i], nums[i]);
	}
	
	int max = dp[0];
	for(int i = 1; i < len; ++i){
		max = std::max(max, dp[i]);
	}
	
	return max;
}


