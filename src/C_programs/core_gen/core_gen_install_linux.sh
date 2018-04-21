#!/bin/sh

### script to install tools and set configuration to generate core file generation

## Install from internet utilites required
sudo apt-get install gdb
sudo apt-get install gcore


## Set environmental configuration requiredj
ulimit -c unlimited # you can change this to some fixed size value

