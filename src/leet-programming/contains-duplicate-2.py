"""
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Show Company Tags
Show Tags
Show Similar Problems

"""

class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        
        if nums == None or k <= 0:
            return False
            
        hash = {}
        for i,v in enumerate(nums):
            # If value is duplicate and the previous number is with in the k window
            if v in hash and i - hash[v] <= k:
                return True
            # Always store the latest index for comparision of duplicate
            hash[v] = i
        
        return False
                
        