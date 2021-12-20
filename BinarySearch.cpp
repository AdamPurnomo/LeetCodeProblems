#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int ind = int(floor((right - left) / 2));

        while ((nums[ind] != target))
        {
            if (left >= right)
            {
                ind = -1;
                break;
            }
            if (nums[ind] < target)
            {
                left = ind + 1;
                ind = left + int(floor((right - left) / 2));
            }
            else if (nums[ind] > target)
            {
                right = ind - 1;
                ind = left + int(floor((right - left) / 2));
            }
        }
        return ind;
    }
};