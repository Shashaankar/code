
/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/


#define SET_BIT(_word, _num) ((_word) |= (1<<(_num)))
#define CHECK_BIT(_word, _num) ((_word) & (1<<(_num)))



bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    
    int i,j,val,row,col,word;
    int *row_bitmask,*col_bitmask;
    
    if (!board || (boardRowSize < 0) || (boardColSize < 0)) {
        return 0;
    }
    
    row_bitmask = malloc(sizeof(int) * boardRowSize);
    col_bitmask = malloc(sizeof(int) * boardColSize);
    //TODO: Free allocated memory gracefully
    
    
    // If malloc'ed memory is not memzeroes
    for (i=0; i<boardRowSize;i++) {
        row_bitmask[i] = 0x0;
    }
    for (i=0; i<boardColSize;i++) {
        col_bitmask[i] = 0x0;
    }
    
    for (i=0; i<boardRowSize; i++) {
        
        for (j=0; j<boardColSize; j++) {
            
            if (board[i][j] != '.') {
               
               val = (int)((int)board[i][j] - (int)'0');
               
               // Check & set for row bitmask
               if (CHECK_BIT(row_bitmask[i], val)) {
                   
                    printf("row check: row = %d, col =%d\n", i, j);
                    return 0;   
               } else {
                   SET_BIT(row_bitmask[i], val);
               }
               
               // Check & set for col bitmask
               if (CHECK_BIT(col_bitmask[j], val)) {
                   printf("col check: row = %d, col =%d\n", i, j);
                   return 0;
               } else {
                   SET_BIT(col_bitmask[j], val);
               }
            }
            
        } // col
        
    } // row
    
    
    // Now check for each 3x3 block in the board
     row = col = word = 0;
    while (row < boardRowSize) {
        
        col = 0;
        while (col < boardColSize) {
            
            word = 0x0;
            for (i=row; i<(row+3); i++) {
                
                for (j=col; j<(col+3); j++) {
            
                    if (board[i][j] == '.') {
                        continue;
                    } 
            
                    val = (int)((int)board[i][j] - (int)'0');
                    if (CHECK_BIT(word, val)) {
                        //printf("3x3 box check: row = %d, col =%d, word = %d, val = %d\n", i, j, word, val);
                        return 0;
                    } else {
                        SET_BIT(word, val);
                        //printf("3x3 box set: row = %d, col =%d, word = %d, val = %d\n", i, j, word, val);
                    }
                } // j 
                
            } // i
            
            col += 3;
        } // col
        
        row += 3;
        
    } // row
    
    
    return 1;
}
