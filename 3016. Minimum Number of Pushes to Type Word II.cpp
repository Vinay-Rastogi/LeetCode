#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {

        unordered_map<char, int> mp;
        vector<int> freq;

        int ans = 0;

        for (char ch : word)
            mp[ch]++;

        for (auto it : mp)
        {
            freq.push_back(it.second);
        }

        sort(freq.begin(), freq.end(), greater<int>());

        if (freq.size() <= 8)
        {
            for (int x : freq)
                ans += x;

            return ans;
        }

        if (freq.size() <= 16)
        {

            for (int i = 0; i < freq.size(); i++)
            {

                if (i < 8)
                {
                    ans += freq[i];
                }
                else
                {
                    ans += 2 * freq[i];
                }
            }

            return ans;
        }

        if (freq.size() <= 24)
        {

            for (int i = 0; i < freq.size(); i++)
            {

                if (i < 8)
                {
                    ans += freq[i];
                }
                else if (i >= 8 && i < 16)
                {
                    ans += 2 * freq[i];
                }
                else
                {
                    ans += 3 * freq[i];
                }
            }

            return ans;
        }

        for (int i = 0; i < freq.size(); i++)
        {

            if (i < 8)
            {
                ans += freq[i];
            }
            else if (i >= 8 && i < 16)
            {
                ans += 2 * freq[i];
            }
            else if (i >= 16 && i < 24)
            {
                ans += 3 * freq[i];
            }
            else
            {
                ans += 4 * freq[i];
            }
        }

        return ans;
    }
};

int main()
{
    Solution sl;
    string word = "abcde";

    cout << sl.minimumPushes(word);

    return 0;
}