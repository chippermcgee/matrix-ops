#!/bin/bash 

#PBS N MatMul_1000_mullencr 
#PBS l walltime=1:00:00 
#PBS l mem=4GB 
#PBS l nodes=1:ppn=1 

cd $PBS_O_WORKDIR
MAT_SIZE=1000
BLOCK_SIZE=50 


for rep in `seq 1 5`
do
     echo '-------------------------[hw4 1000x1000 without blocks]-----------------------'
     perf stat -e cache-misses,cache-references ./MatMul $MAT_SIZE 0
     echo '-------------------------[hw4 1000x1000 with blocking] -----------------------'
     perf stat -e cache-misses,cache-references ./MatMul $MAT_SIZE $BLOCK_SIZE
done 

# end of script
