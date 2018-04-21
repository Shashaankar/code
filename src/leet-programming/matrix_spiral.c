/**
 * Note: The returned array must be malloced, assume caller calls free().
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
 
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    
    int *ret_result = NULL;
    int i,x,y,m,n,k;
    x = y = k = 0;
    m = matrixRowSize;
    n = matrixColSize;
    
    if (matrix == NULL || m <= 0 || n <= 0) {
        return ret_result;
    }
    
    ret_result = malloc(sizeof(int)*m*n);
    
    
    while (m>0 && n>0) {
        
        
        if (m == 1) {
            for (i=0; i<n; i++) {
                ret_result[k++] = matrix[x][y++];
            }
            break;
        } else if (n == 1) {
            for (i=0; i<m; i++) {
                ret_result[k++] = matrix[x++][y];
            }
            break;
        }
        
        // left to right
        for (i=0; i<n-1; i++) {
            ret_result[k++] = matrix[x][y++];
        }
        
        // Top to bottom
        for (i=0; i<m-1; i++) {
            ret_result[k++] = matrix[x++][y];
        }
        
        // Right to left
        for (i=0; i<n-1; i++) {
            ret_result[k++] = matrix[x][y--];
        }
        
        // Bottom to top
        for (i=0; i<m-1; i++) {
            ret_result[k++] = matrix[x--][y];
        }
        
        // loop conditions
        x++;
        y++;
        m=m-2;
        n=n-2;
        
    } // while
    
    
    
    return ret_result;
    
}
