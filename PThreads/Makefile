pthreads:
	gcc -w -g pthreads.c -o pthread -lpthread 

run:
	-rm -rf pthreads
	-rm -rf pthreads.dSYM
	gcc -o -pthreads -g -Wall pthreads pthreads.c
	./pthreads test.txt 10

clean:
	-rm -r pthreads
	-rm -rf pthreads.dSYM