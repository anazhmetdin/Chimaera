#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs a report with each chimeric locus and its supporting reads

rm ./pipline_run/directed_reads.sam
rm ./pipline_run/filtered_chim_reads.sam

./add_field_direction.sh $1 -> ./pipline_run/directed_reads.sam

./extract_chim_reads.sh ./pipline_run/directed_reads.sam -> ./pipline_run/filtered_chim_reads.sam

./extract_needed_fields.sh ./pipline_run/filtered_chim_reads.sam -> ./pipline_run/short_lines.sam

rm ./directed_reads.sam
rm ./filtered_chim_reads.sam

./build_hash_f.sh ./pipline_run/short_lines.sam

rm ./sup_reads_hash_function.gperf
