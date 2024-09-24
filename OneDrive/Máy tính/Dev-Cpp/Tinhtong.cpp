#include <iostream>
#include<iomanip>
using namespace std;

int main() {
    int n;
    float tong = 0;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            tong += 1.0 / i;
        } else {
            tong -= 1.0 / i;
        }
    }

    cout << "Tong cua bieu thuc la: " <<endl;
	cout << fixed << setprecision(3) <<tong - 1 << endl;

    return 0;
}

