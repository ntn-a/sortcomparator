// Nhan Nguyen
// 02 October 2021
// CS-124-01
// Professor Chenhansa
#include <string>
#include <vector>

class QuickSort{
public:
    void sort(std::vector<std::string> &v1, 
      std::vector<std::string> &v2, int from, int to);
    int printCount() const;
private:
    int partition(std::vector<std::string> &v1, 
      std::vector<std::string> &v2, int from, int to);
    void swap(std::string &a, std::string &b);
    int count;
};