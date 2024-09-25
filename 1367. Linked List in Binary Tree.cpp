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

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL && root == NULL)
            return true;
        if (head == NULL || root == NULL)
            return false;
        if (root->val == head->val)
            return isSubPath(head->next, root->left) || isSubPath(head->next, root->right);
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};


ListNode* createLinkedList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    for (int value : values) {
        if (head == nullptr) {
            head = new ListNode(value);
            current = head;
        } else {
            current->next = new ListNode(value);
            current = current->next;
        }
    }
    return head;
}


TreeNode* createTreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) {
    return new TreeNode(val, left, right);
}

int main() {
    
    vector<int> listValues = {1, 4, 2};
    ListNode* head = createLinkedList(listValues);

    TreeNode* root = createTreeNode(1,
                    createTreeNode(4,
                        createTreeNode(2),
                        createTreeNode(6)),
                    createTreeNode(3));

    
    Solution solution;

    
    bool result = solution.isSubPath(head, root);

    
    cout << (result ? "True" : "False") << endl;

    return 0;
}
