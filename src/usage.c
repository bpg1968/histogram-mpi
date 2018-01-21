/**********************************************************************
 * This is just a typical `usage()' function... nothing special here.
 *
 * Parameters:
 *   none
 *
 * Return:
 *   none
 **********************************************************************/
#include <stdio.h>


void
usage ()
{
  printf ("Usage:\n");
  printf ("  mpiexec [mpi_options] ./histogram [options] [< <datafile>]\n");
  printf ("\n");
  printf ("For mpi_options, please see man 1 mpiexec\n");
  printf ("\n");
  printf ("Options\n");
  printf ("  -b <number>  the number of bar to display in the histogram\n");
  printf ("                 (default is -b 5)\n");
  printf ("  -c <number>  the number of data items to read\n");
  printf ("                 (default is -c 2048\n");
  printf ("  -h           display this information\n");
  printf ("\n");
  printf ("Note: if reading data items from a file, -c should be less\n");
  printf ("      than or equal to the number of items in the file.\n");
  printf ("\n");
  printf ("Example:\n");
  printf ("  mpiexec ./histogram -b 10 -c 64 < data.txt\n");
  printf ("  Reads the first 64 numbers from the file `data.txt' and\n");
  printf ("  displays a histogram with 10 bars.\n");
}


// END
