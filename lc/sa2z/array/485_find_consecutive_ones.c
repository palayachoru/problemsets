// problem: https://leetcode.com/problems/max-consecutive-ones/description/

// time - O(N), space - O(1)
int findMaxConsecutiveOnes(int* nums, int numsSize) {
  int curr_cnt = 0;
  int longest = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0) {
      longest = curr_cnt > longest ? curr_cnt : longest;
      curr_cnt = 0;
    }
    else curr_cnt++;
  }

  return (curr_cnt > longest ? curr_cnt : longest);
}