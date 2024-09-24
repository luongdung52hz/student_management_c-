#include<bits/stdc++.h>
using namespace std;
void odd (int);
void even (int);
int main() {
int i = 10;
cout << odd(i);
return 0;
}
void odd (int a) {
if ((a % 2) != 0) cout << “Le”;
else even(a);
}
void even (int a) {
if ((a % 2) = 0) cout << “Chan”;
else odd(a);
}
