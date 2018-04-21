class Solution(object):
/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
**/
    
    def dfs_paran(self, result, string, left, right):
        if left > right:
            return
        
        if left == 0 and right == 0:
            result.append(string)
            return
            
        if left>0:
            self.dfs_paran(result, string+"(", left-1, right)
            
        if right>0:
            self.dfs_paran(result, string+")", left, right-1)
        
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        paran_list = []
        if (n <= 0):
            return ""
            
        self.dfs_paran(paran_list, "", n, n)
        
        return paran_list
                
        
