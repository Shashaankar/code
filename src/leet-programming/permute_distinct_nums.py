"""
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
"""

class Solution(object):
    
    def swap(self, temp_nums, i, j):
        a = temp_nums[i]
        temp_nums[i] = temp_nums[j]
        temp_nums[j] = a
        return;
        
    
    def permute_recur(self, nums, start, ret_list):
        
        temp_nums = list(nums)
        
        if start >= len(temp_nums):
            ret_list.append(temp_nums)
            return;
            
        for i in range(start,len(temp_nums)):
            self.swap(temp_nums, start, i)
            self.permute_recur(temp_nums, start+1, ret_list)
            self.swap(temp_nums, start, i)
        
        
        
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        ret_list = []
        
        if len(nums) == 0:
            return ret_list
            
        
        self.permute_recur(nums, 0, ret_list)
        
        
        return ret_list
