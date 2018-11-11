all main.out:
	gcc -o main.out main.c

run: main.out
	clear
	./main.out
