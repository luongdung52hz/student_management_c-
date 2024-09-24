#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct SinhVien {
    string maSV;
    string HoTen;
    string GioiTinh;
    int NamSinh;
    float diem1, diem2, diem3;
    float diemTB;
    float thiTN;
};

vector<SinhVien> dsSinhVien;

void themSinhVien() {
    SinhVien sv;
    const int MAX_SV = 100; // s? lu?ng sinh viên t?i da
    SinhVien dsSv[MAX_SV];  // kh?i t?o m?ng sinh viên
    int n; 
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    // nh?p thông tin cho t?ng sinh viên
    for (int i = 0; i < n; i++) {
    cout << "Nhap thong tin cho sinh vien: " << endl;
    cout << "Ma SV: ";
    getline(cin, sv.maSV);
    cout << "Ho va ten: ";
    getline(cin, sv.HoTen);
    cout << "Gioi tinh: ";
    getline(cin, sv.GioiTinh);
    cout << "Nam sinh: ";
    cin >> sv.NamSinh;
    cout << "Diem toan: ";
    cin >> sv.diem1;
    cout << "Diem van: ";
    cin >> sv.diem2;
    cout << "Diem anh: ";
    cin >> sv.diem3;
    sv.diemTB = (sv.diem1 + sv.diem2 + sv.diem3) / 3;
    dsSinhVien.push_back(sv);
    cout << "Da them sinh vien thanh cong!" << endl;
}
}
void xuatSinhVien() {
    if (dsSinhVien.empty()) {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }
    cout << "Danh sach sinh vien: " << endl;
    cout << "+MaSV===HoTen===GioiTinh===NamSinh===DiemTB+" << endl;
    for (int i = 0; i < dsSinhVien.size(); i++) {
        SinhVien sv = dsSinhVien[i];
        cout << sv.maSV << "  "
            << sv.HoTen << "  "
            << sv.GioiTinh << "  "
            << sv.NamSinh << "      "
            << sv.diemTB << endl;
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
        switch (key) {
        case 1:
            themSinhVien();
        case 2:
        	xuatSinhVien();
        	break;
        	case 0:
cout << "Thoat chuong trinh" << endl;
return 0;
default:
cout << "Khong co chuc nang tuong ung!" << endl;
break;
}
} while (true); 
}
