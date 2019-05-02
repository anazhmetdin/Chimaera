#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs a report with each chimeric locus and its supporting reads

rm ./pipline_run/directed_reads.sam 2> ./pipline_run/no_files.txt
rm ./pipline_run/filtered_chim_reads.sam 2> ./pipline_run/no_files.txt

./add_field_direction.sh $1
mv directed_reads.sam directed_reads1.sam
awk 'BEGIN{FS=OFS="\t"}{print $0 OFS "SA:"}' directed_reads1.sam > directed_reads.sam
mv directed_reads.sam ./pipline_run
rm directed_reads1.sam
echo done directed

./extract_chim_reads.sh ./pipline_run/directed_reads.sam -> ./pipline_run/filtered_chim_reads.sam
echo done chim

./extract_needed_fields.sh ./pipline_run/filtered_chim_reads.sam -> ./pipline_run/short_lines.sam
echo done needed


./build_hash_f.sh ./pipline_run/short_lines.sam

rm ./sup_reads_hash_function.gperf
