class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {

        int res = 0;
        int start = 0;
        int end;

        for (end = 0; end < nums.size(); end++)
        {
            if (nums[end] == 0)
                k--;

            // if it is no valid, increase the start while not counting the length
            if (k < 0)
            {
                if (nums[start] == 0)
                    k++;
                start++;
            }
            //only counts when it is valid length
            else
                res = max(res, end - start + 1);
        }

        return res;

        /*
        //working solution
        
        int res=0;
        int start=0;
        int end;
        
        for(end=0;end<nums.size();end++)
        {
            //if it is valid, expand while reducing k
            if(nums[end]==0) k--;
            
            //if k<0, means we have more than k zeros, increase start until valid again
            while(k<0)
            {
                if(nums[start]==0) k++;
                start++;
            }
            
            //only check the lenght if it is valid subarray
            res = max(res, end-start+1);
        }
        
        return res;
        */
    }
};