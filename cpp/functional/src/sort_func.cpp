#include "../include/sort_proc.h"
#include <algorithm>
#include <string>

//implementation of merge is procedural
std::vector<std::string> merge(const std::vector<std::string> &first, const std::vector<std::string> &second){
    auto i = first.begin();
    auto j = second.begin();

    std::vector<std::string> ans;
    // to do
    if(j == second.end())
        return first;
    if(i == first.end())
        return second;

    ans.insert(ans.end(), i, first.end());  
    ans.insert(second.end(), j, second.end());

    //stable sorts: for duplicate values the original order is preserved
    while(i != first.end() && j != second.end()){
        if(*j < *i){
            ans.push_back(*j);
            j++;
        }else{
            ans.push_back(*i);
            i++;
        }
    }

    


  

}

// functional
std::vector<std::string> sort_func(const std::vector<std::string>::const_iterator begin, const std::vector<std::string>::const_iterator end)
{
    // const interators are nice because they garuntee you wont modify the vector
    size_t size = end - begin;
    if(size <= 1){
        return std::vector<std::string>(begin,end);
    }

    auto firstBegin = begin;
    auto firstEnd = firstBegin + size/2;
    auto secondBegin = firstEnd;
    auto secondEnd = end;

    auto firstSorted = sort_func(firstBegin, firstEnd);
    auto secondSorted = sort_func(secondBegin, secondEnd);

    return merge(firstSorted, secondSorted);
}

//functional
std::vector<std::string> sort_func(const std::vector<std::string> &items){
   return sort_func(items.begin(), items.end());
}

