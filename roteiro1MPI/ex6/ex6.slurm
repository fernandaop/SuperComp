#!/bin/bash
#SBATCH --job-name=mpi_exercicio6
#SBATCH --ntasks=5
#SBATCH --time=00:05:00
#SBATCH --mem=2G
#SBATCH --output=output_exercicio6_%j.txt

mpirun -np 5 ./exercicio6
