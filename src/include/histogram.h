#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <mpi.h>

// user-defined exit codes
// (should be restricted to the range 64 - 113)
#define IO_ERROR 64
#define IMPROPER_USAGE 65

struct arguments
{
  int bin_count;
  int data_count;
};

void Read_data (double[], int, int, int, MPI_Comm);
void Process_data (double[], int, double[], int[], int);
int Find_bin (double, double[], int);
void Print_histogram (double, double[], int[], int, int, MPI_Comm);
void Display_histogram (double, double[], int[], int);
int max (int[], int);
void Process_args (int *, char **[], struct arguments *, int);
void usage ();

#endif /* HISTOGRAM_H */


// END
