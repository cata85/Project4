#!/bin/sh

##### These lines are for Slurm
#SBATCH -t 10:00:00                #Maximum time required
#SBATCH -o Output16core//pthreads_T2_1000000.%j              #Output file name
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

{ time srun pthreads /homes/dan/625/wiki_dump.txt 1000000 2; } 2> Times/16core/pthreads_T2_1000000.txt

echo '========================ALL DONE==========================='
