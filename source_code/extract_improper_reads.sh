#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that has unproper alignment

samtools view -F 0x2 $1
