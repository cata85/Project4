#!/bin/sh

##### These lines are for Slurm
#SBATCH -t 10:00:00                #Maximum time required
#SBATCH -o Output/16core/openmp_T4_1000000.%j              #Output file name
#SBATCH --mem-per-cpu=1G
#SBATCH --constraint=elves
#SBATCH --nodes=1
#SBATCH --cpus-per-task=16

### Job commands start here
### Display some diagnostic information
echo '=====================JOB DIAGNOTICS========================'
date
echo -n 'This machine is ';hostname
echo -n 'My jobid is '; echo $SLURM_JOBID
echo 'My path is:' echo $PATH
echo 'My job info:'
squeue -j $SLURM_JOBID
echo 'Machine info'
sinfo -s

echo '=====================JOB STARTING=========================='

{ time srun openmp /homes/dan/625/wiki_dump.txt 1000000 4; } 2> Times/16core/openmp_T4_1000000.txt

echo '========================ALL DONE==========================='
