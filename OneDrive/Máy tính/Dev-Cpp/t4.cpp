#include <string>
using namespace std;

int main() {
    string str = "Hello world!";
    string searchWord = "world";
    
    // t�m v? tr� d?u ti�n c?a searchWord trong str
    size_t pos = str.find(searchWord);
    
    if (pos != string::npos) { // n?u t�m th?y
        cout << "T�m  " << searchWord << " tim " << pos <<endl;
    }
    else { // n?u kh�ng t�m th?y
        cout << "Kh�ng t�m th?y t? " << searchWord << endl;
    }

    return 0;
}




