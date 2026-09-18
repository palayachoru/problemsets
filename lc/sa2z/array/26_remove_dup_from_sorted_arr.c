// problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// time - O(N), space - O(1)
int removeDuplicates(int* nums, int numsSize) {
  int l = 0, r = 1;

  while (r < numsSize) {
    if (nums[l] != nums[r]) {
        nums[++l] = nums[r];
    }
    r++;
  }

  // need to return the no of unique values
  // l starts from 0, need to increment 1

  return l + 1;    
}