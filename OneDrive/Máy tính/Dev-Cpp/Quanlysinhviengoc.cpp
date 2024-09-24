// #include <bits/stdc++.h>
#include<string>
#include<iomanip>
#include<fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;
//Khai bao cau truc du lieu SinhVien
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
//Ham nhap du lieu sinh vien vao mang
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
// Ham nhap so luong sinh vien vao mang
void nhapDanhSachSinhVien(SinhVien dsSV[], int k, int& n) {
    for (int i = 0; i < k; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        themSinhVien(dsSV, n);
    }
}

// Ham hien thi danh sach sinh vien
void hienThiDanhSachSinhVien(SinhVien dsSV[], int n) {
    cout << "Danh sach sinh vien:\n";
    cout << "+=============+=====================+===========+===============+========+\n";
    cout << "| MaSV        | TenSV               | LopSV     | NamSinh       | DiemTB |\n";
    cout << "+=============+=====================+===========+===============+========+\n";
    for (int i = 0; i < n; i++) {
        dsSV[i].diemTB =(float)(dsSV[i].diem1 + dsSV[i].diem2 + dsSV[i].diem3) / 3.0;
        cout << "| " << left << setw(12) << dsSV[i].maSV << "| ";
        cout << left << setw(20) << dsSV[i].tenSV << "| ";
        cout << left << setw(10) << dsSV[i].lopSV << "| ";
        cout << left << setw(14) << dsSV[i].namsinh << "| ";
        cout << fixed << setprecision(2) << left << setw(7) << dsSV[i].diemTB << "|\n";
    }
    cout << "+=============+=====================+===========+===============+========+\n";
}
// Ham xoa sinh vien theo ma, ten
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
// Ham sua thong tin sinh vien
void suaThongTinSinhVien(SinhVien dsSV[], int n, string maSV) {
    for (int i = 0; i < n; i++) {
        if (dsSV[i].maSV == maSV) {
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
            dsSV[i] = sv;
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ma so " << maSV << endl;
}
// Ham tim kiem sinh vien theo ma sinh vien
void timKiemSinhVien(SinhVien dsSV[], int n, string maSV, string tenSV) {
    int click;
    cout << "Nhap phuong thuc tim sinh vien:\n";
    cout << "+ 1.Tim kiem theo ma sinh vien. " << endl;
    cout << "+ 2.Tim kiem theo ten sinh vien. " << endl;
    cin >> click;
    bool timsv = false; // bi?n ki?m tra xem d� t�m th?y sinh vi�n hay chua
    if (click == 1) {
        cout << "Nhap ma sinh vien ban muon tim: " << endl;
        cin >> maSV;
        for (int i = 0; i < n; i++) {
            if (dsSV[i].maSV == maSV) {
                cout << "____________________________________\n" << endl;
                cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
                cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
                cout << "Diem mon HA1 : " << dsSV[i].diem1 << endl;
                cout << "Diem mon C++ : " << dsSV[i].diem2 << endl;
                cout << "Diem mon QTCSDL :" << dsSV[i].diem3 << endl;
                cout << "____________________________________\n";
                timsv = true;
                break; // Tim thay sinh vien len dung vong lap
            }
        }
        if (!timsv) {
            cout << "Khong tim thay ma sinh vien " << maSV << " trong danh sach" << endl;
        }
    }
    else if (click == 2) {
        cout << "Nhap ten sinh vien ban muon tim: " << endl;
        cin.ignore();
        getline(cin, tenSV);
        for (int i = 0; i < n; i++) {
            if (dsSV[i].tenSV == tenSV) {
                cout << "____________________________________\n" << endl;
                 cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
                 cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
                 cout << "Diem mon HA1 : " << dsSV[i].diem1 << endl;
                 cout << "Diem mon C++ : " << dsSV[i].diem2 << endl;
                 cout << "Diem mon QTCSDL :" << dsSV[i].diem3 << endl;
                 cout << "___________________________________\n";
                timsv = true;
                break; // Tim thay sinh vien len dung vong lap
            }
        }
        if (!timsv) {
            cout << "Khong tim thay ten sinh vien " << tenSV << " trong danh sach" << endl;
        }
    }
    else {
        cout << "Phuong thuc tim khong hop le" << endl;
    }
}
// Ham sap xep sinh vien theo diem trung binh giam dan
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
    hienThiDanhSachSinhVien(dsSV, n);
}
//Ham luu danh sach vao File text
void ghiFile(SinhVien dsSV[], int n, char fileName[]) {
    ofstream fout(fileName);
    if (!fout.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        fout << dsSV[i].maSV << " "
            << dsSV[i].tenSV << " "
            << dsSV[i].lopSV << " "
            << dsSV[i].namsinh << " "
            << dsSV[i].diem1 << " "
            << dsSV[i].diem2 << " "
            << dsSV[i].diem3 << " "
            << dsSV[i].diemTB << endl;
        if (fout.fail()) {
            cout << "Ghi du lieu that bai!\n";
            fout.close();
            return;
        }
    }
    fout.close();
}
//Ham xet nhung sinh vien phai hoc lai
void sinhvienHoclai(SinhVien dsSV[], int n) {
    for (int i = 0; i < n; i++) {
        if (dsSV[i].diem1 < 2 || dsSV[i].diem2 < 2 || dsSV[i].diem3 < 2 || dsSV[i].diemTB < 5) {
            // In th�ng tin sinh vi�n d? di?u ki?n dang k� thi
           
            cout << "Sinh vien " << dsSV[i].tenSV << " co diem TB " << " " << dsSV[i].diemTB << " phai hoc lai." << endl;
           
        }
        else cout << "Khong co sinh vien phai hoc lai" << endl;
    }
}
//Ham xet hoc luc cua sinh vien
void xetHocLuc(SinhVien dsSV[], int n, string maSV) {
    for (int i = 0; i < n; i++) {
      //  if (dsSV[i].maSV == maSV) {

           if (dsSV[i].diemTB >= 0 && dsSV[i].diemTB < 5) {
                cout << "Sinh vien " << dsSV[i].tenSV << " dat diem F\n";
            }
            else if (dsSV[i].diemTB >= 5 && dsSV[i].diemTB < 5.5) {
                cout << "Sinh vien " << dsSV[i].tenSV << " dat diem D+\n";
            }
            else if (dsSV[i].diemTB >= 5.5 && dsSV[i].diemTB < 6.5) {
                cout << "Sinh vien " << dsSV[i].tenSV << " dat diem C\n";
            }
            else if (dsSV[i].diemTB >= 6.5 && dsSV[i].diemTB < 7) {
                cout << "Sinh vien " << dsSV[i].tenSV << " dat diem C+\n";
            }
            else if (dsSV[i].diemTB >= 7 && dsSV[i].diemTB < 8) {
                cout << "Sinh vien " << dsSV[i].tenSV << " dat diem B\n";
            }
            else if (dsSV[i].diemTB >= 8 && dsSV[i].diemTB < 8.5) {
                cout << "Sinh vien " << dsSV[i].tenSV << " dat diem B+\n";
            }
            else if (dsSV[i].diemTB >= 8.5 && dsSV[i].diemTB <= 10) {
                cout << "Sinh vien " << dsSV[i].tenSV << " dat diem A\n";
         
            }
           
       else {
                cout << "Sinh vien " << dsSV[i].tenSV << " co diem khong hop le\n";
            }
        }
    }
//Ham thong ke 
void demSoSV(SinhVien dsSV[], int n, string tenSV) {
    int click;
    int dem = 0;
    cout << "Nhap phuong thuc tim sinh vien:\n";
    cout << "+ 1.Tim kiem va thong ke so sinh vien hoc lai. " << endl;
    cout << "+ 2.Tim kiem theo ten sinh vien. " << endl;
    cin >> click;

    if (click == 1) {
        for (int i = 0; i < n; i++) {
            if (dsSV[i].diemTB < 5) {
                dem++;
            }
        }
        cout << "So sinh vien hoc lai la: " << dem << endl;
        cout << "Phan tram so sinh vien hoc lai la: " << (float)dem / n * 100 << "%" << endl;
    }
    else if (click == 2) {
        cout << "Nhap ten sinh vien ban muon tim: " << endl;
        cin >> tenSV;
        for (int i = 0; i < n; i++) {
            if (dsSV[i].tenSV.find(tenSV) != string::npos) {
                dem++;
            }
        }
        cout << "So sinh vien co ten " << tenSV << " la: " << dem << endl;
        cout << "Phan tram so sinh vien co ten " << tenSV << " la: " << (float)dem / n * 100 << "%" << endl;
    }
}
//Ham lay danh sach tu  file
   void docDanhSachSinhVienTuFile(SinhVien dsSV[], int& n, char fileName[]) {
//Ham chinh xu ly du lieu   	
    ifstream file(fileName);
    if (file.is_open()) {
        stringstream ss;
        ss << file.rdbuf();
        file.close();

        string line;
        while (getline(ss, line) && n < 100) {
            stringstream lineStream(line);
            lineStream >> dsSV[n].maSV >> dsSV[n].tenSV >> dsSV[n].lopSV
                >> dsSV[n].namsinh >> dsSV[n].diem1 >> dsSV[n].diem2
                >> dsSV[n].diem3 >> dsSV[n].diemTB;
            n++;
        }    
    }
    hienThiDanhSachSinhVien(dsSV, n);
}
    int main() {
    int n = 0;
    string maSV, tenSV;
    int click;
    char fileName[] = "sinhvien.txt";
    int chon;
   // docDanhSachSinhVienTuFile(dsSV, n, fileName);
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
            timKiemSinhVien(dsSV, n, maSV, tenSV);

            break;
        case 4:
            cout << "Nhap ma sinh vien can sua thong tin: ";
            cin >> maSV;
            suaThongTinSinhVien(dsSV, n, maSV);

            break;
        case 5:
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSV;
            xoaSinhVien(dsSV, n, maSV);
            system("cls");
            break;
        case 6:

            sapXepDanhSachSinhVien(dsSV, n);
            for (int i = 0; i < n; i++) {
                cout << dsSV[i].tenSV << " - " << dsSV[i].diemTB << endl;
            }
		   break;
        case 7:
            if (n > 0) {
                cout << "--Ghi danh sach vao file thanh cong--\n";
                ghiFile(dsSV, n, fileName);
            }
            else cout << "Danh sach trong khong the luu file!!!" << endl;
            break;
        
        case 8:
            sinhvienHoclai(dsSV, n);
            break;
        case 9:
           
            xetHocLuc( dsSV, n,maSV);
            break;
        case 10:
            demSoSV(dsSV, n,tenSV);
            break;
        case 11:
            docDanhSachSinhVienTuFile(dsSV, n, fileName);
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
            break;
        }
    } while (chon != 0);

    return 0;
}

