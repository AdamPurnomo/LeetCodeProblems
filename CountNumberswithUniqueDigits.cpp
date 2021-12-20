class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {

        int res = 1;
        int num = 0;
        vector<bool> digit(9, false);
        recursive(res, num, digit, n, 1);

        return res;
    }

    void recursive(int &res, int &num, vector<bool> &digit, int n, int k)
    {
        if (k > n)
            return;

        for (int i = 0; i <= 9; i++)
        {
            if (digit[i] == false)
            {
                /*process*/
                num = num * 10 + i;
                digit[i] = true;

                /*backtrack*/
                if (num != 0)
                {
                    res++;
                    recursive(res, num, digit, n, k + 1);
                }

                /*unprocess*/
                num = (num - i) / 10;
                digit[i] = false;
            }
        }
    }

    int nonrecursive(int n)
    {
        /*since we don't care about the solution, we only care about the number.
        using permutation equation is sufficient*/
        int sum = 1, perm = 9, i = 1;

        while (i <= n && i <= 10)
        {
            sum += perm;
            perm *= (11 - ++i);
        }

        return sum;
    }
};