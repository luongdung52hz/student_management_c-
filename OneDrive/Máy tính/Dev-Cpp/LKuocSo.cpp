#include<iostream>
using namespace std;
int LietKeUocSo(int n){
	for ( int i = 1 ; i <= n ; i++)
	if (n % i == 0)
	cout<< i <<" ";
}
 int main(){
 	int i , n;
 	cout << " Nhap gia tri can tim : ";
 	cin >> n;
 	LietKeUocSo(n);
 	return 0;
 }
