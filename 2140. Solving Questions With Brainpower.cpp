class Solution
{
public:
    long long helper(vector<vector<int>> &questions, int i, vector<long long> &dp)
    {

        // if i is out of bound that means we have travelled through all the element  so return 0
        if (i >= questions.size())
            return 0;

        //  if the sub-problem is already solved directly return it's value
        if (dp[i] != -1)
            return dp[i];

        // we are include the current question to solve and adding it's point
        long long include = questions[i][0] + helper(questions, i + 1 + questions[i][1], dp);

        // we are not skipping this question and moving to next question
        long long exclude = helper(questions, i + 1, dp);

        return dp[i] = max(include, exclude);
    }

    long long mostPoints(vector<vector<int>> &questions)
    {

        vector<long long> dp(questions.size(), -1);

        return helper(questions, 0, dp);
    }
};