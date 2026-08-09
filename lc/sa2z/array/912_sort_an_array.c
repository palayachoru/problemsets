#define PL_SWAP(a, b) \
  do { \
    char swap_tmp[sizeof(a)]; \
    memcpy(swap_tmp, &(a), sizeof(a)); \
    memcpy(&(a), &(b), sizeof(a)); \
    memcpy(&(b), swap_tmp, sizeof(a)); \
  } while (0)



// time - O(N^2), space - O(1)
void bubble_sort(int *nums, int size) {
  bool has_swapped = false;

  for (int i = 0; i < size - 1; i ++) {
    has_swapped = false;
  
    // on each iteration, the largest values is placed at the right side
    // so ignore the last index position
    for (int j = 1; j < size - i; j++) {
      if (nums[j - 1] > nums[j]) {
        PL_SWAP(nums[j - 1], nums[j]);
        has_swapped = true;
      }
    }

    // if no swap happens, then the array is sorted
    if (!has_swapped) break;
  }
}


// time - O(N^2), space - O(1)
void selection_sort(int *nums, int size) {
  int min_idx = 0;

  // outer loop points to curr min position
  for (int i = 0; i < size; i++) {
    min_idx = i;
    
    // identify the min value & swap it with outerloop position
    for (int j = i + 1; j < size; j++) {
      if (nums[j] < nums[min_idx]) min_idx = j;
    }

    // swap the min_idx value at the position i
    PL_SWAP(nums[min_idx], nums[i]);
  }
}


// time - O(N^2), space - O(1)
void insertion_sort(int *nums, int size) {
  int key = 0, prev_key_idx = 0;

  for (int k = 1; k < size; k++) {
    key = nums[k];
    prev_key_idx = k - 1;

    // shift the larger values than key to the right
    while (prev_key_idx >= 0 && key < nums[prev_key_idx]) {
      nums[prev_key_idx + 1] = nums[prev_key_idx];
      prev_key_idx--;
    }

    // place the key in it's proper position
    nums[prev_key_idx + 1] = key;
  }
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  insertion_sort(nums, numsSize);

  return nums;    
}
