// problem: https://leetcode.com/problems/missing-number/description/

int missingNumber(int* nums, int numsSize) {
  int curr_sum = 0;
  for (int i = 0; i < numsSize; i++) curr_sum += nums[i];

  int expected_sum = (numsSize * (numsSize + 1)) / 2;

  return expected_sum - curr_sum;    
}