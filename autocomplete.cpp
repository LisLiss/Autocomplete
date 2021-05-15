#include "autocomplete.h"
#include <bits/stdc++.h>
autocomplete::autocomplete(std::vector <term> &a) : termArray(a){
    stable_sort(termArray.begin(), termArray.end());
};

std::vector<term> autocomplete::all_matches(const std::string &prefix){
    term prefixTerm=term(prefix, 0);
    int numBegin=binary_search_deluxe::first_index_of(termArray, prefixTerm, term::by_prefix_order(prefix.size()));
    int numEnd=binary_search_deluxe::last_index_of(termArray, prefixTerm, term::by_prefix_order(prefix.size()));
    std::vector<term> ans(numEnd-numBegin+1);
    std::copy(termArray.begin()+numBegin, termArray.begin()+numEnd+1, ans.begin());
    stable_sort(ans.begin(), ans.end(), term::by_reverse_weight_order());
    return ans;
};
int autocomplete::number_of_matches(const std::string &prefix){
    term prefixTerm=term(prefix, 0);
    int numBegin=binary_search_deluxe::first_index_of(termArray, prefixTerm, term::by_prefix_order(prefix.size()));
    int numEnd=binary_search_deluxe::last_index_of(termArray, prefixTerm, term::by_prefix_order(prefix.size()));
    return numEnd-numBegin+1;
};
