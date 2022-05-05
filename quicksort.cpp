// Nhan Nguyen
// 02 October 2021
// CS-124-01
// Professor Chenhansa
// Source: Big C++: Late Objects, Cay S. Horstmann
#include "quicksort.h"

void QuickSort::sort(std::vector<std::string> &v1, 
  std::vector<std::string> &v2, int from, int to){
    if (!(from >= to)){
        int p = partition(v1, v2, from, to);
        sort(v1, v2, from, p);
        sort(v1, v2, p + 1, to);
    }
}

int QuickSort::partition(std::vector<std::string> &v1, 
  std::vector<std::string> &v2, int from, int to){
    std::string pivot = v1[from];
    int i = from - 1;
    int j = to + 1;
    while (i < j){
        i++; while (v1[i] < pivot){ i++; }
        j--; while (v1[j] > pivot){ j--; }
        if (i < j){ swap(v1[i], v1[j]); swap(v2[i], v2[j]); }
    }
    return j;
}

void QuickSort::swap(std::string &a, std::string &b){
    std::string temp = a;
    a = b;
    b = temp;
}