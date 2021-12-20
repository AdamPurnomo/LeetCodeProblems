class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]] += 1;

        sort(begin(nums), end(nums), [&](int a, int b)
             { return map[a] == map[b] ? a > b : map[a] < map[b]; });
        return nums;
    }
};