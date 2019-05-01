#! /bin/bash

./extract_chim_reads.sh $1 > chimeric_reads.sam

cut -f 1 chimeric_reads.sam | sort | uniq > list_uniq_chim_reads.txt

while read line; do
  grep $line chimeric_reads.sam > multiple_mapping_one_read.sam
  highest_mapQ=$(cut -f 5 multiple_mapping_one_read.sam | head -n 1)
  awk -v value=0.75*$highest_mapQ '$5 >= value' multiple_mapping_one_read.sam >> filtered_chim_reads.sam
done <list_uniq_chim_reads.txt
