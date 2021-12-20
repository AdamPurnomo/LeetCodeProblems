class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int res = 0;
        unordered_map<char, int> map;

        int start = 0;
        int end = 0;

        while (end < s.length())
        {
            map[s[end]]++;
            if (map.size() == 3)
                res++;
            end++;

            if (end - start > 2)
            {
                map[s[start]]--;
                if (map[s[start]] == 0)
                    map.erase(s[start]);
                start++;
            }
        }

        return res;
    }
};