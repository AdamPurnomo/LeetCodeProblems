class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return dynamicProgrammingPOV(prices);
    }

    int mySolution(vector<int> &prices)
    {
        int profit = 0;
        int buyprice = prices[0];

        for (int i = 0; i < prices.size(); i++)
        {
            buyprice = min(buyprice, prices[i]);
            profit = max(profit, prices[i] - buyprice);
        }

        return profit;
    }

    int dynamicProgrammingPOV(vector<int> &prices)
    {
        /*There are two states, one is min price and another one is profit*/
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = min(prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], prices[i] - dp[i - 1][0]);
        }

        return dp[n - 1][1];
    }
};