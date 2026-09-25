// problem: https://leetcode.com/problems/intersection-of-two-arrays/description/

int compare_integers(const void *a, const void *b) {
    // Cast the void pointers to read them as integer pointers
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    
    // Return a negative value if val_a should come before val_b
    // Return a positive value if val_a should come after val_b
    // Return 0 if they are equal
    return (val_a > val_b) - (val_a < val_b); 
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // WAY 01: Using sorting, time - O(M log M + N log N), space - O(1)
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int ht[1001] = {0};    // array to hold the intersection, also avoid duplicates

  int p = 0, q = 0;

  qsort(nums1, nums1Size, sizeof(int), compare_integers);
  qsort(nums2, nums2Size, sizeof(int), compare_integers);

  while (p < nums1Size && q < nums2Size) {
    if (nums1[p] == nums2[q]) {
      ht[nums1[p]]++;
      p++;
      q++;
    }
    else if (nums1[p] > nums2[q])
      q++;
    else
      p++;
  }

  
  int *ans = malloc(sizeof(int) * (p + q));
  if (!ans) return NULL;

  // go through the ht array and isolate the values that we marked
  int u = 0;   // count the no of values marked
  for (int i = 0; i < 1001; i++) {
    if (ht[i] != 0) ans[u++] = i;
  }

  *returnSize = intersection;
  return ans;    
}


// WAY 02: Without sorting
// time - O(M + N), space - O(1)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  bool ht[1001] = {0};    // bool array to mark elements

  // mark the elements in ht array
  for (int i = 0; i < nums1Size; i++)
    ht[nums1[i]] = 1;

  int *ans = malloc(sizeof(int) * (nums1Size + nums2Size));
  if (!ans) return NULL;

  // identify the marked and make a note
  int unq = 0;
  for (int i = 0; i < nums2Size; i++) {
    if (ht[nums2[i]]) {
      ans[unq++] = nums2[i];   // take a note
      ht[nums2[i]] = 0;        // reset the value
    }
  }

  *returnSize = unq;
  return ans;
}