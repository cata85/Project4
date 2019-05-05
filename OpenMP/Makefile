openmp:
	gcc -o openmp openmp.c -fopenmp

run:
	-rm -f openmp
	gcc -fopenmp -o openmp openmp.c
	./openmp ../Base/shakespeare.txt 15000 1

clean:
	-rm -f openmp
