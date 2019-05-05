#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that represent chimeric alignment

# the script extract lines with the specified tag by SAMv1 documentations:
#   -https://samtools.github.io/hts-specs/SAMv1.pdf
grep '^@\|\sSA:' $1
