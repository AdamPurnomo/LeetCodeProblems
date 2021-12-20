class Solution
{
public:
    int tribonacci(int n)
    {
        int back3 = 0;
        int back2 = 1;
        int back1 = 1;
        int res;

        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (n == 2)
            return 1;
        else
        {
            for (int i = 3; i <= n; i++)
            {
                res = back1 + back2 + back3;
                back3 = back2;
                back2 = back1;
                back1 = res;
            }
        }

        return res;
    }
};