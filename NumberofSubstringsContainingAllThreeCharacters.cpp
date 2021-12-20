class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int start = 0;
        int end = 0;

        int dict[3] = {0};
        int count = 0;

        for (end = 0; end < s.length(); end++)
        {
            dict[s[end] - 'a']++;
            while (checkvalidity(dict))
            {
                count += s.length() - end;
                dict[s[start] - 'a']--;
                start++;
            }
        }
        return count;
    }

    bool checkvalidity(int dict[3])
    {
        if (dict[0] > 0 && dict[1] > 0 && dict[2] > 0)
            return true;
        else
            return false;
    }
};