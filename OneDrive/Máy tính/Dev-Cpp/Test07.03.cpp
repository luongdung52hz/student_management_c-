#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include <stdlib.h>
using namespace std;

struct SinhVien {
    string maSV;
    string tenSV;
    string lopSV;
    int namsinh;
    float diem1;
    float diem2;
    float diem3;
    float diemTB;
};

SinhVien dsSV[100];

void themSinhVien(SinhVien dsSV[], int& n) {
    SinhVien sv;
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sv.tenSV);
    cout << "Nhap lop cua sinh vien:";

    getline(cin, sv.lopSV);
    cout << "Nam sinh cua sinh vien:";
    cin >> sv.namsinh;
    cout << "Nhap diem mon HA1:";
    cin >> sv.diem1;
    cout << "Nhap diem mon C++:";
    cin >> sv.diem2;
    cout << "Nhap diem mon QTCSDL:";
    cin >> sv.diem3;

    dsSV[n] = sv;
    n++;
}
// Hàm nh?p s? lu?ng sinh viên vào m?ng
void nhapDanhSachSinhVien(SinhVien dsSV[], int k, int& n) {
    for (int i = 0; i < k; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        themSinhVien(dsSV, n);
    }
}

// Hàm hi?n th? danh sách sinh viên
void hienThiDanhSachSinhVien(SinhVien dsSV[], int n) {
    cout << "Danh sach sinh vien:\n";
    cout << "+=============+=====================+===========+===============+========+\n";
    cout << "| MaSV        | TenSV               | LopSV     | NamSinh       | DiemTB |\n";
    cout << "+=============+=====================+===========+===============+========+\n";
    for (int i = 0; i < n; i++) {
        dsSV[i].diemTB = (dsSV[i].diem1 + dsSV[i].diem2 + dsSV[i].diem3) / 3.0;
        cout << "| " << left << setw(12) << dsSV[i].maSV << "| ";
        cout << left << setw(20) << dsSV[i].tenSV << "| ";
        cout << left << setw(10) << dsSV[i].lopSV << "| ";
        cout << left << setw(14) << dsSV[i].namsinh << "| ";
        cout << fixed << setprecision(2) << left << setw(7) << dsSV[i].diemTB << "|\n";
    }
    cout << "+=============+=====================+===========+===============+========+\n";
}
void sapXepDanhSachSinhVien(SinhVien dsSV[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsSV[i].diemTB < dsSV[j].diemTB) {
                SinhVien temp = dsSV[i];
                dsSV[i] = dsSV[j];
                dsSV[j] = temp;
            }
        }
         hienThiDanhSachSinhVien( dsSV, n); 
    }
// Hàm xoá sinh viên theo mã sinh viên
/*void xoaSinhVien(SinhVien dsSV[], int& n, string maSV) {
    for (int i = 0; i < n; i++) {
        if (dsSV[i].maSV == maSV) {
            for (int j = i; j < n - 1; j++) {
                dsSV[j] = dsSV[j + 1];
            }
            n--;
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ma so " << maSV << endl;}*/
int main() {
    int n = 0;
    string maSV, tenSV;
    int click;
    char fileName[] = "sinhvien.txt";
    int chon;
    do {
        cout << "===================== MENU =====================" << endl;
        cout << "1. Nhap danh sach sinh vien" << endl;
        cout << "2. Hien thi danh sach sinh vien" << endl;
        cout << "3. Tim kiem sinh vien" << endl;
        cout << "4. Sap xep theo diem TB" << endl;
        cout << "0. Thoat" << endl;
        cout << "================================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        system("cls");
        switch (chon) {
        case 0:
            break;
        case 1:
            int k;
            cout << "Nhap so luong sinh vien: ";
            cin >> k;
            system("cls");
            nhapDanhSachSinhVien(dsSV, k, n);
            system("cls");
            break;
        case 2:
            hienThiDanhSachSinhVien(dsSV, n);
            break;
       
        case 3:

            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSV;
            xoaSinhVien(dsSV, n, maSV);
            system("cls");
            break;
     
        case 4:
        	sapXepDanhSachSinhVien(dsSV, n);
        	break;
        	
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
            break;
        }
    } while (chon != 0);

    return 0;
}}

