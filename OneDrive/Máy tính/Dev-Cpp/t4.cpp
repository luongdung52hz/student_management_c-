#include <string>
using namespace std;

int main() {
    string str = "Hello world!";
    string searchWord = "world";
    
    // tìm v? trí d?u tiên c?a searchWord trong str
    size_t pos = str.find(searchWord);
    
    if (pos != string::npos) { // n?u tìm th?y
        cout << "Tìm  " << searchWord << " tim " << pos <<endl;
    }
    else { // n?u không tìm th?y
        cout << "Không tìm th?y t? " << searchWord << endl;
    }

    return 0;
}




