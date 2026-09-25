// problem: https://leetcode.com/problems/majority-element/description/

// Way 01: set candidate as num[0] and start the loop
// time - O(N), space - O(1)
int majorityElement(int* nums, int numsSize) {
  int candidate = nums[0], count = 1;

  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == candidate) count++;
    else count--;

    if (count == 0) {
      candidate = nums[i];
      count = 1;
    }
  }

  return candidate;
}


// Way 02 - start the candidate with 0 and start the loop
int majorityElement(int* nums, int numsSize) {
  int candidate = 0, count = 0;

  for (int i = 0; i < numsSize; i++) {
    if (count == 0)
      candidate = nums[i];

    count += (nums[i] == candidate ? 1 : -1);
  }

  return candidate;
}