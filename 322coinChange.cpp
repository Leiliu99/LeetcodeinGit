int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);//every time for this position it's the minimun coin amount needed for this value
                    //eg.dp[1] = 1(only need one coin value 1); dp[2] = 1(only need one coin value 2) etc
                    
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }