class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return; // Edge case: empty list or single node

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* temp;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Step 3: Merge the two halves
        ListNode* first = head;
        ListNode* second = prev;
        while (second->next) { // interleave the two lists
            temp = first->next;
            first->next = second;
            first = temp;

            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};
