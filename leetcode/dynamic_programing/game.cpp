//博弈游戏，有多堆石头，每堆石头的个数已知。甲乙两人轮流拿石头，每次
//只能拿一堆，只能拿走最左边或者最右边的石头堆。假设两人足够聪明，请问
//先手和后手最后的石头总数之差。

//分析:明显可以发现该问题存在重叠子问题，可以用动态规划求解。
//由于可以从石堆的左边或者右边拿，所以可以看出有2个状态，每个状态下的
//动作为取左边的或者右边的石堆，同时对于每个状态而言，先手和后手的最
//优收益是不一样的。


//使用dp[][]=bounus二维数组表示所有的状态下先手和后手的最优收益
//base condition：dp[i][j]=bonus(a[i],0)|i=j, i=j时先手收益为a[i],后手收益为0

//状态转移方程：dp[i][j].first = max(a[i]+dp[i-1][j].second, a[j]+dp[i][j-1].second);
//				dp[i][j].second = max(a[i-1][j].first, a[i][j-1].first);
//高状态依赖下后方的低状态值
struct bonus{
	int first;
	int second;
};

int find_max_interval(int[] piles, int num)
{
	int** dp = new int*[num];
	for(int i=0; i<num; ++i){
		dp[i] = new int[num];
	}
	
	for()
	
}
