// problem: https://leetcode.com/problems/pascals-triangle/description/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 // time - O(N^2), space - O(N^2)
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int *) * numRows);     // array of array which hold each row
    if (!ans) return NULL;

    int *col_size = malloc(sizeof(int) * numRows);   // array to hold the size of each array
    if (!col_size) return NULL;

    for (int i = 0; i < numRows; i++) {
        ans[i] = malloc(sizeof(int) * (i + 1));  // allocate new array for size i
        col_size[i] = i + 1;                     // update the array size

        // set the start and the end element to 1
        ans[i][0] = 1;
        ans[i][i] = 1;

        // set the remaining elements value
        for (int j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }

    *returnSize = numRows;
    *returnColumnSizes = col_size;
    return ans;
    
}