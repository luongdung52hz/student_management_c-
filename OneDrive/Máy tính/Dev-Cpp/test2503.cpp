#include<iostream>
using namespace std;
int main(){
	long long n,x ;
	long long A[n];
	int dem1=0,dem2=0;
	cout << "Nhap so luong n:\n";
	cin>>n;
	cout<<"Nhap vao mang:\n";
	for( int i = 0;i <n; i++){
		
		cin>>A[i];
	}
	cout<<"Nhap so x ban muon tim:\n";
	cin>>x;
	for ( int i = 0 ; i < n; i++){
		if( A[i] < x){
			dem1++;}
	
		else if( A[i] > x){
			dem2++;
		
		}
	}	cout<<dem1<<" "<<dem2;
		
	
	
	return 0;
}
