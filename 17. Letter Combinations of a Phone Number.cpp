class Solution
{
private:
    void helper(string digits, int ind, string input, vector<string> &ans, string map[])
    {

        if (ind == digits.length())
        {
            ans.push_back(input);
            return;
        }

        int num = digits[ind] - '0';
        string temp = map[num];

        for (int i = 0; i < temp.length(); i++)
        {
            input.push_back(temp[i]);
            helper(digits, ind + 1, input, ans, map);
            input.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {

        vector<string> ans;
        if (digits.length() == 0)
            return ans;

        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string input = "";
        int ind = 0;

        helper(digits, ind, input, ans, map);

        return ans;
    }
};