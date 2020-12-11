all: build run


build:
	gcc -I ./ -o ./chain_heal ./chain_heal.c -lm

run:
	./chain_heal
	

