#include "sort_proc.h"
#include <algorithm>

void sort_proc(std::vector<std::string> &items, size_t n)
{
  int i, j, min;

  for (int i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i+1; j<n; j++)
    {
      if(items[j] < items[min]){
        min = j;
      }

      swap(items[i], items[j]);
    }

  }
}

void sort_proc(std::vector<std::string> &items)
{
  sort_proc(items, items.size());
  // TODO sort the items using a procedural programming style.
}
