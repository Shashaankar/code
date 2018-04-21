class Solution(object):
    def selectionSort(self, alist):
        for fillslot in range(len(alist)-1,0,-1):
            positionOfMax=0
            for location in range(1,fillslot+1):
                if alist[location]>alist[positionOfMax]:
                    positionOfMax = location

            temp = alist[fillslot]
            alist[fillslot] = alist[positionOfMax]
            alist[positionOfMax] = temp
        return alist
        
        
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret_list = []
        
        nums.sort() # O(nlogn)
        #nums = self.selectionSort(nums)
        #print nums
        
        
        for index in range((len(nums)-2)):
            #print "current index = %s" % (index)
            left_index = index+1
            right_index = len(nums)-1
            
            while (left_index < right_index):
                #print "left_index %s, right_index %s" % (left_index, right_index)
                if (nums[index]+nums[left_index]+nums[right_index]) == 0:
                    app_list = [nums[index], nums[left_index], nums[right_index]]
                    
                    flag = 0
                    for list_item in ret_list:
                        
                        if (set(list_item).intersection(app_list) == set(app_list)) and (set(app_list).intersection(list_item) == set(list_item)):
                            #print "Duplicate list item app_list->%s: list_item->%s" % (app_list, list_item)
                            flag = 1
                            break
                        
                    if flag == 0:
                        ret_list.append(app_list)
                        
                    # Increment the index    
                    left_index += 1
                        
                elif (nums[index]+nums[left_index]+nums[right_index]) < 0:
                    left_index += 1
                else:
                    right_index -= 1
                    
                    
        return ret_list
                    
            
