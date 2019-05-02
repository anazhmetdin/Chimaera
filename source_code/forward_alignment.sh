#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that are forward aligned

samtools view -F 0x10 $1
