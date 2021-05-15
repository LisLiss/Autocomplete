#include <iostream>
#include "autocomplete.h"

void makeTest(){
    std::cout<<"MAKING TERMS"<<std::endl;
    term makeFirst = term("animals", 20);
    term makeSecond = term (makeFirst);
    term makeThird = makeFirst;
    std::cout<<"If this three terms don't equals, it's bad"<<std::endl;
    std::cout<<makeFirst<<std::endl<<makeSecond<<std::endl<<makeThird<<std::endl;
    std::cout<<"================================================"<<std::endl;
}

std::vector <term> animals{
    {"ant", 1},
    {"bat", 2},
    {"cat", 5},
    {"antelope", 200},
    {"bear", 300},
    {"monkey", 4},
    {"beaver", 20},
    {"caterpillar", 1},
    {"moth", 0},
    {"badger", 10},
    {"mouse", 3},
};

void compareTest(){
    std::cout<<"COMPARING"<<std::endl;
    std::cout<<"ant == ant "<<(animals[0]==animals[0] ? "true" : "false")<<std::endl;
    std::cout<<"ant != moth "<<(animals[0]!=animals[8] ? "true" : "false")<<std::endl;
    std::cout<<"ant >= badger "<<(animals[0]>=animals[9] ? "true" : "false")<<std::endl;
    std::cout<<"antelope <= bear "<<(animals[3]<=animals[4] ? "true" : "false")<<std::endl;
    std::cout<<"beaver > cat "<<(animals[6]>animals[2] ? "true" : "false")<<std::endl;
    std::cout<<"monkey < caterpillar "<<(animals[5]<animals[7] ? "true" : "false")<<std::endl;
    std::cout<<"================================================"<<std::endl;
}

void stringTest(){
    std::cout<<"TO STRING"<<std::endl;
    std::cout<<"This is term (badger, 10) in string: "<<animals[9].to_string()<<std::endl;
    std::cout<<"================================================"<<std::endl;
}

void printArray(std::vector <term> &a){
    for (int i=0; i<a.size(); i++) std::cout<<a[i]<<std::endl;
}
void sortTest(){
    std::cout<<"SORTING"<<std::endl;
    std::cout<<std::endl<<"Not sorted:"<<std::endl;
    printArray(animals);
    std::cout<<std::endl<<"By reverse weight order:"<<std::endl;
    std::vector <term> weightSort=animals;
    stable_sort(weightSort.begin(), weightSort.end(), term::by_reverse_weight_order());
    printArray(weightSort);
    std::cout<<std::endl<<"By size 3 prefix order:"<<std::endl;
    std::vector <term> prefSort=animals;
    stable_sort(prefSort.begin(), prefSort.end(), term::by_prefix_order(3));
    printArray(prefSort);
    std::cout<<"================================================"<<std::endl;
}

void autocompleteTest(){
    autocomplete dicAnimals(animals);
    std::cout<<"AUTOCOMPLETE"<<std::endl;
    std::cout<<"Search in array:"<<std::endl;
    stable_sort(animals.begin(), animals.end());
    printArray(animals);
    std::cout<<std::endl<<"Name animals with prefix \"ante\""<<std::endl;
    std::cout<<dicAnimals.number_of_matches("ante")<<" elements:"<<std::endl;
    std::vector <term> ans=dicAnimals.all_matches("ante");
    printArray(ans);
    std::cout<<std::endl<<"Name animals with prefix \"ant\""<<std::endl;
    std::cout<<dicAnimals.number_of_matches("ant")<<" elements:"<<std::endl;
    ans=dicAnimals.all_matches("ant");
    printArray(ans);
    std::cout<<std::endl<<"Name animals with prefix \"mo\""<<std::endl;
    std::cout<<dicAnimals.number_of_matches("mo")<<" elements:"<<std::endl;
    ans=dicAnimals.all_matches("mo");
    printArray(ans);
    std::cout<<std::endl<<"Name animals with prefix \"dog\""<<std::endl;
    std::cout<<dicAnimals.number_of_matches("dog")<<" element:"<<std::endl;
    ans=dicAnimals.all_matches("dog");
    printArray(ans);
    std::cout<<std::endl<<"================================================"<<std::endl;
}

int main() {
    makeTest();
    compareTest();
    stringTest();
    sortTest();
    autocompleteTest();
    return 0;
}
