"""
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]
"""



# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    
    def mergeInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        
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
    
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        
       
            
        for i in range(0, len(intervals)):
            if intervals[i].start > newInterval.start:
                intervals.insert(i, newInterval)
                break
            elif i == len(intervals)-1:
                intervals.append(newInterval)
            
        if len(intervals) == 0:
            intervals.append(newInterval)
            
        for interval in intervals:
            print "[%s, %s]" % (interval.start, interval.end)
        
        # trigger merge now
        intervals = self.mergeInterval(intervals)
        
        return intervals
