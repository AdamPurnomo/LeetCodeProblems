class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i, j;
        vector<int> dummy;

        i = 0;
        j = 0;

        while ((i < m) && (j < n))
        {
            if (nums1[i] < nums2[j])
            {
                dummy.push_back(nums1[i]);
                i++;
            }
            else
            {
                dummy.push_back(nums2[j]);
                j++;
            }
        }

        // Inputting whatever left
        while (i < m)
        {
            dummy.push_back(nums1[i]);
            i++;
        }
        while (j < n)
        {
            dummy.push_back(nums2[j]);
            j++;
        }

        // copying back
        for (int k = 0; k < m + n; k++)
            nums1[k] = dummy[k];
    }
};