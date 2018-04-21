#!/bin/python

"""
7.2 Write a program that prompts for a file name, then opens that file
and reads through the file, looking for lines of the form:
X-DSPAM-Confidence:    0.8475
Count these lines and extract the floating point values from each of
the lines and compute the average of those values and produce an
output as shown below.
You can download the sample data at
http://www.pythonlearn.com/code/mbox-short.txt when you are testing
below enter mbox-short.txt as the file name.
"""
import logging

file_name = raw_input("Enter file name: ")

logging.basicConfig(level=logging.INFO, format='%(asctime)s %(levelname)s %(message)s', filename='./dbg.log', filemode='w') 

try:
    count=0
    float_sum=0

    fhandle = open(file_name, "r")
    for line in fhandle:
        if not line.startswith("X-DSPAM-Confidence"):
            continue

        # If control reaces here then we got the line
        line = line.split(":")
        float_num = line[1].strip()

        try:
            float_num = float(float_num)
        except:
            print "Error: not a float value"
            exit()

        count += 1
        float_sum += float_num

    # At the end
    logging.info(count)
    logging.info(float_sum)
    print "Average spam confidence: ", (float_sum/count)

except:
    print "Error: file: ", file_name, "error in reading"
    exit()



