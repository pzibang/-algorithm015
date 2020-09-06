class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        int a2 = 0, b3 = 0, c5 = 0;
        dp[0] = 1;

        for(int i = 1; i< n; i++){
            dp[i] =min((min(dp[a2]*2, dp[b3]*3)), dp[c5]*5);
            if(dp[i] == dp[a2]*2){
                a2++;
            }

            if(dp[i] == dp[b3]*3){
                b3++;
            }

            if(dp[i] == dp[c5]*5){
                c5++;
            }                       
        }

        return dp[n-1];
    }
};
