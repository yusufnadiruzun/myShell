CC=gcc

CFLAGS=-c -Wall

all:
	gcc islem.c -o islem
	gcc topla.c -o topla
	gcc cikar.c -o cikar
	gcc tekrar.c -o tekrar
	gcc myshell.c -o myshell
	./myshell
