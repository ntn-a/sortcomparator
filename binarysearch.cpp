// Nhan Nguyen
// 02 October 2021
// CS-124-01
// Professor Chenhansa
// Source: Big C++: Late Objects, Cay S. Horstmann
#include "binarysearch.h"

int BinarySearch::search(std::vector<std::string> &v, 
  int from, int to, std::string value) const{
    if (from > to){
        return -1;
    }
    int mid = (from + to) / 2;
    if (v[mid] == value){
        return mid;
    }
    else if (v[mid] < value){
        return search(v, mid + 1, to, value);
    }
    else{
        return search(v, from, mid - 1, value);
    }
}