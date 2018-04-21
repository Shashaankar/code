/**
 * @input X : Integer array corresponding to the X co-ordinate
 * @input n1 : Integer array's ( X ) length
 * @input Y : Integer array corresponding to the Y co-ordinate
 * @input n2 : Integer array's ( Y ) length
 *
 * Points are represented by (X[i], Y[i])
 * 
 * @Output Integer
 *
 */
 
 #define DELTA(a, b) (((a) > (b))?((a)-(b)):((b) - (a)))
 
int coverPoints(int* X, int n1, int* Y, int n2) {
    
    int i, count, x, y;
    
    if ((n1 != n2) || (n1 <= 1) || (X == NULL || Y == NULL)) {
        
        return 0;
        
    }
    
    count = 0;
    i = 1;
    
    //Init
    x = X[0];
    y = Y[0];
    
    while (i < n1) {
        
        if ((DELTA(x, X[i]) == 0) && (DELTA(y, Y[i]) == 0)) {
            
            i++;
            continue;
        }
        
        // add the delta to x and y
        if (x > X[i]) {
            x--;
        } else if (x < X[i]) {
            x++;
        }
        if (y > Y[i]) {
            y--;
        } else if (y < Y[i]) {
            y++;
        }
        
        count++;
        
    }
    
    return count;
    
    
}


