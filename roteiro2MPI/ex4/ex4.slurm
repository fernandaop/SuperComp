#!/bin/bash
#SBATCH --job-name=exercicio4_mpi
#SBATCH --output=exercicio4_output.txt
#SBATCH --error=exercicio4_error.txt
#SBATCH --ntasks=4
#SBATCH --time=00:10:00
#SBATCH --partition=normal  # Substitua pela partição adequada

srun ./ex4