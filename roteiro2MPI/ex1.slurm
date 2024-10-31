#!/bin/bash
#SBATCH --job-name=exercicio1_mpi
#SBATCH --output=exercicio1_output.txt
#SBATCH --error=exercicio1_error.txt
#SBATCH --ntasks=4           # Número de processos MPI
#SBATCH --time=00:10:00      # Tempo máximo de execução
#SBATCH --partition=standard # Partição a ser usada

srun ./ex1             # Executa o programa MPI
