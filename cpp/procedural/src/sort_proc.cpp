#include "../include/sort_proc.h"
#include <string>

// https://en.wikipedia.org/wiki/Procedural_programming
// Procedural style modifys your intputs. Makes a bunch of adjustments to the list to sort and return the 
// re-adjust list.

void sort_proc(std::vector<std::string> &items, int left, int right) {
  left = 0;
  right = items.size();
  int i = 0, j = items.size();
    std::string pivot = items[(i + j) / 2];
    
    while (i <= j) {
        while (items[i] < pivot) i++;
        while (items[j] > pivot) j--;
        
        if (i <= j) {
            swap(items[i], items[j]);
            i++;
            j--;
        }
    }
    
    if (left < j) sort_proc(items, left, j);
    if (i < right) sort_proc(items, i, right);
}
