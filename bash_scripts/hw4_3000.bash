#!/bin/bash 

#PBS N MatMul_1000_mullencr 
#PBS l walltime=1:00:00 
#PBS l mem=4GB 
#PBS l nodes=1:ppn=1 

cd $PBS_O_WORKDIR
MAT_SIZE=3000
BLOCK_SIZE=50 


for rep in `seq 1 5`
do
     echo '-------------------------[hw4 1000x1000 without blocks]-----------------------'
     /usr/bin/time -v ./MatMul $MAT_SIZE 0
     echo '-------------------------[hw4 1000x1000 with blocking] -----------------------'
     /usr/bin/time -v ./MatMul $MAT_SIZE $BLOCK_SIZE
done 

# end of script
