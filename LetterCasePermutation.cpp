class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> res;
        recursive(res, s, 0);
        return res;
    }

    void recursive(vector<string> &res, string &s, int k)
    {
        if (k == s.size())
        {
            res.push_back(s);
            return;
        }

        /*only two candidates, one is not changing current char,
        another one is changing the current char
        */

        /*backtrack, not changing the current char*/
        recursive(res, s, k + 1);

        /*backtrack, changing the curent char if current char is letter*/
        if (isalpha(s[k]))
        {
            toggle(s, k);
            recursive(res, s, k + 1);
            toggle(s, k);
        }
    }

    void alter(string &s, int index)
    {
        if (islower(s[index]))
            s[index] = toupper(s[index]);
        else
            s[index] = tolower(s[index]); /*change to capital*/
    }

    void toggle(string &s, int index)
    {
        s[index] ^= (1 << 5);
    }
};