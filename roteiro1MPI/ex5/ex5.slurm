#!/bin/bash
#SBATCH --job-name=mpi_exercicio5
#SBATCH --ntasks=4
#SBATCH --time=00:05:00
#SBATCH --output=output_exercicio5_%j.txt

module load mpi
mpirun -np 4 ./exercicio5
