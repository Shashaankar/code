#!/bin/python

import os

root_dir = os.getcwd()

for dirs,subdirs,files in os.walk(root_dir):
    print "directory name: ", dirs
    print "sub-directory names: ", subdirs
    for f in files:
        print "file list: ", f

