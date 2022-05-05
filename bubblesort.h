// Nhan Nguyen
// 11 September 2021
// CS-124-01
// Professor Chenhansa
#include <string> // Libraries to be included in class.
#include <vector>
class BubbleSort{
public: // Function to conduct Bubble Sort and return count of comparisons.
    void sort(std::vector<std::string> &vector1, std::vector<std::string> &vector2);
    int printCount() const;
private: // Swap function in private because it should really only
    void swap(std::string &a, std::string &b); // be used by function.
    int count; // Keeps track of comparisons.
};