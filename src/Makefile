# Makefile

# directory for header files
IDIR=include

# directory for object files
ODIR=../obj

# directory for executable file
BDIR=../bin

# directory for library files (not used at the moment)
LDIR=.

_DEPS=histogram.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=histogram.o read_data.o  process_data.o find_bin.o print_histogram.o display_histogram.o max.o process_args.o usage.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_TARGET=histogram
TARGET=$(patsubst %,$(BDIR)/%,$(_TARGET))

# the compiler:
#   `gcc` for C program
#   `g++` for C++
#   `mpicc` for C program using MPI
#   `mpic++` for C++ program using MPI
CC=mpicc

# compiler flags:
#   `-Wall` turns on most compiler warnings
#   `-g` adds debugging information to the executable file
#   `-I$(IDIR)` specify a path to header files
CFLAGS=-Wall -I$(IDIR)

# move files
MV=mv

# remove files
RM=rm

all: $(TARGET)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) $(FCLAGS) -o $@ $^

# just in case we have a file named 'clean'
.PHONY: clean

clean:
	$(RM) $(OBJ) $(TARGET)


# END
