/**********************************************************************
 * find the bin number in which the target belongs.
 * 
 * Parameters
 *   target: the target value
 *   bin_maxes[]: an array of upper values of the bins
 *   bin_count: the total number of bins
 *
 * Return
 *   the bin number in which the target belongs
 **********************************************************************/

int Find_bin(double target, double bin_maxes[], int bin_count)
{
  int i;

  for(i = 0; i < bin_count; i++)
  {
    if(target < bin_maxes[i]) return i;
  }
  return -1;
}


// END
