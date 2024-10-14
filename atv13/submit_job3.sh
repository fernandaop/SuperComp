#!/bin/bash
#SBATCH --job-name=vetor_inserts
#SBATCH --output=vetor_inserts.txt
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --time=00:05:00
#SBATCH --mem=8G

./vetor_insert
./vetor_insert2