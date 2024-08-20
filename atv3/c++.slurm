#!/bin/bash
#SBATCH --job-name=atv3
#SBATCH --output=c_%j.txt
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem=1024
#SBATCH --time=00:10:00
#SBATCH --partition=espec

./at1