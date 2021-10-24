#! /bin/bash

# shell script that takes a SAM file name as an input
# and outputs a report with each chimeric locus and its supporting reads

# removing old files from any previous run
rm ./pipline_run/directed_reads.sam 2> ./pipline_run/no_files.txt
rm ./pipline_run/filtered_chim_reads.sam 2> ./pipline_run/no_files.txt
rm ./pipline_run/supported_loci.txt 2> ./pipline_run/no_files.txt
# store reads that have the chimeric alignment tag in a separate file
./extract_chim_reads.sh $1 > ./pipline_run/filtered_chim_reads.sam 2> ./pipline_run/corrupted_file.txt
echo done extracting chimeric reads
# add direaction to each read before the Qname:
# 0 for forward alignment
# 1 for reverse alignment
# !!!Disclaimer!!! the output file doesn't have headers
./add_field_direction.sh ./pipline_run/filtered_chim_reads.sam 2> ./pipline_run/corrupted_file.txt
echo done adding direction
mv ./directed_reads.sam ./pipline_run/directed_reads.sam 2> ./pipline_run/no_files.txt
# ask the user to build a new hashing function or not
# if you have ran this exact sample in the previous run:
#   -you could select (n)
# if you have NOT ran this exact sample in the previous run:
#   -you should select (y)
echo Do you want to build a new hash_function?
echo [y/n]?
read option
if [ $option == 'y' ]
then
  # build a new hash_f.h that stores the information of the perfect hashing
  # function for the input data
  ./build_hash_f.sh ./pipline_run/directed_reads.sam 2> ./pipline_run/corrupted_file.txt
  rm ./sup_reads_hash_function.gperf 2> ./pipline_run/no_files.txt
  # enable public access to the hashing function
  sed '44d' hash_f.h > hash_f1.h 2> ./pipline_run/corrupted_file.txt
  sed 's/private/public/' hash_f1.h > hash_f.h 2> ./pipline_run/corrupted_file.txt
  rm ./hash_f1.h 2> ./pipline_run/no_files.txt 2> ./pipline_run/no_files.txt
fi

#compile the main script in C++ language using g++ complier
g++ store_chi_reads.cpp linked.cpp table.cpp read_class.cpp node.cpp locus.cpp 2> ./pipline_run/corrupted_file.txt
#passing the input file to the main script
./a.out ./pipline_run/directed_reads.sam 2> ./pipline_run/corrupted_file.txt
