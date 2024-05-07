output: post1.o post3.o
	gcc -Wall post1.o post3.o -o output

post1: post1.c
	gcc -Wall -c post1.c -o post1.o

post3: post3.c
	gcc -Wall -c post3.c -o post3.o

run:
	./output

clean:
	rm *.o
