#include<iostream>
#include<math.h>
using namespace std;
int main(){
  int ds = 5000000;
  long long i,n;
  double tl = 0.02;
  cout<<"Nhap so nam can tinh: \n";cin>>n;
  for( i = 1 ; i <= n ; i++){
  	ds += ds * tl;
  	} 
cout<<"So dan la:"<< ds << endl; 
return 0 ;
}
