#include <stdio.h>
#include <mpi.h>
#include "histogram.h"


int
main (int argc, char *argv[])
{
  int comm_sz;
  int my_rank;
  MPI_Init (&argc, &argv);
  MPI_Comm_size (MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);

  struct arguments args;
  Process_args (&argc, &argv, &args, my_rank);

  int bin_count = args.bin_count;
  int data_count = args.data_count;
  double min_meas = 0;
  double max_meas = 10;
  int local_data_count = data_count / comm_sz;
  double local_data[local_data_count];
  double bin_maxes[bin_count];
  int bin_qty[bin_count];
  double bin_width = (max_meas - min_meas) / bin_count;
  int b;

  // initialize the arrays bin_maxes[] and bin_qty[]
  for (b = 0; b < bin_count; b++)
    {
      bin_maxes[b] = min_meas + bin_width * (b + 1);
      bin_qty[b] = 0;
    }

  Read_data (local_data, local_data_count, data_count, my_rank,
             MPI_COMM_WORLD);
  Process_data (local_data, local_data_count, bin_maxes, bin_qty, bin_count);
  Print_histogram (min_meas, bin_maxes, bin_qty, bin_count, my_rank,
                   MPI_COMM_WORLD);

  MPI_Finalize ();

  return 0;
}


// END
