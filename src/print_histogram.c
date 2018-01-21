/**********************************************************************
 * This function amalgamates the work done my all the processes and
 * displays the histogram.
 *
 * All processes send their results to process 0. Process 0 collects
 * the work from all other processes and calls the function that
 * actually outputs the histogram.
 *
 * Parameters:
 *   min - the smallest value on the x axis of the histogram
 *   maxes[] - the upper limit of each bin
 *   local_bin_qty[] - the number of values in each bin
 *   bin_count - the number of bins
 *   my_rank - the number of this process
 *   comm - the comm world
 *
 * Return:
 *   none.
 **********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include "histogram.h"


void Print_histogram
(
    double min,
    double maxes[],
    int local_bin_qty[],
    int bin_count,
    int my_rank,
    MPI_Comm comm
)
{
  int *bin_qty = NULL;
  // int i;

  if(my_rank == 0)
  {
    bin_qty = malloc(bin_count*sizeof(double));
    MPI_Reduce(local_bin_qty, bin_qty, bin_count, MPI_INT, MPI_SUM, 0, comm);
    Display_histogram(min, maxes, bin_qty, bin_count);
  }
  else
  {
    MPI_Reduce(local_bin_qty, bin_qty, bin_count, MPI_INT, MPI_SUM, 0, comm);
  }
}


// END
