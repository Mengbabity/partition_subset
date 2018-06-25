class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return false;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1)
            return false;
        
        int target = sum >> 1;
    
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for(auto num : nums) 
            for(int i = target; i >= 0; i--)
            {
                if(i>=num)
                    dp[i] = dp[i] || dp[i - num];
            }
                
        return dp[target];
        
    }
};
