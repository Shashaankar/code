"""
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
"""

class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret_list = []
        
        if len(nums) == 0:
            return ret_list
            
        
        self.permute_recur(nums, 0, ret_list)
        
        
        return ret_list
        
    def checkDup(self, temp_nums, start, end):
        
        for i in range(start, end):
            if temp_nums[i] == temp_nums[end]:
                return False
        
        return True
        
    def swap(self, temp_nums, i, j):
        a = temp_nums[i]
        temp_nums[i] = temp_nums[j]
        temp_nums[j] = a
        return;
        
    
    def permute_recur(self, nums, start, ret_list):
        
        temp_nums = list(nums)
        
        if start >= len(temp_nums):
            #if temp_nums not in ret_list: -> Time complexity is very high when using this inbuilt routine
            ret_list.append(temp_nums)
            return;
            
        for i in range(start,len(temp_nums)):
            if self.checkDup(temp_nums, start, i):
                self.swap(temp_nums, start, i)
                self.permute_recur(temp_nums, start+1, ret_list)
                self.swap(temp_nums, start, i)
