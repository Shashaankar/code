/**
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**/

int climbStairs(int n) {
    
    int i;
    int *table=NULL;
    
    if (n<=0) {
        return 0;
    }
    
    if (n == 1 || n == 2) {
        return n;
    }
    
    table = malloc(sizeof(n)*(n+1));
    
    // Initial values
    table[0] = 0;
    table[1] = 1;
    table[2] = 2;
    
    i = 3;
    
    while (i<=n) {
        
        table[i] = table[i-1] + table[i-2];
        
        if (i == n) {
            return table[i];
        }
        i++;
    }
    
    
    return table[n];
    
}
