#include <iostream>
using namespace std;
int main() {
    int i,n ;
    int g = 1;
    cout << "Nhap so nguyen n : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    g *= i;
    cout<< "Giai thua cua n la:" << g <<endl;
    return 0 ;}




