#include <bits/stdc++.h>
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int ind = (left + right) / 2;
            if (nums[ind] == target)
                return ind;
            else if (nums[ind] < target)
                left = ind + 1;
            else if (nums[ind] > target)
                right = ind - 1;
        }
        return left;
    }
};