#!/bin/bash
#SBATCH --job-name=exercicio3_mpi
#SBATCH --output=exercicio3_output.txt
#SBATCH --error=exercicio3_error.txt
#SBATCH --ntasks=4
#SBATCH --time=00:10:00
#SBATCH --partition=normal  # Substitua pela partição adequada


srun ./ex3
