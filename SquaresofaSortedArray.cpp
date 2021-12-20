class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> inv;
        vector<int> forw;

        //look for flip
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                inv.push_back(nums[i] * nums[i]);
            else
                forw.push_back(nums[i] * nums[i]);
        }

        vector<int> dummy;
        int m = inv.size();
        int n = forw.size();

        //debugging
        //for(int i=0; i<m;i++) cout << inv[i] << endl;

        //for(int i=0; i<n;i++) cout << forw[i] << endl;

        int i = m - 1;
        int j = 0;

        while ((i > -1) && (j < n))
        {
            if (inv[i] < forw[j])
            {
                dummy.push_back(inv[i]);
                i--;
            }
            else
            {
                dummy.push_back(forw[j]);
                j++;
            }
        }

        //filling leftover
        while (i > -1)
        {
            dummy.push_back(inv[i]);
            i--;
        }

        while (j < n)
        {
            dummy.push_back(forw[j]);
            j++;
        }

        return dummy;
    }
};