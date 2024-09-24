#include<iostream>
#include<math.h>
#include<iomanip>
#include<Windows.h>
using namespace std;
int sum(int a,int b = 20) {
   int result;
   result = a + b;
   return (result);
}
int main() {
   int a = 100, b= 200, result;
   result = sum(a);
   cout << result << endl;
}

