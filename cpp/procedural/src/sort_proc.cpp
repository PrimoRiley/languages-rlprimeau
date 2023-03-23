#include "sort_proc.h"
#include <algorithm>
#include<iostream>

void sort_proc(std::vector<std::string> &items, size_t n)
{
  int i, j, min;
  //std::cout<<n<<std::endl;

  for (int i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i+1; j<n; j++)
    {
      if(items[j] < items[min]){
        min = j;
      }
    }
    if(min != i)
      swap(items[i], items[j]);
  }

}

void sort_proc(std::vector<std::string> &items)
{
  if(items.size() != 0)
    sort_proc(items, items.size());
  // TODO sort the items using a procedural programming style.
}
