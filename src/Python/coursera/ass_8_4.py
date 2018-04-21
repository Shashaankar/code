#!/bin/python

"""
8.4 Open the file romeo.txt and read it line by line. For each line,
split the line into a list of words using the split() function. The
program should build a list of words. For each word on each line check
to see if the word is already in the list and if not append it to the
list. When the program completes, sort and print the resulting words in
alphabetical order.
You can download the sample data at
http://www.pythonlearn.com/code/romeo.txt
"""

words_list = list()
fname = raw_input("Enter file name:=")

try:
    f_handle = open(fname, 'r')
    for line in f_handle:
        line = line.split()
        for word in line:
            if word not in words_list:
                # then append to list
                words_list.append(word)



except Exception, e:
    print e

# Sort the words list and print it out
words_list.sort()
print words_list
