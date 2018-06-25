class Solution {
private:
    int help(vector<int>& nums,int s)
    {
        vector<int> dp(s+1,0);
        dp[0]=1;
        
        for(auto num:nums)
            for(int i=s;i>=0;i--)
            {
                if(i>=num)
                    dp[i]+= dp[i-num];
            }
        
        return dp[s];
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        if(n==0)
            return 0;
        int sum=0;
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        if(((sum+S) & 1) || sum<S)
            return 0;
        
        return help(nums,(sum+S)>>1);
    }
};
