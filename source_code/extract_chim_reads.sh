#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs lines that represent supplementary alignment

grep '^@\|\sSA:' $1
