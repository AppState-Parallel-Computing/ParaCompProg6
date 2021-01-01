#ifndef SEQSORT1_H
#define SEQSORT1_H
#include "Sorts.h"
class SeqSort : public Sorts
{
  private:
  public:
    SeqSort(uint64_t size, int32_t * data);
    double sort();
};
#endif
