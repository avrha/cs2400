# Makefile for testing functions submitted with a main function
# It uses catch testing library
# Compile your program: make
# Run your program:  ./a.out
# Run tests: make run_tests
#

#Variables
CFLAGS = -Wall -std=c++11
CC = g++

# Replace with your own file names.
a.out: myset-main.o myset.o
	$(CC) $(CFLAGS) myset-main.o myset.o -o a.out

myset-main.o: myset-main.cc
	$(CC) -c $(CFLAGS) myset-main.cc

myset.o:
	$(CC) -c $(CFLAGS) myset.cc
	
########################### DO NOT MODIFY THIS RULE ############################
#                           make and run the tests                             #
run_tests:
	$(CC) -c $(CFLAGS) myset.cc -o _TEST/myset.o
	head myset.h
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc _TEST/myset.o -o _TEST/run_tests && ./_TEST/run_tests -sr compact
#	rm -rf ./_TEST/NO_MAIN.cc ./_TEST/run_tests
################################################################################


clean:
	rm -rf a.out *.o _TEST/*.o _TEST/a.out
