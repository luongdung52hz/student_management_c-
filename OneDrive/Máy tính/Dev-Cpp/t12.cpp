#include<iostream>
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
	int x;
    float y;
    Color(3);
    cout<<"======================+======================+======================\n";
    cout<<"=                     +                      +                     =\n";
    cout<<"=       HELLO         +                      +                     =\n";
	return 0 ;
}
