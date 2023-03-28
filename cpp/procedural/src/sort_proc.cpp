#include "sort_proc.h"
#include <algorithm>
#include<iostream>

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
    }
    if(min != i)
		{
        	// Swap
			std::string temp = items[i];
			items[i] = items[min];
			items[min] = temp;
		}
  }
  //std::cout<<"Done!"<<std::endl;
}

void sort_proc(std::vector<std::string> &items)
{
  if(items.size() != 0)
    sort_proc(items, items.size());
  // TODO sort the items using a procedural programming style.
}
