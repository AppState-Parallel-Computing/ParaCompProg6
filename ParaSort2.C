#include <string.h>
#include "ParaSort2.h"
#include "helpers.h"

/*
 * ParaSort2 constructor
 * Initialize threadCt and description.
 * Use constructor in parent Sorts class to initialize size and data.
 */
ParaSort2::ParaSort2(uint64_t size, int32_t * data, int32_t threadCt):Sorts(size, data)
{
  this->threadCt = threadCt;
  description = "Parallel Sort 2: create one task for each element\n";
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
double ParaSort2::sort()
{

  /* The parallelization in this code is similar to the parallelization
   * of the sort in ParaSort1 (which is based on problem 2, page 218). However,
   * instead of using a parallel for, it should create a task to handle
   * one iteration of the outer loop.  Thus, it will create size tasks.
   * In addition, threadCt threads will be created to handle the size tasks.
   * Task parallelism is covered in section 6.6.
   *
   * Use a lambda expression for clean code.  The lambda should be executed
   * by the task.
   */
  TIMERSTART(para)


  TIMERSTOP(para)
  return GETTIME(para);
}

