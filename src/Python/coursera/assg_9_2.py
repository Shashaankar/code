#!/bin/python

"""
9.4 Write a program to read through the mbox-short.txt and figure out
who has the sent the greatest number of mail messages. The program looks
for 'From ' lines and takes the second word of those lines as the person
who sent the mail. The program creates a Python dictionary that maps the
sender's mail address to a count of the number of times they appear in
the file. After the dictionary is produced, the program reads through
the dictionary using a maximum loop to find the most prolific committer.
"""

name = raw_input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
search_str = "From "
sender_dict = dict()
try:
    handle = open(name, 'r')
    for line in handle:
        if search_str in line:
            line = line.split()
            sender = line[1]
            # Add to the dictionary if not found else, increment the
            # count for number of times he sent
            sender_dict[sender] = sender_dict.get(sender, 0) + 1

    # Now find most prolific committer
    max_commit = None
    for sender in sender_dict:
        if max_commit is None or sender_dict[sender] > max_commit:
            max_commit = sender_dict[sender]
            max_sender = sender
            
    # Now print the max committer
    print max_sender, max_commit

except Exception, e:
    print e

