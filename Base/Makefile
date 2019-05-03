base:
	gcc -o base base.c

run:
	-rm -rf base
	-rm -rf base.dSYM
	gcc -o base base.c
	./base test.txt 10

clean:
	-rm -r base
	-rm -rf base.dSYM