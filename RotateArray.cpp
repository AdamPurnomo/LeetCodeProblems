class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dummy(n);
        for (int i = 0; i < n; i++)
        {
            int index = i + k;
            if (index > n - 1)
                index = index % n;
            dummy[index] = nums[i];
        }

        // copy back
        for (int i = 0; i < n; i++)
            nums[i] = dummy[i];
    }
};