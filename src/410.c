class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long **dp = new long* [m+1];
        int numCnt = nums.size();
        for(int i = 0; i < m+1; i ++)
            dp[i] = new long [numCnt];

        dp[1][0] = nums[0];

        for(int i = 1; i < numCnt; i ++){
            dp[1][i] = dp[1][i-1] + nums[i];
        }

        for(int i = 2; i < m+1; i ++){
            long sum = 0;
            for(int j = 0; j < numCnt; j ++){
                sum += nums[j];

                long tmpMin = sum;
                long tmpSum = sum;
                for(int k = 0; k < j; k ++){
                    tmpSum -= nums[k];

                    long tmpMax = (tmpSum > dp[i-1][k]) ? tmpSum : dp[i-1][k];

                    tmpMin = tmpMin < tmpMax ? tmpMin : tmpMax;

                }
                dp[i][j] = tmpMin;
            }
        }
        return dp[m][numCnt-1];

    }
};