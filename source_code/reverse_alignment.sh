#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that are reverse aligned
# !!!Disclaimer!!! the output file doesn't have headers

samtools view -f 0x10 $1
