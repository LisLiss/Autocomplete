#include "binary_search_deluxe.h"
int binary_search_deluxe::first_index_of(std::vector <term> &a, term key, std::function <bool(const term &first, const term &second)> cmp){
    std::vector<term>::iterator findKey=lower_bound(a.begin(), a.end(), key, cmp);
    return findKey-a.begin();
}

int binary_search_deluxe::last_index_of(std::vector <term> &a, term key, std::function <bool(const term &first, const term &second)> cmp){
    std::vector<term>::iterator findKey=upper_bound(a.begin(), a.end(), key, cmp);
    return findKey-a.begin()-1;
}
