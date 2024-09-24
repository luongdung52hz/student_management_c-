#include<iostream>
#include<math.h>
#include<string>
#include<vector>

using namespace std;

struct SinhVien {
    string maSV;
    string HoTen;
    string GioiTinh;
    int NamSinh;
    float diem1, diem2 ,diem3;
    float diemTB;
    float thiTN;
};



void themSinhVien() {
    SinhVien sv;
    const int MAX_SV = 100; // s? lu?ng sinh vi�n t?i da
    SinhVien dsSv[MAX_SV];  // kh?i t?o m?ng sinh vi�n
    int n; 
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    // Nhap thong tin cho tung SV
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho sinh vien thu " << i+1 << ":" << endl;
        cout << "Ho va ten: ";
        getline(cin, dsSv[i].HoTen);
        cout << "Nam sinh: ";
        cin >> dsSv[i].NamSinh;
        cout << "Diem toan: ";
        cin >> dsSv[i].diem1;
        cout << "Diem van: ";
        cin >> dsSv[i].diem2;
         cout << "Diem van: ";
        cin >> dsSv[i].diem3;
        cin.ignore();
    }
    cin.ignore();
    sv.diemTB = (sv.diem1 + sv.diem2 + sv.diem3 ) / 3;
    
    cout << "Da them sinh vien thanh cong!" << endl;
}

void xuatSinhVien() {
    if (dsSinhVien.empty()) {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }
    cout << "Danh sach sinh vien: " << endl;
    cout << "MaSV  HoTen  GioiTinh  NamSinh  DiemTB" << endl;
    for (int i = 0; i < dsSinhVien.size(); i++) {
        cout << dsSinhVien[i].maSV << "  "
             << dsSinhVien[i].HoTen << "  "
             << dsSinhVien[i].GioiTinh << "  "
             << dsSinhVien[i].NamSinh << "  "
             << dsSinhVien[i].diemTB << endl;
    }
}
int main() {
int key;
do {
cout << "Chon chuc nang: " << endl;
cout << "1. Them sinh vien" << endl;
cout << "2. Xuat danh sach sinh vien" << endl;
cout << "0. Thoat chuong trinh" << endl;

cin >> key;
cin.ignore();
switch(key) {
case 1:
themSinhVien();
break;
case 2:
xuatSinhVien();
break;
case 0:
cout << "Thoat chuong trinh" << endl;
return 0; // D?ng chuong tr�nh
default:
cout << "Khong co chuc nang tuong ung!" << endl;
break;
}
} while (true); // V�ng l?p v� h?n
}




