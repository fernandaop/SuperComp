#!/bin/bash
#SBATCH --job-name=exercicio1_mpi
#SBATCH --output=exercicio1_output.txt
#SBATCH --error=exercicio1_error.txt
#SBATCH --ntasks=4
#SBATCH --time=00:10:00
#SBATCH --partition=normal  # Alterado para a partição 'normal'


srun ./ex1
