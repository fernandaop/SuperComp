#!/bin/bash
#SBATCH --job-name=alocacao_dinamica       # Nome do job
#SBATCH --output=alocacao_dinamica.out     # Arquivo de saída
#SBATCH --error=alocacao_dinamica.err      # Arquivo de erro
#SBATCH --ntasks=1                        # Número de tarefas (processos)
#SBATCH --time=00:05:00                   # Tempo máximo de execução
#SBATCH --mem=1G                         # Memória solicitada

# Executa o código
srun ./aloc1
