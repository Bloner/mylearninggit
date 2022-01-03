step12: step12a.o step12b.o step12c.o
		gcc -o step12 step12a.o step12b.o step12c.o

step12a.o: step12a.c step12a.h step12c.h
		gcc -c step12a.c
	
step12b.o: step12b.c step12a.h
		gcc -c step12b.c

step12c.o: step12c.c step12c.h step12a.h
		gcc -c step12c.c

clean:
		rm -f *.o step12a
