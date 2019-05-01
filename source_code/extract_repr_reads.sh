#! /bin/bash

./extract_tagged_chimeric_reads.sh $1 | samtools view -F 0x800
