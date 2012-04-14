#!/bin/bash

#$ -V
#$ -cwd
#$ -q development
#$ -pe 12way 12
#$ -N parallel_bfsb
#$ -o output_merge
#$ -e error_merge
#$ -M adityasarawgioo7@gmail.com
#$ -m be
#$ -l h_rt=01:00:00

export PATH=$PATH:$HOME/cilk/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/cilk/lib
./parallel_bfsb < /work/01905/rezaul/CSE613/HW2/samples/sample-02-in.txt > temp.txt
