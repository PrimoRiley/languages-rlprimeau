#include "../include/sort_proc.h"
#include <string>

// https://en.wikipedia.org/wiki/Procedural_programming
// Procedural style modifys your intputs. Makes a bunch of adjustments to the list to sort and return the 
// re-adjust list. This is selection sort in a procedural style. 

void sort_proc(std::vector<std::string> &items) {
  int n = items.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i+1; j<n; j++) {
            if (items[j] < items[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::string temp = items[i];
            items[i] = items[minIndex];
            items[minIndex] = temp;
        }
    }
}

