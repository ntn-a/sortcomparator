// Nhan Nguyen
// 11 September 2021
// CS-124-01
// Professor Chenhansa
#include "bubblesort.h"
/*
    Sorts a vector using Bubble Sort.
    @param Vector to be sorted, passed by reference.
    @param 2nd vector to be sorted, used in situation where 
    proper capitalization is required for output.
    @param size of vector.
*/

void BubbleSort::sort(std::vector<std::string> &vector1, std::vector<std::string> &vector2){
    count = 0; // Initialize Variables to be used.
    int i = 0;
    int num_swaps = 0;
    do{
        num_swaps = 0;
        for (int j = 1; j < vector1.size(); j++){
            if (vector1[j-1] > vector1[j]){ // As the loop goes through,
                swap(vector1[j-1], vector1[j]);// If the n-1 entry is greater than n,
                swap(vector2[j-1], vector2[j]);
                num_swaps++; // with n starting at 1, swap.
            } // num_swaps will allow for an exit if no swaps occurred.
            count++; // To be used for counting comparisons.
        }
        i++;
    }while(i < vector1.size() - 1 && num_swaps != 0); // do-while loop, with 
}       // exit condition for i going under size and swaps not occurring.

/*
    Swaps two string variables by reference, due to vector.
    @param first string to bet swapped.
    @param second string to be swapped.
*/
void BubbleSort::swap(std::string &a, std::string &b){
    std::string temp = a; // Store a in a temporary variable.
    a = b; // Set a equal to b.
    b = temp; // Set b equal to a.
}

/*
    Prints the amount of comparisons that occurred.
    @return count, data member that stores comparisons.
*/
int BubbleSort::printCount() const{
    return count;
}