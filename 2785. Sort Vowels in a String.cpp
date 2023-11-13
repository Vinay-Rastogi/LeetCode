#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isVowel(char ch)
    {

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;

        return false;
    }

    string sortVowels(string s)
    {

        map<char, int> mp;

        for (int i = 0; i < s.length(); i++)
            if (isVowel(s[i]))
                mp[s[i]]++;

        if (mp.size() == 0)
            return s;

        map<char, int>::iterator it = mp.begin();

        for (int i = 0; i < s.length(); i++)
        {

            if (isVowel(s[i]))
            {
                s[i] = (*it).first;

                if (--(*it).second == 0)
                    it++;
            }
        }

        return s;
    }
};

int main()
{

    Solution sl;
    string s = "lEetcOde";

    cout << sl.sortVowels(s);

    return 0;
}