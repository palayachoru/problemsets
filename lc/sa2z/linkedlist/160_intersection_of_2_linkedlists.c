// problem: https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// time - O(M + N), space - O(1)
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
  typedef struct ListNode Node;

  Node *pa = headA;
  Node *pb = headB;

  if (headA == headB) return headA;

  while (pa != pb) {
    pa = pa ? pa->next : headB;
    pb = pb ? pb->next : headA;
  }

  return pa;
}
