class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(robhelper(0, n - 2, nums), robhelper(1, n - 1, nums));
    }

    int robhelper(int l, int r, vector<int> &nums)
    {
        int res = 0;
        int back1 = 0;
        int back2 = 0;

        for (int i = l; i <= r; i++)
        {
            res = max(nums[i] + back2, back1);
            back2 = back1;
            back1 = res;
        }
        return res;
    }
};