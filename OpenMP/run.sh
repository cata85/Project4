#!/bin/sh


# Setup
gcc -w -g openmp.c -o openmp -lpthread

# 1 Core
sbatch Scripts/1core/openmp_T1_1000000.sh
sbatch Scripts/1core/openmp_T2_1000000.sh
sbatch Scripts/1core/openmp_T4_1000000.sh
sbatch Scripts/1core/openmp_T8_1000000.sh
sbatch Scripts/1core/openmp_T16_1000000.sh
sbatch Scripts/1core/openmp_T32_1000000.sh

# 2 Cores
sbatch Scripts/2core/openmp_T1_1000000.sh
sbatch Scripts/2core/openmp_T2_1000000.sh
sbatch Scripts/2core/openmp_T4_1000000.sh
sbatch Scripts/2core/openmp_T8_1000000.sh
sbatch Scripts/2core/openmp_T16_1000000.sh
sbatch Scripts/2core/openmp_T32_1000000.sh

# 4 Cores
sbatch Scripts/4core/openmp_T1_1000000.sh
sbatch Scripts/4core/openmp_T2_1000000.sh
sbatch Scripts/4core/openmp_T4_1000000.sh
sbatch Scripts/4core/openmp_T8_1000000.sh
sbatch Scripts/4core/openmp_T16_1000000.sh
sbatch Scripts/4core/openmp_T32_1000000.sh

# 8 Cores
sbatch Scripts/8core/openmp_T1_1000000.sh
sbatch Scripts/8core/openmp_T2_1000000.sh
sbatch Scripts/8core/openmp_T4_1000000.sh
sbatch Scripts/8core/openmp_T8_1000000.sh
sbatch Scripts/8core/openmp_T16_1000000.sh
sbatch Scripts/8core/openmp_T32_1000000.sh
