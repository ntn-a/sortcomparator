// Nhan Nguyen
// 02 October 2021
// CS-124-01
// Professor Chenhansa
// Source: Big C++: Late Objects, Cay S. Horstmann
#include "linearsearch.h"

int LinearSearch::search(std::vector<std::string> v, std::string value) const{
    for (int i = 0; i < v.size(); i++){
        if (v[i] == value){
            return i;
        }
    }
    return -1;
}