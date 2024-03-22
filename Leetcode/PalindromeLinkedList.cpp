// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise.

//  

// Example 1:

// Input: head = [1,2,2,1]
// Output: true


// Example 2:

// Input: head = [1,2]
// Output: false


//  

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9

//  


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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) // Handling edge cases
            return true;

        // Step 1: Find the middle of the linked list
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode *secondHalf = reverseList(slow->next);
        ListNode *firstHalf = head;

        // Step 3: Compare the first half with the reversed second half
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr != nullptr) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }
};
