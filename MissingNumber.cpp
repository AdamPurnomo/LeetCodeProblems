class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int x1 = 0;
        int x2 = 0;
        int i = 0;
        while (i < n)
        {
            x1 ^= nums[i];
            x2 ^= i;
            i++;
        }

        return x1 ^ x2 ^ i;
    }
};

//use XOR instead