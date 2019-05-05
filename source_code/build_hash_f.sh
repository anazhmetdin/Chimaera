#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs hash_f.h which contains the information of the perfect hashing
# function for the input data

echo building gperf input file...
# make a list of unique Qnames, so that, the hash_f would hash only those reads
cut -f 2 $1 | sort | uniq > sup_reads_hash_function.gperf
echo building hash_f.h...
# build the function in C++ language
gperf -L C++ sup_reads_hash_function.gperf --output-file hash_f.h
echo function is ready.
