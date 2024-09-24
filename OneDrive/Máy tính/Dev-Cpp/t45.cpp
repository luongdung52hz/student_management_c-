#include<iostream>
#include<string>
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
int soSV = 0; // S? lu?ng sinh viên trong danh sách

// Ch?c nang thêm sinh viên
void themSinhVien() {
    if (soSV < 100) {
        SinhVien sv;
        cout << "Nhap ma sinh vien: ";
        cin >> sv.maSV;
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, sv.tenSV);
        cout << "Nhap lop cua sinh vien:"
            ;
        getline(cin, sv.lopSV);
        cout << "Nhap diem 1: ";
        cin >> sv.diem1;
        cout << "Nhap diem 1: ";
        cin >> sv.diem2;
        cout << "Nhap diem 1: ";
        cin >> sv.diem3;
        dsSV[soSV] = sv;
        soSV++;
    }
}
    // Hàm xóa sinh viên kh?i danh sách
    void xoaSinhVien(SinhVien dsSV[], int& n, string maSV) {
        for (int i = 0; i < n; i++) {
            if (dsSV[i].maSV == maSV) {
                for (int j = i; j < n - 1; j++) {
                    dsSV[j] = dsSV[j + 1];
                }
                n--;
                return;
            }
        }
        cout << "Khong tim thay sinh vien co ma so " << maSV << endl;
    }

    // Hàm s?a thông tin sinh viên trong danh sách
    void suaThongTinSinhVien(SinhVien dsSV[], int n, string maSV) {
        for (int i = 0; i < n; i++) {
            if (dsSV[i].maSV == maSV) {
                SinhVien sv;
                cout << "Nhap ten sinh vien: ";
                getline(cin, sv.tenSV);
                cout << "Nhap diem toan: ";
                cin >> sv.diem1;
                cout << "Nhap diem ly: ";
                cin >> sv.diem2;
                cout << "Nhap diem hoa: ";
                cin >> sv.diem3;
                dsSV[i] = sv;
                return;
            }
        }
        cout << "Khong tim thay sinh vien co ma so " << maSV << endl;
    }

    // Hàm tìm ki?m sinh viên theo mã s?
    void timKiemSinhVien(SinhVien dsSV[], int n, string maSV) {
        for (int i = 0; i < n; i++) {
            if (dsSV[i].maSV == maSV) {
                cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
                cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
                cout << "Diem toan: " << dsSV[i].diem1 << endl;
                cout << "Diem ly: " << dsSV[i].diem2 << endl;
                cout << "Diem hoa: " << dsSV[i].diem3 << endl;
                return;
            }
        }
        cout << "Khong tim thay sinh vien co ma so " << maSV << endl;
    }
    // Hàm hi?n th? danh sách sinh viên
    void hienThiDanhSachSinhVien(SinhVien dsSV[], int n) {
        cout << "Danh sach sinh vien:\n";
        cout << "MaSV TenSV LopSV NamSinh DiemTB\n";
        cout << "----------------------------------------------------\n";
        for (int i = 0; i < n; i++) {
            dsSV[i].diemTB = (dsSV[i].diem1 + dsSV[i].diem2 + dsSV[i].diem3) / 3;
            cout << dsSV[i].maSV << " ";
            cout << dsSV[i].tenSV << " ";
            cout << dsSV[i].lopSV << " ";
            cout << dsSV[i].namsinh << " ";
            cout << dsSV[i].diemTB << endl;
        }
        cout << "----------------------------------------------------\n";
    }
    // Hàm s?p x?p danh sách sinh viên theo di?m trung bình gi?m d?n
    void sapXepDanhSachSinhVien(SinhVien dsSV[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dsSV[i].diemTB < dsSV[j].diemTB) {
                    SinhVien temp = dsSV[i];
                    dsSV[i] = dsSV[j];
                    dsSV[j] = temp;
                }
            }
        }
        cout << "Danh sach sinh vien sau khi sap xep:\n";
        hienThiDanhSachSinhVien(dsSV, n);
    }
    int main() {
        int choice;
        string maSV;
        do {
            cout << "MENU" << endl;
            cout << "1. Them sinh vien" << endl;
            cout << "2. Xoa sinh vien" << endl;
            cout << "3. Sua thong tin sinh vien" << endl;
            cout << "4. Tim kiem sinh vien" << endl;
            cout << "5. Hien thi danh sach sinh vien" << endl;
            cout << "6. Sap xep danh sach sinh vien" << endl;
            cout << "0. Thoat" << endl;
            cout << "Nhap lua chon cua ban: ";
            cin >> choice;
            switch (choice) {
            case 1:
                themSinhVien();
                break;
            case 2:
                cout << "Nhap ma sinh vien muon xoa: ";
                cin >> maSV;
                xoaSinhVien(dsSV, soSV, maSV);
                break;
            case 3:
                cout << "Nhap ma sinh vien muon sua thong tin: ";
                cin >> maSV;
                suaThongTinSinhVien(dsSV, soSV, maSV);
                break;
            case 4:
                cout << "Nhap ma sinh vien muon tim kiem: ";
                cin >> maSV;
                timKiemSinhVien(dsSV, soSV, maSV);
                break;
            case 5:
                for (int i = 0; i < soSV; i++) {
                    cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
                    cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
                    cout << "Lop sinh vien: " << dsSV[i].lopSV << endl;
                    cout << "Nam sinh: " << dsSV[i].namsinh << endl;
                    cout << "Diem toan: " << dsSV[i].diem1 << endl;
                    cout << "Diem ly: " << dsSV[i].diem2 << endl;
                    cout << "Diem hoa: " << dsSV[i].diem3 << endl;
                    cout << "Diem trung binh: " << dsSV[i].diemTB << endl;
                }
                break;
            
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
            }
        } while (choice != 0);
        return 0;
    }
