mpi:
	mpicc mpi.c -o mpi

run:
	-rm -rf mpi
	-rm -rf mpi.dSYM
	mpicc mpi.c -o mpi
	mpirun -np 4 ./mpi test.txt 10

clean:
	-rm -r mpi
	-rm -rf mpi.dSYM