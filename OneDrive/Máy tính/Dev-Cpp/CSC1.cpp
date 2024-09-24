#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    cout << "Nhap vao n: ";
    cin >> n;

    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += pow(i,2);
    }

    cout << "Tong cac so binh phuong tu 1 den " << n << " la: " << s << endl;

    return 0;
}
