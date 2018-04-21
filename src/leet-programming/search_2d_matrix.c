/**
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
**/
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    
    int i,j,m,n,start,end,mid;
    
    
    if (matrix == NULL) {
        return NULL;
    }
    
    m = matrixRowSize;
    n = matrixColSize;
    start = 0;
    end = m*n-1;
    
    
    while (start <= end) {
        
        mid = (start+end)/2;
        
        if (mid >= n) {
            
            i = mid/n;
            j = mid%n;
        } else {
            
            i = 0;
            j = mid;
        }
        
        if (matrix[i][j] == target) {
            return 1;
        }
        
        if (matrix[i][j] > target) {
            end = mid-1;
        } else {
            start = mid+1;
        }
        
    } // while
    
    
    return 0;
}
