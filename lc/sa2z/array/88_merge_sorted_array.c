// problem: https://leetcode.com/problems/merge-sorted-array/description/

#define SWAP(type, a, b) do { \
    type temp = a; \
    a = b; \
    b = temp; \
} while (0)


// time - O(M + N), space - O(1)
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int p = m - 1;
  int q = n - 1;
  int s = nums1Size - 1;

  while (q >= 0) {
    if (p >= 0 && nums1[p] > nums2[q]) {
      SWAP(int, nums1[p], nums1[s]);
      p--;
    }
    else {
      SWAP(int, nums2[q], nums1[s]);
      q--;
    }
    s--;
  }    
}