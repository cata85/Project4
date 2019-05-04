#!/bin/sh


# Setup
gcc -w -g pthreads.c -o pthreads -lpthread

# 2 Cores
sbatch Scripts/2core/pthreads_T1_1000000.sh
sbatch Scripts/2core/pthreads_T2_1000000.sh
sbatch Scripts/2core/pthreads_T4_1000000.sh
sbatch Scripts/2core/pthreads_T8_1000000.sh
sbatch Scripts/2core/pthreads_T16_1000000.sh
sbatch Scripts/2core/pthreads_T32_1000000.sh

# 4 Cores
sbatch Scripts/4core/pthreads_T1_1000000.sh
sbatch Scripts/4core/pthreads_T2_1000000.sh
sbatch Scripts/4core/pthreads_T4_1000000.sh
sbatch Scripts/4core/pthreads_T8_1000000.sh
sbatch Scripts/4core/pthreads_T16_1000000.sh
sbatch Scripts/4core/pthreads_T32_1000000.sh

# 8 Cores
sbatch Scripts/8core/pthreads_T1_1000000.sh
sbatch Scripts/8core/pthreads_T2_1000000.sh
sbatch Scripts/8core/pthreads_T4_1000000.sh
sbatch Scripts/8core/pthreads_T8_1000000.sh
sbatch Scripts/8core/pthreads_T16_1000000.sh
sbatch Scripts/8core/pthreads_T32_1000000.sh

# 16 Cores
sbatch Scripts/16core/pthreads_T1_1000000.sh
sbatch Scripts/16core/pthreads_T2_1000000.sh
sbatch Scripts/16core/pthreads_T4_1000000.sh
sbatch Scripts/16core/pthreads_T8_1000000.sh
sbatch Scripts/16core/pthreads_T16_1000000.sh
sbatch Scripts/16core/pthreads_T32_1000000.sh

