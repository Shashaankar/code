#!/bin/python


"""
10.2 Write a program to read through the mbox-short.txt and figure out
the distribution by hour of the day for each of the messages. You can
pull the hour out from the 'From ' line by finding the time and then
splitting the string a second time using a colon.
From stephen.marquard@uct.ac.za Sat Jan  5 09:14:16 2008
Once you have accumulated the counts for each hour, print out the
counts, sorted by hour as shown below. Note that the autograder does not
have support for the sorted() function.
"""

name = raw_input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
try:
    handle = open(name)
except Exception,e:
    print "Erron in erading file:", e

hour_hist = dict()
    
try:

    for line in handle:
        if "From " in line:
            line = line.split()
            time = line[5]
            time = time.split(':')
            hour = time[0].strip()
            hour_hist[hour] = hour_hist.get(hour, 0) + 1

    # After parsing all lines, print sorted hist
    tmp = list()
    for k,v in hour_hist.items():
        tmp.append((k,v))

    tmp.sort()

    # Print in ascending order
    for k,v in tmp:
        print k,v

except Exception,e:
    print "Error in parsing file:", e


