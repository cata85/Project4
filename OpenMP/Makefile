openmp:
	gcc -o openmp openmp.c -fopenmp -w

run:
	-rm -f openmp
	gcc -fopenmp -o openmp openmp.c
	./openmp test.txt 10

clean:
	-rm -f openmp