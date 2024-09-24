#include<iostream>
using namespace std;

long x (long a) { 
if (a > 1) return (a * x(a - 1)); 
else return (1); 
} 
int main() { 
cout << x(5); 
return 0; 
}



