#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* curr = head->next;
        int sum = 0;

        while(curr) {
            if(curr->val == 0) {
                if(sum != 0) {
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                    sum = 0;
                }
            } else {
                sum += curr->val;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for(int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while(current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test case
    vector<int> input = {0, 3, 1, 0, 4, 5, 2, 0};
    ListNode* head = createLinkedList(input);

    ListNode* result = solution.mergeNodes(head);

    // Print the result
    printLinkedList(result);

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
