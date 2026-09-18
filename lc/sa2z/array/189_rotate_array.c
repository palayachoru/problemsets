// problem: https://leetcode.com/problems/rotate-array/description/

void reverse_arr(int *arr, int start, int end) {
  int swp;

  while (start < end) {
    swp = arr[start];
    arr[start] = arr[end];
    arr[end] = swp;

    start++;
    end--;
  }
}

// time - O(N), space - O(1)
void rotate(int* nums, int numsSize, int k) {
  // shrink the k within numsSize limit
  k = k % numsSize;

  // reverse first half (0 to numsSize - k - 1)
  reverse_arr(nums, 0, numsSize - k - 1);

  // reverse second half (numsSize - k, numsSize - 1)
  reverse_arr(nums, numsSize - k, numsSize - 1);

  // reverse the entire array
  reverse_arr(nums, 0, numsSize-1);
}