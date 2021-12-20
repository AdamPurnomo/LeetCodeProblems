// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;

        while (left <= right)
        {
            int ind = left + (right - left) / 2;
            if (isBadVersion(ind))
            {
                right = ind - 1;
                if (!isBadVersion(ind - 1))
                    return ind;
            }
            else if (!isBadVersion(ind))
                left = ind + 1;
        }
        return -1;
    }
};