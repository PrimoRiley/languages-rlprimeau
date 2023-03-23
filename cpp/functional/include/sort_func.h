#pragma once

#include <string>
#include <vector>

std::vector<std::string>  sort_func(const std::vector<std::string> &items);
std::vector<std::string> quicksort(const std::vector<std::string> &items);
std::vector<std::string> partition_right(std::vector<std::string> items, std::string pivot);
std::vector<std::string> partition_left(std::vector<std::string> items, std::string pivot);