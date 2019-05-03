#!/bin/sh


# Setup
gcc -o base base.c

# Nodes: 1
sbatch Scripts/10K/base_N1_10000.sh
sbatch Scripts/100K/base_N1_100000.sh
sbatch Scripts/300K/base_N1_300000.sh
sbatch Scripts/500K/base_N1_500000.sh
sbatch Scripts/1000K/base_N1_1000000.sh

# Nodes: 2
sbatch Scripts/10K/base_N2_10000.sh
sbatch Scripts/100K/base_N2_100000.sh
sbatch Scripts/300K/base_N2_300000.sh
sbatch Scripts/500K/base_N2_500000.sh
sbatch Scripts/1000K/base_N2_1000000.sh

# Nodes: 4
sbatch Scripts/10K/base_N4_10000.sh
sbatch Scripts/100K/base_N4_100000.sh
sbatch Scripts/300K/base_N4_300000.sh
sbatch Scripts/500K/base_N4_500000.sh
sbatch Scripts/1000K/base_N4_1000000.sh

# Nodes: 8
sbatch Scripts/10K/base_N8_10000.sh
sbatch Scripts/100K/base_N8_100000.sh
sbatch Scripts/300K/base_N8_300000.sh
sbatch Scripts/500K/base_N8_500000.sh
sbatch Scripts/1000K/base_N8_1000000.sh

# Nodes: 16
sbatch Scripts/10K/base_N16_10000.sh
sbatch Scripts/100K/base_N16_100000.sh
sbatch Scripts/300K/base_N16_300000.sh
sbatch Scripts/500K/base_N16_500000.sh
sbatch Scripts/1000K/base_N16_1000000.sh
