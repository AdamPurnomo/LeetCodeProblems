class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        // vector<int> candidate;

        effrecursive(nums, res, 0);

        return res;
    }

    void recursive(vector<int> &nums, vector<vector<int>> &res, vector<int> &candidate, int k)
    {
        if (k < 1)
        {
            res.push_back(candidate);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != -100)
            {
                int dummy = nums[i];
                candidate.push_back(dummy);             // make move
                nums[i] = -100;                         // exclue from the possible set
                recursive(nums, res, candidate, k - 1); // backtrack
                nums[i] = dummy;                        // reset
                candidate.pop_back();                   // unmake move
            }
        }
    }

    void effrecursive(vector<int> &nums, vector<vector<int>> &res, int begin)
    {
        if (begin >= nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = begin; i < nums.size(); i++)
        {
            swap(nums[begin], nums[i]);
            effrecursive(nums, res, begin + 1);
            swap(nums[begin], nums[i]);
        }
    }
};