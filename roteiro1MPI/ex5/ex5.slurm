#!/bin/bash
#SBATCH --job-name=mpi_exercicio5
#SBATCH --ntasks=4
#SBATCH --time=00:05:00
#SBATCH --mem=2G
#SBATCH --output=output_exercicio5_%j.txt

mpirun -np 4 ./exercicio5
