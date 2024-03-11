#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxFrequency(vector<int>& nums) {
    map<int, int> freqMap;
    int maxFreq = 0;
    
    for (size_t i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        maxFreq = max(maxFreq, ++freqMap[num]);
    }
    
    int count = 0;
    for (map<int, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
        if (it->second == maxFreq) {
            count += it->second;
        }
    }
    
    return count;
}

int main() {
    vector<int> nums;
    int numElements;
    
    cout << "Enter the number of elements: ";
    cin >> numElements;
    
    cout << "Enter the elements: ";
    for (int i = 0; i < numElements; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    cout << "Output: " << maxFrequency(nums) << endl;

    return 0;
}