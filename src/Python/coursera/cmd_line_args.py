#!/usr/bin/python


import os
from optparse import OptionParser



def main():
    usage = "usage: %prog [options] arg1 agr2"
    parser = OptionParser(usage=usage)
    parser.add_option("-f", "--file", dest="filename", help="read data\
            from FILENAME")
    parser.add_option("-o", "--out", action="store", type="string",\
            dest="output")
    parser.add_option("-v", "--verbose", action="store_true",\
            dest="verbose",default="False")
    parser.add_option("-q", "--quiet", action="store_false",\
            dest="verbose", default="True")
    parser.add_option("-m", "--mode", default="intermediate",\
            help="interaction mode: novice, intermediate, or expert\
            [default: %default]")

    (options, args) = parser.parse_args()
    if len(args) != 1:
        parser.error("incorrect number of arguments")

    if options.verbose:
        print "reading %s..." % options.filename

    # Custom code







if __name__ == "__main__":
    main() 
