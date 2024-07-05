#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        vector<int> pos;
        int ind = 0;

        ListNode *prev = nullptr, *curr = head, *nxt = head->next;

        while (curr) {
            if (prev && nxt) {
                if ((curr->val > prev->val && curr->val > nxt->val) ||
                    (curr->val < prev->val && curr->val < nxt->val))
                    pos.push_back(ind);
            }

            prev = curr;
            curr = curr->next;

            if (!curr || !curr->next)
                break;

            nxt = curr->next;
            ind++;
        }

        if (pos.size() < 2)
            return {-1, -1};

        int mn = INT_MAX;
        int mx = INT_MIN;

        mx = pos.back() - pos.front();

        for (int i = 1; i < pos.size(); i++)
            mn = min(mn, pos[i] - pos[i - 1]);

        return {mn, mx};
    }
};

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);

    Solution sol;
    vector<int> result = sol.nodesBetweenCriticalPoints(head);

    cout << "Minimum distance: " << result[0] << ", Maximum distance: " << result[1] << endl;

    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
