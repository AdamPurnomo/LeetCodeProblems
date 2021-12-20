class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int index1 = 0;
        int index2 = numbers.size() - 1;
        int sum = target - 1;
        while (sum != target)
        {
            sum = numbers[index1] + numbers[index2];
            if (sum < target)
                index1++;
            else if (sum > target)
                index2--;
        }

        vector<int> res = {index1 + 1, index2 + 1};

        return res;
    }
};