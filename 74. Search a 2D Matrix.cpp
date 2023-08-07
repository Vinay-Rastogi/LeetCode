class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int row = matrix.size();
        int col = matrix[0].size();
        int search_row = 0;

        // finding the row no in which the element might be present
        for (int i = 0; i < row; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][col - 1])
                search_row = i;
        }

        int low = 0;
        int high = col - 1;

        //  using binary search in the search_row

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (matrix[search_row][mid] == target)
                return true;

            if (matrix[search_row][mid] > target)
                high = mid - 1;

            if (matrix[search_row][mid] < target)
                low = mid + 1;
        }

        return false;
    }
};