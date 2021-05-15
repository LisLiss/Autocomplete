#include "term.h"

term::term (const std::string nowNameTerm, const int nowWeight) : nameTerm(nowNameTerm), weight(nowWeight){};
term::term(const term &nowTerm)=default;
term::term()=default;

bool operator== (const term &first, const term &second){
    return first.nameTerm == second.nameTerm;
};
bool operator!= (const term &first, const term &second){
    return first.nameTerm != second.nameTerm;
};
bool operator>= (const term &first, const term &second){
    return first.nameTerm >= second.nameTerm;
};
bool operator<= (const term &first, const term &second){
    return first.nameTerm <= second.nameTerm;
};
bool operator> (const term &first, const term &second){
    return first.nameTerm > second.nameTerm;
};
bool operator< (const term &first, const term &second){
    return first.nameTerm < second.nameTerm;
};

term &term::operator= (const term &nowTerm)=default;

std::string term::to_string() const{
    return std::to_string(weight)+" "+nameTerm;
};

std::ostream &operator<< (std::ostream &out, const term &nowTerm){
    out << nowTerm.to_string();
    return out;
};

std::function <bool (const term &first, const term &second)> term::by_reverse_weight_order(){
    return [] (const term &first, const term &second){
        return first.weight > second.weight;
    };
};
std::function <bool (const term &first, const term &second)> term::by_prefix_order(int r){
    return [r] (const term &first, const term &second){
        std::string subFirst=first.nameTerm.substr(0, r);
        std::string subSecond=second.nameTerm.substr(0, r);
        return subFirst<subSecond;
    };
};
