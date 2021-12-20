#include <bits/stdc++.h>

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxcount = 0;
        int start = 0;
        unordered_map<char, int> hashmap;

        for (int i = 0; i < s.length(); i++)
        {
            /*The if statement here is very important
            If the current char is already in the hashmap
            we update the start. If the last start index is less
            than the index after the found char, then update it to the 
            index after the found char. The start index can only move forward*/
            if (hashmap.find(s[i]) != hashmap.end())
                start = max(start, hashmap[s[i]] + 1);
            hashmap[s[i]] = i;
            maxcount = max(maxcount, i - start + 1);
        }
        return maxcount;
    }
};