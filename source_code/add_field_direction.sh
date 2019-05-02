#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs the same file with extra field before Qname for direction
# 0 for forward
# 1 for reverse

./forward_alignment.sh $1 | awk 'BEGIN{FS=OFS="\t"}{print "0" OFS $0}' >> directed_reads.sam

./reverse_alignment.sh $1 | awk 'BEGIN{FS=OFS="\t"}{print "1" OFS $0}' >> directed_reads.sam
