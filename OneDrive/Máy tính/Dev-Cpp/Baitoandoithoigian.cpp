#include<iostream>
#include<math.h>
#include<iomanip>
#include<Windows.h>
using namespace std;
void Color(int color)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {

        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }

}
 int main(){
 	int g;
 	float h,p,g2;
 	cout<<"Nhap so giay ban muon doi\n";cin>>g;
 	h = g/3600;
 	g %= 3600;
 	p = g/60;
 	g2 = g % 60;
 	Color(2);
 	cout<<"So gio la:"<<h<<endl;
 	Color(5);
 	cout<<"So phut la:"<<p<<endl;
 	Color(3);
 	cout<<"So giay la:"<<g2<<endl; 
 	
 	
 	
 	
 	
 	
 	
 	return 0 ;
 }
