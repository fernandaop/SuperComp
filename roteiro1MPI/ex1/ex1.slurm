#!/bin/bash
#SBATCH --job-name=mpi_exercicio1
#SBATCH --ntasks=2
#SBATCH --time=00:05:00
#SBATCH --mem=2G
#SBATCH --output=output_exercicio1_%j.txt

mpirun -np 2 ./exercicio1
