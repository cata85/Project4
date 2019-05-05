#!/bin/sh


# Setup
mpicc mpi.c -o mpi

# Cores: 1
sbatch Scripts/1core/mpi_N1_1000000.sh
sbatch Scripts/1core/mpi_N2_1000000.sh
sbatch Scripts/1core/mpi_N4_1000000.sh
sbatch Scripts/1core/mpi_N8_1000000.sh

# Cores: 2
sbatch Scripts/2core/mpi_N1_1000000.sh
sbatch Scripts/2core/mpi_N2_1000000.sh
sbatch Scripts/2core/mpi_N4_1000000.sh
sbatch Scripts/2core/mpi_N8_1000000.sh

# Cores: 4
sbatch Scripts/4core/mpi_N1_1000000.sh
sbatch Scripts/4core/mpi_N2_1000000.sh
sbatch Scripts/4core/mpi_N4_1000000.sh
sbatch Scripts/4core/mpi_N8_1000000.sh

# Cores: 8
sbatch Scripts/8core/mpi_N1_1000000.sh
sbatch Scripts/8core/mpi_N2_1000000.sh
sbatch Scripts/8core/mpi_N4_1000000.sh
sbatch Scripts/8core/mpi_N8_1000000.sh

# Cores: 16
sbatch Scripts/16core/mpi_N1_1000000.sh
sbatch Scripts/16core/mpi_N2_1000000.sh
sbatch Scripts/16core/mpi_N4_1000000.sh
sbatch Scripts/16core/mpi_N8_1000000.sh
