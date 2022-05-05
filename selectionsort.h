// Nhan Nguyen
// 11 September 2021
// CS-124-01
// Professor Chenhansa
#include <string> // Libraries for sort.
#include <vector>
class SelectionSort{
public: // Sort function and print for Selection Sort and comparisons.
    void sort(std::vector<std::string> &v1, std::vector<std::string> &v2);
    int printCount() const;
private: // Min_poision and swap are private because the functions should only
    int min_position(std::vector<std::string> v, int from, int to); // be used
    void swap(std::string &a, std::string &b); //  by the sort function.
    int count; // Comparisons.
};