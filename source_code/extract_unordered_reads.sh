#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that are unordered

samtools view -f 0x40 $1 |samtools view -f 0x80
samtools view -F 0x40 $1 |samtools view -F 0x80
