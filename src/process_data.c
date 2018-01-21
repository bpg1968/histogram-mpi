/**********************************************************************
 * This function is executed in it's entirety by each process, but each
 * process only works on its own chunk of data.
 *
 * Parameters:
 *   local_data[] - array containing the process's chunk of data
 *   local_data_count - the number of items in local_data[]
 *   bin_maxes[] - the upper limit of each bin
 *   bin_qty[] - the number of items that belong to each bin
 *   bin_count - the number of bins
 *
 * Return:
 *   no return value, although some parameters are used to return
 *   information to the calling function.
 **********************************************************************/
#include "histogram.h"

void Process_data
(
  double local_data[],
  int local_data_count,
  double bin_maxes[],
  int bin_qty[],
  int bin_count
)
{
  int local_i;
  int bin;

  for(local_i = 0; local_i < local_data_count; local_i++)
  {
    bin = Find_bin(local_data[local_i], bin_maxes, bin_count);
    ++bin_qty[bin];
  }
}


// END
