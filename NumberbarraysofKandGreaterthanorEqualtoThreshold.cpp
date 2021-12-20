class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int start = 0;
        int end = 0;
        int sum = 0;
        int count = 0;

        while (end < arr.size())
        {
            sum += arr[end];
            end++;

            if (end - start > k - 1)
            {
                int avg = sum / k;
                if (avg >= threshold)
                    count++;
                sum -= arr[start];
                start++;
            }
        }

        return count;
    }
};