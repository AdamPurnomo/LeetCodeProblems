class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int height = triangle.size();
        int mintotalcost;
        vector<vector<int>> dp;
        dp.push_back(triangle[0]);

        if (triangle.size() == 1)
            return triangle[0][0];

        for (int i = 1; i < triangle.size(); i++)
        {
            vector<int> mincost;
            mintotalcost = INT_MAX;
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j > 0 && j < triangle[i - 1].size())
                    mincost.push_back(triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]));
                else if (j == 0)
                    mincost.push_back(triangle[i][j] + dp[i - 1][j]);
                else if (j == triangle[i - 1].size())
                    mincost.push_back(triangle[i][j] + dp[i - 1][j - 1]);
                mintotalcost = min(mintotalcost, mincost[j]);
            }
            dp.push_back(mincost);
        }

        return mintotalcost;
    }
};