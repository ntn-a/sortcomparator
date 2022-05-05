// Nhan Nguyen
// 11 September 2021
// CS-124-01
// Professor Chenhansa
#include "selectionsort.h"
/*
    Finds the smallest value in a vector.
    @param string vector that'll be used to find min_pos
    @param int for beginning of range.
    @param int for end of range.
    @return min_pos.
*/
int SelectionSort::min_position(std::vector<std::string> v, int from, int to){
    int min_pos = from; // Variable to store first value of range.
    for (int i = from + 1; i <= to; i++){
        if (v[i] < v[min_pos]){ // If smaller value is found through range,
            min_pos = i; // Make min_pos into i.
        }
    }
    return min_pos; // Return the minimum position.
}

/*
    Sorts a vector using Selection Sort
    @param string vector to be sorted.
    @param size of vector.
*/
void SelectionSort::sort(std::vector<std::string> &v1, std::vector<std::string> &v2){    
    for (int i = 0; i < v1.size() - 1; i++){ // For loop to go through array/
        int min_pos = min_position(v1, i, v1.size() - 1);
        swap(v1[i], v1[min_pos]); // After min_pos is found, swap values.
        swap(v2[i], v2[min_pos]);
    }
}

/*
    Swaps two strings by reference.
    @param first string to be swapped.
    @param second string to be swapped.
*/
void SelectionSort::swap(std::string &a, std::string &b){
    std::string temp = a;
    a = b;
    b = temp;
}

/*
    Output count of comparisons
    @return count of comparison.
*/
int SelectionSort::printCount() const{
    return count;
}