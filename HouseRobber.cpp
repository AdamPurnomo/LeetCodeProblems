class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int res = 0;

        if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int back1 = max(nums[1], nums[0]);
        int back2 = nums[0];
        for (int i = 2; i < nums.size(); i++)
        {
            res = max(nums[i] + back2, back1);
            back2 = back1;
            back1 = res;
        }
        return res;
    }
};