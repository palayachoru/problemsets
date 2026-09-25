// problem: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // time - O(N), space - O(N)
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
  int *ans = malloc(sizeof(int) * numsSize);
  if (!ans) return NULL;

  // keep track of positive and negative elements index
  // positive index: 0, 2, 4, 6, 8
  // negative index: 1, 3, 5, 7, 9
  int p_idx = 0, n_idx = 1;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > 0) {
      ans[p_idx] = nums[i];
      p_idx += 2;
    }
    else {
      ans[n_idx] = nums[i];
      n_idx += 2;
    }
  }

  *returnSize = numsSize;
  return ans;    
}