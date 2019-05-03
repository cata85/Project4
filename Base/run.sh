#!/bin/sh


# Nodes: 1
sbatch Scripts/base_N1_10000.sh
sbatch Scripts/base_N1_100000.sh
sbatch Scripts/base_N1_300000.sh
sbatch Scripts/base_N1_500000.sh
sbatch Scripts/base_N1_1000000.sh
