#include <bits/stdc++.h>

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> triplets;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            //Once we process the leading number, we don't want
            //to process it all again avoinding duplication
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[left] + nums[right];
                //while we are processing a particular leading number,
                //we want to find all possible combinations with the leading num
                //so that we don't have to process it again
                if (sum == -nums[i])
                {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    //to avoid duplication, we don't want the second or third num
                    // the same as the one we already recoded
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum > -nums[i])
                    right--;
                else if (sum < -nums[i])
                    left++;
            }
        }

        return res;
    }
};