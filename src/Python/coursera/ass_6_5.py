#!/bin/python/

"""
6.5 Write code using find() and string slicing (see section 6.10) to
extract the number at the end of the line below. Convert the extracted
value to a floating point number and print it out.
"""

text = "X-DSPAM-Confidence:: 75";

try:
    col_pos = None
    col_pos = text.find(':')

    if col_pos != -1:
        for ch in text[col_pos+1:]:
            if ch.isdigit():
                # Print foating point number from here
                num_pos = text.find(ch)

                # Assuming the last few chars of the statement is always a
                # floating/integer number
                num = text[num_pos:] # get value until end
                num = float(num)
                print num
                break
    else:
        print "Error: wrong input statement"
except:
    print "Something wrong with the string"
    pass
