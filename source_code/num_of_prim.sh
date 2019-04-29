#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs number of primary reads

samtools view -F 0x100 $1 | wc -l
