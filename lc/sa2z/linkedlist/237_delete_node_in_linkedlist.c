// problem: https://leetcode.com/problems/delete-node-in-a-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // time - O(1)
void deleteNode(struct ListNode* node) {
  node->val = node->next->val;
  node->next = node->next->next;    
}