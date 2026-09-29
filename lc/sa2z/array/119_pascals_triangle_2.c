// problem: https://leetcode.com/problems/pascals-triangle-ii/description/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // time - O(N), space - O(N)
int* getRow(int rowIndex, int* returnSize) {
  // Use "Sequential Multiplier Method" to calculate all the elements in a row
  // k : column index (starts from 0), in formula use the previous elements k value
  // n : row number
  // 
  // current_element = (previous_element * (n - k)) / (k + 1)
  // 
  //   k points to the k value of previous element, ie. k is one less than current index

  int *ans = malloc(sizeof(int) * (rowIndex + 1));
  if (!ans) return NULL;

  // set start and last element's value
  ans[0] = 1;
  ans[rowIndex] = 1;

  long long curr = 1;   // to prevent over flow, using this to do caluclation

  for (int i = 1, k = 0; i < rowIndex; i++, k++) {
    curr = (curr * (rowIndex - k)) / (k + 1);

    ans[i] = (int) curr;     // update the value into array
  }

  *returnSize = rowIndex + 1;
  return ans;
}