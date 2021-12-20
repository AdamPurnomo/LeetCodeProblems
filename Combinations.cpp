class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> candidate(k, 0);

        recursive(1, n, k, candidate, res);
        return res;
    }

private:
    void recursive(int i, int n, int k, vector<int> &candidate, vector<vector<int>> &res)
    {
        if (k < 1)
        {
            res.push_back(candidate);
            return;
        }
        /*n-k+1 is to prune unnesecessary search.
        For example, if n=9, and k=5, then starting from
        i=6, there will be no viable candidate anymore
        */
        while (i <= n - k + 1)
        {
            candidate[candidate.size() - k] = i; /*fill candidate with current number, candidate size is always the value of initial k. This does make move and unmake move at the same time*/
            recursive(i + 1, n, k - 1, candidate, res);
            i++;
        }
    }
};
