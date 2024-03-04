#include <iostream>
#include <algorithm>//sorting headerfile 
using namespace std;

int main() {
    string inputString = "aefzmdbmctabcetfdz";
    // Sort the characters in the string in ascending order
    sort(inputString.begin(), inputString.end());

    // Rearrange the characters in pairs
    string rearrangedString;
    for (size_t i = 0; i < inputString.length(); i += 2) {
        rearrangedString += inputString[i];
        rearrangedString += inputString[i + 1];
    }

    // Display the result
    cout << "Original String: " << "aefzmdbmctabcetfdz" << endl;
    cout << "Rearranged String: " << rearrangedString <<endl;

    return 0;
}
