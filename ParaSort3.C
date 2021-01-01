#include <string.h>
#include "ParaSort3.h"
#include "helpers.h"

/*
 * ParaSort3 constructor
 * Initialize threadCt and description.
 * Use constructor in parent Sorts class to initialize size and data.
 */
ParaSort3::ParaSort3(uint64_t size, int32_t * data, int32_t threadCt):Sorts(size, data)
{
  this->threadCt = threadCt;
  description = "Parallel Sort 3: Parallelizes the calculation of the destination of an element\n";
}

/*
 * sort
 * Sorts an array of int32_t values using OpenMP threads. 
 * Input:
 * data - array of int32_t values
 * size - number of elements in the array
 * threadCt - number of threads to use to perform the sort
 * Modifies:
 * data - elements of data array in increasing sorted order
 */

double ParaSort3::sort()
{
  /* The first and second versions of the sort parallelized the outer most
   * loop.  However, the innermost loop can also be parallelized.  That is,
   * instead of using only one thread to determine the destination of data[i],
   * multiple threads can be doing that and their counts can be added together
   * (a reduction).
   * In this version, you'll parallelize the outermost for loop and create 
   * threadCt threads to do it.  And, you'll parallelize the innermost for loop
   * by creating 8 threads to do that (that is, 8 threads per each iteration of
   * the i loop). Treat the array so that it is divided into 8 chunks so that each
   * of the threads calculates count for one chunk of the array. Those counts need
   * to be added together to calculate the destination of data[i]. (Basically, you'll
   * want to put the j loop inside of another loop that is executed 8 times.  But the
   * j loop indices won't range from 0 to size - 1.  They'll only iterate through
   * 1/8th of the array. 
   * Use a lambda expression for clean code.
   */

  TIMERSTART(para)


  TIMERSTOP(para)
  return GETTIME(para);
}

