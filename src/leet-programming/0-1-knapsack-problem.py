#!/bin/python

"""
 0/1 Knapsack Problem - Given items of certain weights/values and
 maximum allowed weight how to pick items to pick items from this 
set to maximize sum of value of items such that
sum of weights is less than or equal to maximum allowed weight.

Time complexity - O(W*total items)


Approach:
    Since here you are either allowed to take or not to include an item,
    think in terms of DP as greedy approach wouldn't work unless the
    problem statemnt says you could include a fraction of the item in
    the final set of solution to maximize the value.

    If you could do that then sort the given items in value/weight
    decreasing order, then include one item by item unless you run out
    of max weight limit. If the final item can not be included then
    include fraction of it.
"""

from collections import defaultdict

def getMaxValue(value, weight, max_weight):

    sol_mat = defaultdict(list)
    
    num_rows = len(value)


    # Initialize the solution matrix for DP based solution
    for i in range(num_rows+1):
        sol_mat[i] = list()
        for j in range(max_weight+1):
            sol_mat[i].append(0)



    # Fill in first row with null as with zero items included we can
    # only generate zero value (already done in above step)

    """
    sol_mat[i][j] =  sol_mat[i-1][j] if weight[i] > i
    sol_mat[i][j] =  max(sol_mat[i-1][j], value[i]+sol_mat[i-1][j-weight[i]])
    """
    # Now fill in the matrix according to above formula
    for i in range(1, len(sol_mat)):
        for j in range(1, max_weight+1):
            
            if weight[i-1] > j:
                sol_mat[i][j] = sol_mat[i-1][j]

            else:
                sol_mat[i][j] = max(sol_mat[i-1][j], \
                                value[i-1]+sol_mat[i-1][j-weight[i-1]])


    # Last cell in the sol matrix should have the max value that can be
    # generated with given items

    if __debug__ :
        print "DEBUG"
        for i in range(len(sol_mat)):
            print "row = %s" % (i)
            for j in range(len(sol_mat[0])):
                print sol_mat[i][j]

    return sol_mat[num_rows][max_weight]



val = [1, 4, 5, 7]
wt = [1, 3, 4, 5]

#val = [22, 20, 15, 30, 24, 54, 21, 32, 18, 25]
#wt = [4, 2, 3, 5, 5, 6, 9, 7, 8, 10]

print getMaxValue(val, wt, 7)

