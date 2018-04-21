"""
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
"""




class Solution(object):
    
    def combinationSumDFS(self, candidates, target, j, curr_list, ret_list):
        
        temp_list = list(curr_list)
        if target == 0:
            ret_list.append(temp_list)
            return
            
        if candidates[j] > target:
            return
            
        for i in range(j, len(candidates)):
            temp_list.append(candidates[i])
            #print "After append: %s" % temp_list
            self.combinationSumDFS(candidates, target-candidates[i], i, temp_list, ret_list)
            #print "After DFS call: %s" % temp_list
            temp_list.pop()
            #print "After pop: %s" % temp_list
        
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ret_list = []
        curr_list = []
        
        if len(candidates) == 0:
            return ret_list
            
        # Sort the list
        candidates.sort()
        
        self.combinationSumDFS(candidates, target, 0, curr_list, ret_list)
        
        return ret_list
