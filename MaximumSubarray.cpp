class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int dp = nums[0];
        int currentmax = dp;

        for (int i = 1; i < nums.size(); i++)
        {
            dp = max(nums[i], dp + nums[i]);
            if (dp >= currentmax)
                currentmax = dp;
        }
        return currentmax;
    }
};