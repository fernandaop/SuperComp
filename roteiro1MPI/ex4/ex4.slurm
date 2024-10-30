#!/bin/bash
#SBATCH --job-name=mpi_exercicio4
#SBATCH --ntasks=5
#SBATCH --time=00:05:00
#SBATCH --output=output_exercicio4_%j.txt

module load mpi
mpirun -np 5 ./exercicio4
