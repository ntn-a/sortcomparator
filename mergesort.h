// Nhan Nguyen
// 02 October 2021
// CS-124-01
// Professor Chenhansa
#include <string>
#include <vector>

class MergeSort{
public:
    void sort(std::vector<std::string> &v1, 
      std::vector<std::string> &v2, int from, int to);
    int printCount() const;
private:
    void merge(std::vector<std::string> &v1, std::vector<std::string> &v2, 
        int from, int mid, int to);
    int count;
};