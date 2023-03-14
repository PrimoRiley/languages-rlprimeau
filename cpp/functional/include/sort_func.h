#pragma once

#include <string>
#include <vector>

std::vector<std::string>  sort_func(const std::vector<std::string> &items);
std::vector<std::string> quicksort(const std::vector<std::string> &items);
void partition(std::vector<std::string> items, std::vector<std::string> &right, std::vector<std::string> &left, std::string &pivot);