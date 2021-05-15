#pragma once
#include "binary_search_deluxe.h"
#include <vector>
struct autocomplete{
    explicit autocomplete(std::vector <term> &a);

    std::vector<term> all_matches(const std::string &prefix);
    unsigned int number_of_matches(const std::string &prefix);

private:
    std::vector <term> termArray;
};
