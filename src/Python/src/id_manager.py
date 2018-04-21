#!/bin/python

import sys

class IdManager(object):
    """
    id_cont: To keep track of integer values assigned as Id's
    free_ids: Maintains a list of free_ids
    """

    # Initializing objects 
    def __init__(self):

        self.id_count = 0
        self.free_ids = []

    def __init__(self, id_count):

        self.id_count = id_count
        self.free_ids = []


    """
    @Desc
    get_id() : Generate a new ID which is not allocated previously or
    free ID not in use
    return: returns valid id on success, -1 on failure or overflow
    """
    def get_id(self):
        
        # First check if we have any free_ids to be assigned
        if self.id_count != 0 and len(self.free_ids) != 0:
            free_id_no = self.free_ids.pop()
            return free_id_no

        # Else increment id counter and send the value
        if self.id_count == sys.maxint:
            # reached system maximum
            return -1
        self.id_count += 1
        return self.id_count

    """
    @Desc
    free_id(id) : Accepts an integer value to free up previosuly
    allocated ID.
    return: returns 0 on success, -ve value on failure or on error
    Note: user has to pass integer value to this function, else ascii
    equivalent of character arguments are considered for processing.
    Approach 2:accept string with numberic values, sanity check for
    valid numbers inside the function.
    """
    def free_id(self, id):

        # Sanity check id passed in as argument

        if id > self.id_count or id <= 0:
            # Error condition, return -1 to indicate
            return -1
        else:
            # Check if the id is already freed 
            for id_val in self.free_ids:
                if id_val == id:
                    # return -ve value to indicate error condition
                    return -2
            # Add to free list
            self.free_ids.append(id)
            return 0



id_mgr1 = IdManager(0)

# Test case 1: check for initial settings
print "Test case 1: check for initial settings"
print id_mgr1.id_count
print id_mgr1.free_ids

# Test case 2: functional check for get id
print "Test case 2: functional check for get id"
print id_mgr1.get_id()
print id_mgr1.get_id()

# Test case 3: free invalid id, expected -ve return value
print "Test case 3: free invalid id, expected -ve return value"
print id_mgr1.free_id(10)
print id_mgr1.free_id(0)
print id_mgr1.free_id(-10)

# Test case 4: Functioal test of free_id, expected 0 return value
print "Test case 4: Functioal test of free_id, expected 0 return value"
print id_mgr1.free_id(1)

# Test case 5: Check free_ids after valid/Invalid free_id call
print "Test case 5: Check free_ids after valid/Invalid free_id call"
print id_mgr1.free_ids

print "Test case 6: free with invalid parameters"
print id_mgr1.get_id()
print id_mgr1.get_id()
#print id_mgr1.free_id()


print "Test case 7: free with invalid value, expected -ve return value"
print id_mgr1.free_id('a')

print "Test case 8: check for max get id"
while 1:
    x =  id_mgr1.get_id()
    print x
    if x == -1:
        print "reached max"
        break
