/**********************************************************************
 * This function reads data from stdin to an array and distributes that
 * array to each process. Process 0 reads in the data then distibutes
 * it to the other processes; the other processes wait to get the data
 * from process 0.
 *
 * There are no "Enter value" prompts because the easiest way to read
 * the large amounts of data required for this program is to redirect
 * the input from a file.
 *
 * Parameters:
 *   local_data[] - each process's array of data to operate on
 *   local_n - the number of items in the process's data array
 *   n - the total number of numbers to read
 *   my_rank - the process's rank
 *   comm - the comm world
 *
 * Return:
 *   no return value, although some parameters are used to return
 *   information to the calling function.
 **********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

void Read_data
(
  double local_data[],
  int local_n,
  int n,
  int my_rank,
  MPI_Comm comm
)
{
  double *data = NULL;
  int i;

  // only process 0 will read in the data from stdin
  if(my_rank == 0)
  {
    data = malloc(n*sizeof(double));
    for(i = 0; i < n; i++)
    {
      scanf("%lf", &data[i]);
    }
    MPI_Scatter(data, local_n, MPI_DOUBLE, local_data, local_n, MPI_DOUBLE, 0, comm);
    free(data);
  }
  // the other processes will wait to recieve their chunk of data from process 0
  else
  {
    MPI_Scatter(data, local_n, MPI_DOUBLE, local_data, local_n, MPI_DOUBLE, 0, comm);
  }
}


// END
