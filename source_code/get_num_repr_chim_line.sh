#! /bin/bash

grep $1 $2 | tr -d [:space:] | cut -c 1 > num_rep_reads.txt
