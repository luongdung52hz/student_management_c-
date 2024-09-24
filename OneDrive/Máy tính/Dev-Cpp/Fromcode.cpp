#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//chuan hoa
string chuanhoa(string n) {
    
    for (int i = 0; i < n.length(); i++) {
        if (i == 0 || n[i-1] == ' ') {
            n[i] = toupper(n[i]);
    } else {
            n[i] = tolower(n[i]);
        }
    }

    return n;
}

//Ham dem ky tu so
int demso(string n)
{
	int sodem = 0;
	for (int i = 0; i < n.length(); i++) 
	{
        if (isdigit(n[i])) {
            sodem++;
        }
    }  
    cout << "So ky tu so trong xau: " << sodem << endl;
    return sodem;
}

//Ham dem ky tu chu
int demchu(string n)
{
	int sochu = 0;
	for (int i = 0; i < n.length(); i++) 
	{
        if (isalpha(n[i])) {
            sochu++;
        }
    } 
	cout << "So ky tu chu cai trong xau: " << sochu << endl; 
    return sochu;
}

//Nhap
void nhap(string &n)
{
	cout << "Nhap xau ky tu (>= 20 ky tu): ";
    getline(cin, n);
	while (n.length() < 20) {
        cout << "Khong du 20 ky tu. Nhap lai: ";
        getline(cin, n);
    }
    n = chuanhoa(n);
    cout << "Xau ky tu nhap vao: " << n << endl;
}

void timkytu(string &n)
{
    char x;
    int dem = 0;
    cout << "Nhap ky tu can dem: ";
    cin >> x;
    // duy?t t?ng kí t? trong xâu và d?m s? l?n xu?t hi?n c?a kí t? c?n d?m
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == x) {
            dem++;
        }  
	}
	cout << "So lan xuat hien cua ky tu " << x << " trong xau la: " << dem << endl;		
}

int main() {
    string n;
	int luachon;
	
	do {
		cout << "===================== MENU =====================" << endl;
        cout << "1. Nhap danh sach sinh vien" << endl;
        cout << "2. Hien thi danh sach sinh vien" << endl;
        cout << "3. Tim kiem sinh vien" << endl;
        cout << "4. Sua thong tin sinh vien" << endl;
        cout << "5. Xoa sinh vien" << endl;
        cout << "6. Danh sach sinh vien theo diem TB giam dan" << endl;
        cout << "7. Ghi vao file" << endl;
        cout << "8. In ra nhung sinh vien hoc lai" << endl;
        cout << "9. In ra hoc luc cua sinh vien" << endl;
        cout << "10. Thong ke danh sach" << endl;
        cout << "11. Doc file co san" << endl;
        cout << "0. Thoat" << endl;
        cout << "================================================" << endl;
        cout << "Nhap lua chon cua ban: ";
		cin >> luachon;
		cin.ignore();
		switch (luachon) {
			case 1:
			{
				nhap(n);
				break;
			}
			case 2: 
			{
				n = chuanhoa(n);
				cout << "Xau sau khi chuan hoa: " << n << endl;
			 	break;
			}
			case 3:
			{
				demso(n);
				demchu(n);
				break;
			}
			case 4:
			{
				timkytu(n);
				break;
			}	
			case 0:
			{
				return;
			}
			default:
			{
				cout << "Nhap tu 1 den 3" << endl;
				break;
			}
		}
	} while (luachon != 3); // Ch?y vòng l?p cho d?n khi ngu?i dùng ch?n 3 d? thoát

    return 0;
}


