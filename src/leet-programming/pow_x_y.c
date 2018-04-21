double myPow(double x, int n) {
    
    double temp = 0;
    
    if (n == 0 || x == 1) {
        return 1;
    }
    if (x == 0) {
        return 0;
    }
    
    
    temp = myPow(x, n/2);
    
    if (n%2 == 0) {
        
        return temp*temp;
        
    } else {
        
        if (n > 0) {
            return x*temp*temp;
        } else {
            return (temp*temp)/x;
        }
        
    }
}



