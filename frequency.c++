#include <iostream>
#include <vector>
#include <map>

int maxFrequency(std::vector<int>& nums) {
    std::map<int, int> freqMap;
    int maxFreq = 0;
    
    for (size_t i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        maxFreq = std::max(maxFreq, ++freqMap[num]);
    }
    
    int count = 0;
    for (std::map<int, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
        if (it->second == maxFreq) {
            count += it->second;
        }
    }
    
    return count;
}

int main() {
    std::vector<int> nums;
    int numElements;
    
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;
    
    std::cout << "Enter the elements: ";
    for (int i = 0; i < numElements; ++i) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }
    
    std::cout << "Output: " << maxFrequency(nums) << std::endl;

    return 0;
}