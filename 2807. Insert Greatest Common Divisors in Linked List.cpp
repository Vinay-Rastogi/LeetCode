#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr && curr->next) {
            int gcd = __gcd(curr->val, curr->next->val);
            ListNode* temp = new ListNode(gcd);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }
        return head;
    }
};


ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}


void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {

    vector<int> nums = {18, 24, 30}; 
    ListNode* head = createList(nums);

    Solution sol;
    head = sol.insertGreatestCommonDivisors(head);

    
    printList(head);

    // Free the allocated memory
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
