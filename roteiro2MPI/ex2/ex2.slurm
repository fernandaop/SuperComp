#!/bin/bash
#SBATCH --job-name=exercicio2_mpi
#SBATCH --output=exercicio2_output.txt
#SBATCH --error=exercicio2_error.txt
#SBATCH --ntasks=4
#SBATCH --time=00:05:00
#SBATCH --partition=normal  # Substitua pela partição adequada

srun ./ex2
