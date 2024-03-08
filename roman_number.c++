#include <iostream>
#include <string>

using namespace std;

string toRoman(int num) {
    string roman =" ";
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            roman += symbols[i];
            num -= values[i];
        }
    }
    return roman;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Roman numeral: " << toRoman(num) << endl;
    return 0;
}