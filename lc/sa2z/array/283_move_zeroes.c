// problem: https://leetcode.com/problems/move-zeroes/description/

// time - O(N), space - O(1)
void moveZeroes(int* nums, int numsSize) {
  int l = 0, r = 0;   // two pointers
  int swp = 0;

  // r - move over the array
  while (r < numsSize) {
    if (nums[r]) {
      swp = nums[r];
      nums[r] = nums[l];
      nums[l] = swp;

      l++;
    }
    r++;
  }   
}