#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main(){
istring s = "racecar";
bool isPalindrome = true;

for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - i - 1]) {
        isPalindrome = false;
        break;
    }
}

if (isPalindrome) {
    cout << "The string is a palindrome";
} else {
    cout << "The string is not a palindrome";
}
}
