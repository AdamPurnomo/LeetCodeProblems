class Solution
{
public:
    int climbStairs(int n)
    {
        int back1 = 2;
        int back2 = 1;
        int res = 0;

        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else
        {
            for (int i = 3; i <= n; i++)
            {
                res = back1 + back2;
                back2 = back1;
                back1 = res;
            }
        }
        return res;
    }
};