#pragma once
#include <functional>

class term{
public:
    term (const std::string nowNameTerm, const int nowWeight);
    term(const term &NowTerm);
    term();

    friend bool operator== (const term &first, const term &second);
    friend bool operator!= (const term &first, const term &second);
    friend bool operator>= (const term &first, const term &second);
    friend bool operator<= (const term &first, const term &second);
    friend bool operator> (const term &first, const term &second);
    friend bool operator< (const term &first, const term &second);

    term &operator= (const term &nowTerm);

    std::string to_string() const;

    friend std::ostream &operator<< (std::ostream &out, const term &nowTerm);

    static std::function <bool (const term &first, const term &second)> by_reverse_weight_order();
    static std::function <bool (const term &first, const term &second)> by_prefix_order(int r);

private:
    unsigned int weight;
    std::string nameTerm;
};
