#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs filtered reads associated with variant structure

cat < ./extract_supl_reads.sh $1 < extract_unordered_reads.sh $1 < extract_supl_reads.sh $1 | sort | uniq -u
