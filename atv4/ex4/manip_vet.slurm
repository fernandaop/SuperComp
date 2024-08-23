#!/bin/bash
#SBATCH --job-name=manip_vet
#SBATCH --output=manip_vet.out
#SBATCH --error=manip_vet.err
#SBATCH --ntasks=1
#SBATCH --time=00:05:00
#SBATCH --partition=express
#SBATCH --mem=512M

# Executar o programa
srun ./manip_vet