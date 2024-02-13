all:
	gcc -g -Wall -o toylang interp.c exec.c parse.c stack.c

  clean: 
	 $(RM) toylang