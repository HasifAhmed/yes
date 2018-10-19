all: list.o tunes.o driver.o
	gcc list.o tunes.o driver.o
run:
	./a.out

error: list.o tunes.o driver.o
	gcc -g list.o tunes.o driver.o

run2 :
	./a.out

check: list.o tunes.o driver.o
	gcc -g list.o tunes.o driver.o

clean:
	rm *.o

list.o: list.c list.h
	gcc -c list.c

tunes.o: tunes.h tunes.c
	gcc -c tunes.c

driver.o: driver.c
	gcc -c driver.c
