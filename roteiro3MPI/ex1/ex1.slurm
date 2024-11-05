#!/bin/bash
#SBATCH --job-name=exercicio1_mpi
#SBATCH --output=exercicio1_output.txt
#SBATCH --error=exercicio1_error.txt
#SBATCH --ntasks=4
#SBATCH --time=00:10:00
#SBATCH --partition=normal  # Substitua pela partição adequada

srun ./ex1