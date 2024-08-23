#!/bin/bash
#SBATCH --job-name=const_multiplication
#SBATCH --output=const_multiplication.out
#SBATCH --error=const_multiplication.err
#SBATCH --ntasks=1
#SBATCH --time=00:05:00
#SBATCH --partition=express
#SBATCH --mem=512M

srun ./const
