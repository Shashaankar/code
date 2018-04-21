#!/bin/python


class MinHeap:
    def __init__(self, size):
        self.heap_arr       = []
        self.heap_size      = size
        self.heap_cur_size  = 0


    def insertValue(self, value):
        
        if self.heap_cur_size == self.heap_size:
            print "Heap capacity full"
            return

        self.heap_cur_size += 1
        self.heap_arr.append(value)
        index = self.heap_cur_size-1

        while index != 0 and self.heap_arr[self.parent(index)] > self.heap_arr[index]:
            self.swap(self.heap_arr, index, self.parent(index))
            index = self.parent(index)

    def swap(self, heap_arr, index1, index2):
        temp = heap_arr[index1]
        heap_arr[index1] = heap_arr[index2]
        heap_arr[index2] = temp


    def parent(self, index):
        return (index-1)/2

    def left_child(self, index):
        return ((2*index) + 1)

    def right_child(self, index):
        return ((2*index) + 2)


    def minHeapify(self, index):

        left = self.left_child(index)
        right = self.right_child(index)
        smallest = index

        if left < self.heap_cur_size and self.heap_arr[left] < self.heap_arr[index]:
            smallest = left

        if right  < self.heap_cur_size and self.heap_arr[right] < self.heap_arr[smallest]:
            smallest = right

        if smallest != index:
            self.swap(self.heap_arr, index, smallest)
            self.minHeapify(smallest)

    def extractMinimum(self):

        if self.heap_cur_size <= 0:
            return None

        if self.heap_cur_size == 1:
            self.heap_cur_size -= 1
            return self.heap_arr[0]

        ret_val = self.heap_arr[0]
        self.heap_arr[0] = self.heap_arr[self.heap_cur_size-1]
        self.heap_cur_size -= 1
        self.minHeapify(0)

        return ret_val


    def printHeap(self):

        print "########## Heap elements start #############"
        for num in self.heap_arr:
            print num
        print "########## Heap elements end #############"



# Execution start
min_heap = MinHeap(10)

min_heap.insertValue(0)
min_heap.insertValue(1)
min_heap.insertValue(2)
min_heap.insertValue(3)
min_heap.printHeap()

print min_heap.extractMinimum()
print min_heap.extractMinimum()
print min_heap.extractMinimum()
print min_heap.extractMinimum()
