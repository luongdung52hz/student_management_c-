#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
std::srand(std::time(0));
int secretNumber = std::rand() % 100 + 1;
int guess = 0;
int tries = 0;

cout<<"=======================" << endl;
cout << "====================" << endl;
cout << "Chào mung den voi tro choi doan so!" << endl;
cout<<"Ban co 6 lan doan so!" << endl;
cout << "Hay doan so tu 1 den 100:" << endl;

while (guess != secretNumber && tries < 7) {
    std::cout << "Nhap so cua ban:";
    std::cin >> guess;

    if (guess > secretNumber) {
        std::cout << "So ban doan qua lon!" << endl;
    } else if (guess < secretNumber) {
        std::cout << "So ban doan qua nho!" << endl;
    }

    tries++;
}

if (guess == secretNumber) {
    std::cout << "Chúc mung ban da doan dung sau " << tries << " lan thu!" << std::endl;
} else {
    std::cout << "Rat tiec ban da het lan thu. So ma ban can doan la: " << secretNumber << std::endl;
}

return 0;
}
