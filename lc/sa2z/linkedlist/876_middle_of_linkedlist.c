// PROBLEM: https://leetcode.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // time complexity - O(N)
 // space complexity - O(1)
struct ListNode* middleNode(struct ListNode* head) {
  typedef struct ListNode List;

  List *tortoise = head;
  List *hare = head;

  while (hare && hare->next) {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }

  return tortoise;    
}