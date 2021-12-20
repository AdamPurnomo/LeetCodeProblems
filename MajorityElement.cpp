class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int count = 0;
        int candidate;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                candidate = nums[i];
            if (candidate == nums[i])
                count++;
            else
                count--;
        }
        /*
        unordered_map<int, int> map;
        int n = nums.size();

        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]] += 1;
            if(map[nums[i]] > n/2) return nums[i];
        }
        */

        return candidate;
    }
};