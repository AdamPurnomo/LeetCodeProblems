class Solution
{
public:
    int fib(int n)
    {
        int back1 = 1;
        int back2 = 0;
        int res;

        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
        {
            for (int i = 2; i <= n; i++)
            {
                res = back1 + back2;
                back2 = back1;
                back1 = res;
            }
        }

        return res;
    }
};