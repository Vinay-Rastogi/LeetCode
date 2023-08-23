#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {

        unordered_map<char, int> mp;

        for (int i = 0; i < s.length(); i++)
            mp[s[i]]++;

        priority_queue<pair<int, char>> maxHeap;

        for (auto x : mp)
            maxHeap.push({x.second, x.first});

        string ans = "";

        while (maxHeap.size() >= 2)
        {

            auto ch1 = maxHeap.top();
            maxHeap.pop();
            auto ch2 = maxHeap.top();
            maxHeap.pop();

            ans += ch1.second;
            ans += ch2.second;

            if (--ch1.first > 0)
                maxHeap.push({ch1.first, ch1.second});

            if (--ch2.first > 0)
                maxHeap.push({ch2.first, ch2.second});
        }

        if (!maxHeap.empty())
        {

            auto ch = maxHeap.top();

            if (ch.first > 1)
                return "";

            ans += ch.second;
        }

        return ans;
    }
};

int main()
{

    Solution sl;

    string s = "aab";

    cout << sl.reorganizeString(s);

    return 0;
}