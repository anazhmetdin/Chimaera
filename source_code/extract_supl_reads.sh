#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that represent supplementary alignment

samtools view -f 0x800 $1
