#! /bin/bash

echo building gperf input file...
head -n 20000 $1 | cut -f 1 | sort | uniq > sup_reads_hash_function.gperf
echo building hash_f.h...
gperf -L C++ sup_reads_hash_function.gperf --output-file hash_f.h


