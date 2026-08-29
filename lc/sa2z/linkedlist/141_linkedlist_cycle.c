// problem: https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // time - O(N), space - O(1)
bool hasCycle(struct ListNode *head) {
  typedef struct ListNode Node;

  Node *tortoise = head;
  Node *hare = head;

  while (hare && hare->next) {
    tortoise = tortoise->next;
    hare = hare->next->next;

    if (hare == tortoise) return true;
  }

  return false;  // no cycle, as we hit end of loop    
}