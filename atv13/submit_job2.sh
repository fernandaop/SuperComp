#!/bin/bash
#SBATCH --job-name=opi_recursivos
#SBATCH --output=pi_recursivos.txt
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --time=00:05:00
#SBATCH --mem=8G

./pi_recursivo
./pi_recursivo2