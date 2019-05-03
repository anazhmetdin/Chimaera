#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs a report with each chimeric locus and its supporting reads

rm ./pipline_run/directed_reads.sam 2> ./pipline_run/no_files.txt
rm ./pipline_run/filtered_chim_reads.sam 2> ./pipline_run/no_files.txt
rm ./pipline_run/supported_loci.txt 2> ./pipline_run/no_files.txt

awk 'BEGIN{FS=OFS="\t"} {if($0 ~ /^[^@]/) print $0 OFS "SA:Z:2"; else print $0}' $1 > ./pipline_run/tagged_chim.sam
echo done tagging

./extract_chim_reads.sh ./pipline_run/tagged_chim.sam  -> ./pipline_run/filtered_chim_reads.sam
echo done chim

head -n 20000 ./pipline_run/filtered_chim_reads.sam > ./pipline_run/short_lines.sam

./add_field_direction.sh ./pipline_run/short_lines.sam
echo done directed

mv ./directed_reads.sam ./pipline_run/directed_reads.sam

echo Do you want to build a new hash_function?
echo [y/n]?
read option
if [ $option == 'y' ]
then
  ./build_hash_f.sh ./pipline_run/directed_reads.sam
  rm ./sup_reads_hash_function.gperf 2> ./pipline_run/no_files.txt

  sed '44d' hash_f.h > hash_f1.h
  sed 's/private/public/' hash_f1.h > hash_f.h
  rm ./hash_f1.h 2> ./pipline_run/no_files.txt
fi


g++ store_chi_reads.cpp linked.cpp table.cpp read_class.cpp node.cpp locus.cpp

./a.out ./pipline_run/directed_reads.sam
