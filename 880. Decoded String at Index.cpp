#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long decodedLength = 0; // Track the length of the decoded string.

        // Calculate the decoded length by iterating through the string.
        for (char c : s)
        {
            if (isdigit(c))
            {
                int digit = c - '0';
                decodedLength *= digit; // Multiply the current length by the digit.
            }
            else
            {
                decodedLength++; // Increment the length for a letter.
            }
        }

        // Start from the end of the string and work backwards to find the kth letter.
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (isdigit(s[i]))
            {
                int digit = s[i] - '0';
                decodedLength /= digit; // Divide the current length by the digit.
                k %= decodedLength;     // Update k with the remainder.
            }
            else
            {
                // If k is 0 or k equals the current length, return the current character.
                if (k == 0 || k == decodedLength)
                {
                    return string(1, s[i]);
                }
                decodedLength--; // Decrement the length for a letter.
            }
        }

        return ""; // This should not be reached, but return an empty string if needed.
    }
};

int main()
{

    Solution sl;
    string s = "leet2code3";
    int k = 10;

    cout << sl.decodeAtIndex(s, k);

    return 0;
}