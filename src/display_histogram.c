/**********************************************************************
* This is a sequential function called by process 0 to display the
* histogram.
*
* Parameters:
*   min - the smallest value on the x axis of the histogram
*   maxes[] - the upper limit of each bin
*   quantities[] - the number of values in each bin
*   count - the number of bins
*
* Return:
*   none.
**********************************************************************/
#include <stdio.h>
#include "histogram.h"
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 53
#define X_AXIS_MARGIN 3
#define Y_AXIS_MARGIN 6


void
Display_histogram (double min, double maxes[], int quantities[], int count)
{
  int i, line, column;
  int max_qty = max (quantities, count);
  int graph_height = SCREEN_HEIGHT - X_AXIS_MARGIN;
  int graph_width = SCREEN_WIDTH - Y_AXIS_MARGIN;
  int bar;                      // the current bar number
  int last_col;

  for (i = 0; i < count; i++)
    {
      quantities[i] = (quantities[i] * graph_height) / max_qty;
    }

  for (line = graph_height; line > 0; line--)
    {
      if (line % (graph_height / 5) == 0)
        printf ("%4d-|", max_qty * line / graph_height);
      else
        printf ("     |");
      column = 0;
      bar = 0;
      while (bar < count)
        {
          last_col = (bar + 1) * graph_width / count - 1;
          if (quantities[bar] >= line)
            putchar ('/' + (bar % 2) * 45);
          else
            putchar (' ');
          if (column == last_col)
            bar++;
          column++;
        }
      printf ("\n");
    }

/* print bottom margin */
/* print the x axis */
  printf ("   0-+");
  column = 0;
  bar = 0;
  while (bar < count)
    {
      last_col = (bar + 1) * graph_width / count - 1;
      if (column == last_col)
        {
          putchar ('+');
          bar++;
        }
      else
        {
          putchar ('-');
        }
      column++;
    }
  printf ("\n");

/* print the tick marks on the x axis */
  printf ("     |");
  column = 0;
  bar = 0;
  while (bar < count)
    {
      last_col = (bar + 1) * graph_width / count - 1;
      if (column == last_col)
        {
          putchar ('|');
          bar++;
        }
      else
        {
          putchar (' ');
        }
      column++;
    }
  printf ("\n");

/* print the numbers on the x axis */
  printf ("     0");
  column = 0;
  bar = 0;
  while (bar < count)
    {
      last_col = (bar + 1) * graph_width / count - 2;
      if (column == last_col)
        {
          if (bar == count - 1)
            printf ("%2.0f", maxes[bar]);
          else
            printf ("%2.1f", maxes[bar]);
          column += 2;
          bar++;
        }
      else
        {
          putchar (' ');
        }
      column++;
    }
  printf ("\n");
}


// END
