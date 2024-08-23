#!/bin/bash
#SBATCH --job-name=manipulacao_arquivos
#SBATCH --output=manipulacao_arquivos.out
#SBATCH --ntasks=1
#SBATCH --time=00:05:00
#SBATCH --mem=1GB

srun ./manipulacao_arquivos
