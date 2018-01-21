/**********************************************************************
 * This function uses the getopt library to process command line
 * arguments. If this function needs to output any information (error
 * messages, usage information, etc.), only process 0 will produce
 * output.
 * 
 * Parameters:
 *   *argc - the number of arguments passed on the command line
 *   **argv[] - the arguments passed on the command line
 *   *args - a structure for returning the options set by the command
 *           line arguments
 *   my_rank - the rank of the calling process
 *
 * Return:
 *   there is no return value, but the options set are returned to the
 *   calling function via a struct passed as a parameter.
 **********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "histogram.h"


void
Process_args (int *argc, char **argv[], struct arguments *args, int my_rank)
{
  // set defaults
  args->bin_count = 5;
  args->data_count = 2048;

  int c;
  opterr = 0;

  while ((c = getopt (*argc, *argv, "b:c:h")) != -1)
    {
      switch (c)
        {
        case 'b':
          if (optarg)
            args->bin_count = atoi (optarg);
          break;
        case 'c':
          if (optarg)
            args->data_count = atoi (optarg);
          break;
        case 'h':
          if (my_rank == 0)
            usage ();
          MPI_Finalize ();
          exit (0);
        case '?':
          if (my_rank == 0)
            {
              if (optopt == 'b' || optopt == 'c')
                fprintf (stderr, "Option -%c requires an integer argument.\n",
                         optopt);
              else if (isprint (optopt))
                fprintf (stderr, "Unknown option -%c.\n", optopt);
              else
                fprintf (stderr, "Unknown option character `\\x%x'.\n",
                         optopt);
              usage ();
            }
          MPI_Finalize ();
          exit (IMPROPER_USAGE);
        default:
          abort ();
        }
    }
}


// END
