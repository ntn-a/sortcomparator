// Nhan Nguyen
// 02 October 2021
// CS-124-01
// Professor Chenhansa
// Source: Big C++: Late Objects, Cay S. Horstmann
#include "insertionsort.h"

void InsertionSort::sort(std::vector<std::string> &v1, 
  std::vector<std::string> &v2){
    for (int i = 1; i < v1.size(); i++){
        std::string next = v1[i];
        std::string next2 = v2[i];
        int j = i;
        while (j > 0 && v1[j - 1] > next){
            v1[j] = v1[j - 1];
            v2[j] = v2[j - 1];
            j--;
        }
        v1[j] = next;
        v2[j] = next2;
    }
}

int InsertionSort::printCount() const{
    return count;
}