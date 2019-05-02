#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs field that are needed for read_class

cut -f 1,2,3,4,5,6,10 $1
