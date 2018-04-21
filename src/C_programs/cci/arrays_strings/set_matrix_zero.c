#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*
 * Write an algorithm such that if an element in an MxN matrix is 0, its
 * entire row and
 * column are set to 0.
 */

void print_matrix(int *mat, int m, int n);
void set_zero(int *mat, int m, int n);
void main() {

    int m1[][4] = {{0,0,0,1}, {5,6,7,8}, {9,3,1,2}, {3,4,5,6}};

    printf("Before setting zeroes...\n");
    print_matrix(&m1[0][0], 4, 4);
    set_zero(&m1[0][0], 4, 4);

    printf("After setting zeroes...\n");
    print_matrix(&m1[0][0], 4, 4);

}

void print_matrix(int *mat, int m, int n)
{
    int i,j;

    if (mat == NULL || m <= 0 || n <= 0)
    {
        return;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i*n+j]);
        }
        printf("\n");
    }
}

void set_zero(int *mat, int m, int n)
{
    int *row, *col;
    int i,j;
    /* Optimization:
     * #1 Allocate a bit field to determine the row/column that needs to
     * be zeroe-ed out 
     * #2 with out allocating additional memory, we can mark zeroes as a
     * special integer (if the values in matrix are of some specified
     * range) then in second pass null out the special integer
     * row/column */
    row = malloc(sizeof(int)*m);
    col = malloc(sizeof(int)*n);

    assert(row && col);
    if (!mat || m <= 0, n<= 0) {
        return;
    }

    /* First pass to mark the zero row's and col's */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i*n + j] == 0) {
                row[i] = col[j] = -1;
                printf("DEBUG: row:= %d, col:= %d", i,j);
            }
        }
    }

    /* Second pass to zero out the rows and columns */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (row[i] == -1 || col[j] == -1) {
                mat[i*n + j] = 0;
            }
        }
    }

}
