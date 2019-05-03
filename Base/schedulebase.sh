#!/bin/csh


##### These lines are for Slurm
#SBATCH -N 1                      #Number of nodes to use
#SBATCH -p pReserved              #Workshop queue
#SBATCH -t 15:00                   #Maximum time required
#SBATCH -o output.%j              #Output file name
#SBATCH --mem-per-cpu=1G
#SBATCH --ntask=16

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


# Nodes 1 ********************************************************************************************
gcc -w -g base.c -o base -lbase
#Run the code
time srun -N1 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 10000 > base_N1_10000.txt
time srun -N1 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 100000 > base_N1_100000.txt
time srun -N1 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 300000 > base_N1_300000.txt
time srun -N1 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 500000 > base_N1_500000.txt
time srun -N1 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 1000000 > base_N1_1000000.txt


# Nodes 2 ********************************************************************************************
gcc -w -g base.c -o base -lbase
#Run the code
time srun -N2 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 10000 > base_N2_10000.txt
time srun -N2 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 100000 > base_N2_100000.txt
time srun -N2 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 300000 > base_N2_300000.txt
time srun -N2 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 500000 > base_N2_500000.txt
time srun -N2 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 1000000 > base_N2_1000000.txt
### Issue the sleep so we have time to see the job actually running


# Nodes 4 ********************************************************************************************
gcc -w -g base.c -o base -lbase
#Run the code
time srun -N4 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 10000 > base_N4_10000.txt
time srun -N4 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 100000 > base_N4_100000.txt
time srun -N4 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 300000 > base_N4_300000.txt
time srun -N4 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 500000 > base_N4_500000.txt
time srun -N4 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 1000000 > base_N4_1000000.txt
### Issue the sleep so we have time to see the job actually running


# Nodes 8 ********************************************************************************************
gcc -w -g base.c -o base -lbase
#Run the code
time srun -N8 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 10000 > base_N8_10000.txt
time srun -N8 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 100000 > base_N8_100000.txt
time srun -N8 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 300000 > base_N8_300000.txt
time srun -N8 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 500000 > base_N8_500000.txt
time srun -N8 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 1000000 > base_N8_1000000.txt
### Issue the sleep so we have time to see the job actually running


# Nodes 16 *******************************************************************************************
gcc -w -g base.c -o base -lbase
#Run the code
time srun -N16 --mem-per-cpu=200M -t1./base /homes/dan/625/wiki_dump.txt 10000 > base_N16_10000.txt
time srun -N16 --mem-per-cpu=200M -t1./base /homes/dan/625/wiki_dump.txt 100000> base_N16_100000.txt
time srun -N16 --mem-per-cpu=200M -t1./base /homes/dan/625/wiki_dump.txt 300000 > base_N16_300000.txt
time srun -N16 --mem-per-cpu=200M -t1./base /homes/dan/625/wiki_dump.txt 500000 > base_N16_500000.txt
time srun -N16 --mem-per-cpu=200M -t1./base /homes/dan/625/wiki_dump.txt 1000000 > base_N16_1000000.txt
### Issue the sleep so we have time to see the job actually running


# Nodes 32 *******************************************************************************************
gcc -w -g base.c -o base -lbase
#Run the code
time srun -N32 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 10000 > base_N32_10000.txt
time srun -N32 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 100000> base_N32_100000.txt
time srun -N32 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 300000 > base_N32_300000.txt
time srun -N32 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 500000 > base_N32_500000.txt
time srun -N32 --mem-per-cpu=200M -t1 ./base /homes/dan/625/wiki_dump.txt 1000000 > base_N32_1000000.txt
### Issue the sleep so we have time to see the job actually running



sleep 120
echo ' '
echo '========================ALL DONE==========================='
