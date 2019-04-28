#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that represent supplementary alignment

awk '$2 >= 2048 && $2 <= 2559' $1
