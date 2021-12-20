class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int back1 = 0;
        int back2 = 0;
        int res = 0;

        for (int i = 2; i <= n; i++)
        {
            res = min(back1 + cost[i - 1], back2 + cost[i - 2]);
            back2 = back1;
            back1 = res;
        }

        return res;
    }
};