// Nhan Nguyen
// 02 October 2021
// CS-124-01
// Professor Chenhansa
// Source: Big C++: Late Objects, Cay S. Horstmann
#include "mergesort.h"

void MergeSort::merge(std::vector<std::string> &v1, 
  std::vector<std::string> &v2, int from, int mid, int to){
    int n = to - from + 1;
    std::string *b1 = new std::string[n];
    std::string *b2 = new std::string[n];
    int i1 = from;
    int i2 = mid + 1;
    int j = 0;

    while (i1 <= mid && i2 <= to){
        if (v1[i1] < v1[i2]){
            b1[j] = v1[i1];
            b2[j] = v2[i1];
            i1++;
        }
        else{
            b1[j] = v1[i2];
            b2[j] = v2[i2];
            i2++;
        }
        j++;
    }

    while (i1 <= mid){
        b1[j] = v1[i1];
        b2[j] = v2[i1];
        i1++;
        j++;
    }

    while (i2 <= to){
        b1[j] = v1[i2];
        b2[j] = v2[i2];
        i2++;
        j++;
    }

    for (j = 0; j < n; j++){
        v1[from + j] = b1[j];
        v2[from + j] = b2[j];
    }

    delete []b1;
    delete []b2;
}

void MergeSort::sort(std::vector<std::string> &v1, 
  std::vector<std::string> &v2, int from, int to){
    if (from != to){
        int mid = (from + to) / 2;
        sort(v1, v2, from, mid);
        sort(v1, v2, mid + 1, to);
        merge(v1, v2, from, mid, to);
    }
}

int MergeSort::printCount() const{
    return count;
}