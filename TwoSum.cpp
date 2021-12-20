#include <unordered_map>
#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> ump;
        vector<int> ind;

        for (int i = 0; i < nums.size(); i++)
        {
            int key = target - nums[i];
            if (ump.find(key) != ump.end())
            {
                ind.push_back(i);
                ind.push_back(ump[key]);
            }
            else
            {
                ump[nums[i]] = i;
            }
        }
        return ind;
    }
};