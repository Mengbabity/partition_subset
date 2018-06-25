# partition_subset

# Partition Equal Subset Sum
问题：给定一个数组，判断是否可以将其分为两个子集，两个子集的和相等。

思路：动态规划问题。（0/1背包问题）
     首先对数组求和。numeric库中的函数accumulate函数可直接对vector求和。
     若和为奇数，可直接返回false。即 sum&1 按位与为true。
     
     核心：数组dp[i][j]表示和j可以有i，dp[0][0]必为true，和0pick0，则dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]]
          前一种情况表示没有i，后一种情况表示有i。
     
     优化为一维数组。dp[i]表示和有i。则dp[i]=dp[i] || dp[i-num]
     前一种情况表示有i，后一种情况表示没有i。
     
    
