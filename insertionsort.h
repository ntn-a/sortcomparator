// Nhan Nguyen
// 02 October 2021
// CS-124-01
// Professor Chenhansa
// Source: Big C++: Late Objects, Cay S. Horstmann
#include <string>
#include <vector>

class InsertionSort{
public:
    void sort(std::vector<std::string> &v1, 
      std::vector<std::string> &v2);
    int printCount() const;
private:
    int count;
};