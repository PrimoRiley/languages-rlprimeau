#include <iostream>
#include "sort_func.h"
#include "utility.h"
#include "merger.h"

#if 0
template <typename T, typename Ordered = std::less < T > >
std::vector<T> sort_func(typename std::vector<T>::const_iterator begin, 
                          typename std::vector<T>::const_iterator end) {
  typename std::vector<T>::difference_type size =  end - begin;
  if (size <= 1) {
    return std::vector<T>(begin,end);
  }

  auto a0 = begin;
  auto a1 = a0 + size/2;
  auto b0 = a1;
  auto b1 = end;

  auto a = sort_func<T,Ordered>(a0,a1);
  auto b = sort_func<T,Ordered>(b0,b1);

  merger<typename std::vector<T>::const_iterator,typename std::vector<T>::const_iterator,Ordered> m(a.begin(),a.end(),b.begin(),b.end());
  return std::vector < T > (m.begin(),m.end());
}
#endif

std::vector<std::string> merge(const std::vector<std::string> &a, const std::vector<std::string> &b) {
  if (a.size() == 0) return b;
  if (b.size() == 0) return a;

  if (b[0] < a[0]) {
    return vec(b[0],merge(a,slice(b,1,b.size())));
  } else {
    return vec(a[0],merge(slice(a,1,a.size()),b));
  }
}

std::vector<std::string>  sort_func(const std::vector<std::string> &items) {
  if (items.size() <= 1) { return items; }
  auto a = sort_func(slice(items,0,items.size()/2));
  auto b = sort_func(slice(items,items.size()/2,items.size()));
  return merge(a,b);
}

std::vector<std::string> quicksort(const std::vector<std::string> &items) { 
  if (items.size() <= 1) return items;

    std::string pivot = items[0];
    std::vector<std::string> left, right;

    left = partition_left(items, pivot);
    right = partition_right(items, pivot);

    std::vector<std::string> sorted_left = quicksort(left);
    std::vector<std::string> sorted_right = quicksort(right);
    std::vector<std::string> result;

    result = vec(combine_subvectors(sorted_left, sorted_right, pivot));

    return result;
}


std::vector<std::string> partition_left(std::vector<std::string> items, std::string pivot) {
  std::vector<std::string> left;
  for (int i = 1; i < items.size(); i++) {
        if (items[i] < pivot) {
            left.push_back(items[i]);
        }
    }
  return left;
}

std::vector<std::string> partition_right(std::vector<std::string> items, std::string pivot) {
  std::vector<std::string> right;
  for (int i = 1; i < items.size(); i++) {
        if (items[i] >= pivot)
            right.push_back(items[i]);
    }
    return right;
}


