all:
	gcc -Wall -o toylang interp.c exec.c parse.c stack.c

clean: 
	 $(RM) toylang tests/parse_command_test tests/scan_file_test tests/exec_test

test:
	cd tests; gcc -g -o scan_file_test parser_scanfile_test.c ../parse.c; ./scan_file_test; gcc -g -o parse_command_test parser_parse_command_test.c ../parse.c;./parse_command_test;gcc -g -o exec_test exec_operator_tests.c ../exec.c ../stack.c; ./exec_test;cd ..;$(MAKE) clean
debug:
	gcc -Wall -Wpedantic -Wextra -Werror -g -o toylang interp.c exec.c parse.c stack.c

