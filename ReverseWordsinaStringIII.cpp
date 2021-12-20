class Solution
{
public:
    string reverseWords(string s)
    {
        int startid = 0;
        int endid = 0;
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == ' ' || i == s.length())
            {
                endid = i - 1;
                reversechar(s, startid, endid);
                startid = i + 1;
            }
        }

        return s;
    }

    void reversechar(string &s, int i, int j)
    {
        while (i < j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};