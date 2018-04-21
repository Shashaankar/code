#!/usr/bin/python
"""
7.1 Write a program that prompts for a file name, then opens that file
and reads through the file, and print the contents of the file in upper
case. Use the file words.txt to produce the output below.
You can download the sample data at
http://www.pythonlearn.com/code/words.txt
"""
import os

try:
    file_name = raw_input("Enter filename: ")

    # Check if file exists
    if not os.path.isfile(file_name):
        print "Invalid file"
        exit()

    fhandle = open(file_name, "r")
    for line in fhandle:
        print (line.upper()).rstrip()

except:
    print "file: ", file_name, "can not be opened in read mode"
    exit()


