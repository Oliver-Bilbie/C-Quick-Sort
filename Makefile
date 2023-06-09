SHELL=/bin/bash

SOURCE_FILE=./src/main.c

.PHONY: run

run:
	@gcc ${SOURCE_FILE} -o compiled_c_file
	@./compiled_c_file
	@rm compiled_c_file

leak-check:
	@gcc ${SOURCE_FILE} -o compiled_c_file
	@valgrind --leak-check=full --show-leak-kinds=all ./compiled_c_file
	@rm compiled_c_file
