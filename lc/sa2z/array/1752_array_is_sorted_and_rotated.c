// problem: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

// time - O(N), space - O(1)
bool check(int* nums, int numsSize) {
  // non-decreasing order -> increasing order

  // sorted array  - all value keep on increasing
  // sorted + rotate -> last element & first element will be merged, then
  //                    value drop from high to low occur at only at meeting point
  //                    ie. nums[i] > nums[i + 1]
  int boundary = 0;
  
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > nums[(i + 1) % numsSize]) boundary++;
  }

  return boundary < 2;
}