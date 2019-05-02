#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that are reverse aligned

samtools view -f 0x10 $1
