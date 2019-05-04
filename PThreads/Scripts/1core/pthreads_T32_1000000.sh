#!/bin/sh

##### These lines are for Slurm
#SBATCH -t 10:00:00                #Maximum time required
#SBATCH -o Output/pthreads_T32_1000000.%j              #Output file name
#SBATCH --mem-per-cpu=16G
#SBATCH --constraint=elves

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

{ time srun --nodes=1 --cpus-per-task=1 pthreads /homes/dan/625/wiki_dump.txt 1000000 32; } 2> Times/pthreads_T32_1000000.txt

echo '========================ALL DONE==========================='
