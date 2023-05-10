class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        vector<vector<int>> Res(n, vector<int>(n));

        int top = 0;
        int right = n - 1;
        int bottom = n - 1;
        int left = 0;
        int start = 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {

                Res[top][i] = start;
                start++;
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {

                Res[i][right] = start;
                start++;
            }
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    Res[bottom][i] = start;
                    start++;
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {

                    Res[i][left] = start;
                    start++;
                }
                left++;
            }
        }

        return Res;
    }
};