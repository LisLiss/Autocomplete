#pragma once
#include "term.h"
#include <vector>
#include <functional>
#include <algorithm>
struct binary_search_deluxe{
    binary_search_deluxe()=delete;

    static int first_index_of(std::vector <term> &a, term key, std::function <bool(const term &first, const term &second)> cmp);
    static int last_index_of(std::vector <term> &a, term key, std::function <bool(const term &first, const term &second)> cmp) ;
};
