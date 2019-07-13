# Makefile for compiling a single program
# Also includes testing command
#
#
# don't echo the commands
MAKEFLAGS += --silent
#Variables
CFLAGS = -Wall -std=c++11 -g
CC = g++

# Replace with your own file names in the following two lines.
a.out:
	sh _TEST/configure.sh
	$(CC) $(CFLAGS) _TEST/PROGRAM.cc -o a.out



clean:
	rm -rf a.out *.o _TEST/a.out _TEST/PROGRAM.cc
