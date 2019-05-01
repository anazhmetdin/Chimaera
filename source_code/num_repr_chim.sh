#! /bin/bash

./extract_repr_reads.sh $1 | cut -f 1 | sort | uniq -c
