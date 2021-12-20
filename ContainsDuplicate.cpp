class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int key = nums[i];
            if (map.find(key) == map.end())
                map[key] = 1;
            else
                return true;
        }
        return false;
    }
};