#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that are forward aligned
# !!!Disclaimer!!! the output file doesn't have headers

samtools view -F 0x10 $1
