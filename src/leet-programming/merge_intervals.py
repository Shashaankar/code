"""
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
"""

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        ret_list = []
        
        # Sort the list based on start index
        intervals.sort(key=lambda x: x.start, reverse=False)
        for interval in intervals:
            print interval.start, interval.end
        
        i = reset_flag = j = 0
        
        while i < len(intervals)-1:
            
            j = i+1
            while j < len(intervals):
                if intervals[i].end >= intervals[j].start and intervals[i].end < intervals[j].end:
                    
                    print "merging [%s, %s] and [%s, %s]" % (intervals[i].start, intervals[i].end, intervals[j].start, intervals[j].end)
                    intervals[j].start = intervals[i].start
                    del intervals[i]
                    
                    # Loop break condition
                    reset_flag = 1
                    break
                elif intervals[i].end >= intervals[j].start and not (intervals[i].end < intervals[j].end):
                    print "deleting [%s, %s] " % (intervals[j].start, intervals[j].end)
                    del intervals[j]
                    continue
                
                j += 1
                
        
            if reset_flag == 1:
                i = 0
                reset_flag = 0
            else:
                i += 1
        
        
        return intervals
        
