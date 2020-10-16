GCC := gcc

all: cpfiles build

cpfiles:
	rm -f kann.* 
	rm -f kautodiff.* 
	cp -a ../../kann.* .
	cp -a ../../kautodiff.* .

build:
	gcc -o main kann.c kautodiff.c main.c -lm