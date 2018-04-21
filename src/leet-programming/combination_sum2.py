"""
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
"""

class Solution(object):

    def combinationSumDFS(self, candidates, target, j, curr_list, ret_list):

        temp_list = list(curr_list)
        if target == 0:
            if temp_list not in ret_list:
                ret_list.append(temp_list)
            return

        if candidates[j] > target:
            return

        for i in range(j+1, len(candidates)):
            temp_list.append(candidates[i])
            #print "After append: index = %s list = %s" % (i, temp_list)
            self.combinationSumDFS(candidates, target-candidates[i], i, temp_list, ret_list)
            #print "After DFS call: %s" % temp_list
            temp_list.pop()
            #print "After pop: %s" % temp_list

    def combinationSum2(self, candidates, target):
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
        
        print "List after sorting: %s" % candidates

        for k in range(len(candidates)):
            curr_list = []
            curr_list.append(candidates[k])
            self.combinationSumDFS(candidates, target-curr_list[0], k, curr_list, ret_list)

        return ret_list

