#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m, vector<int>(n, -1)); // 2D vector
        int minr = 0, maxr = m - 1;
        int minc = 0, maxc = n - 1;
        ListNode* temp = head;
        while (minr <= maxr && minc <= maxc) {
            for (int j = minc; j <= maxc; j++) {
                if (temp == NULL)
                    return arr;
                arr[minr][j] = temp->val;
                temp = temp->next;
            }
            minr++;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = minr; i <= maxr; i++) {
                if (temp == NULL)
                    return arr;
                arr[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--;
            if (minr > maxr || minc > maxc)
                break;
            for (int j = maxc; j >= minc; j--) {
                if (temp == NULL)
                    return arr;
                arr[maxr][j] = temp->val;
                temp = temp->next;
            }
            maxr--;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = maxr; i >= minr; i--) {
                if (temp == NULL)
                    return arr;
                arr[i][minc] = temp->val;
                temp = temp->next;
            }
            minc++;
            if (minr > maxr || minc > maxc)
                break;
        }
        return arr;
    }
};

// Helper function to create a linked list from a vector of integers
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the 2D vector matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == -1) {
                cout << " " << " ";
            } else {
                cout << val << " ";
            }
        }
        cout << endl;
    }
}

int main() {

    vector<int> values = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
    int m = 3, n = 5;
    
    ListNode* head = createLinkedList(values);

    Solution sol;
    vector<vector<int>> result = sol.spiralMatrix(m, n, head);

    
    printMatrix(result);

    return 0;
}
