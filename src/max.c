/**********************************************************************
 * Finds the largest value in an array.
 *
 * Parameters:
 *   a[] - the array
 *   count - the size of the array
 *
 * Return:
 *   the largest value in the array
 **********************************************************************/

int max(int a[], int count)
{
  int max = 0;
  int i;
  for(i = 0; i < count; i++)
  {
    if(a[i] > max) max = a[i];
  }
  return max;
}


// END
