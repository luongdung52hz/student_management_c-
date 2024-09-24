#include<bits/stdc++.h>

using namespace std;

struct SinhVien {
    string maSV;
    string tenSV;
    string lopSV;
    string gioitinhSV;
    string quequanSV;
    string nghanhSV;
    int namsinh;
    float diem1 ;
    float diem2 ;
    float diem3 ;
    float diemTB ;
};

SinhVien dsSV[100];
void hoclucSV(SinhVien dsSV[], int n);
//Ham nhap thong tin sinh vien 
void themSinhVien(SinhVien dsSV[], int& n) {
    SinhVien sv;
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sv.tenSV);
    cout << "Nhap gioi tinh cua sinh vien: ";
   
    getline(cin, sv.gioitinhSV);
    cout << "Nhap que quan cua sinh vien: ";
    
    getline(cin, sv.quequanSV);
    
    cout << "Nhap nghanh hoc cua  sinh vien: ";
    
    getline(cin, sv.nghanhSV);
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
// Ham nhap so luong sinh vien
void nhapDanhSachSinhVien(SinhVien dsSV[], int k, int& n) {
    for (int i = 0; i < k; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        themSinhVien(dsSV, n);
    }
}

//Ham hien thi danh sach
void hienThiDanhSachSinhVien(SinhVien dsSV[], int n) {
    cout << "Danh sach sinh vien:\n";
    cout << "+=============+=====================+===========+===============+============+===========+==============+========+\n";
    cout << "|     MaSV    | TenSV               |  LopSV    |    NghanhSV   | GioiTinhSV | NamSinh   |  QueQuanSV   | DiemTB |\n";
    cout << "+=============+=====================+===========+===============+============+===========+==============+========+\n";
    for (int i = 0; i < n; i++) {
        dsSV[i].diemTB = (dsSV[i].diem1 + dsSV[i].diem2 + dsSV[i].diem3) / 3.0;
        cout << "| " << left << setw(12) << dsSV[i].maSV << "| ";
        cout << left << setw(20) << dsSV[i].tenSV << "| ";
        cout << left << setw(10) << dsSV[i].lopSV << "| ";
        cout << left << setw(14) << dsSV[i].nghanhSV << "| ";
        cout << left << setw(11) << dsSV[i].gioitinhSV << "| ";
        cout << left << setw(10) << dsSV[i].namsinh << "| ";
        cout << left << setw(13) << dsSV[i].quequanSV << "| ";
        cout << fixed << setprecision(2) << left << setw(7) << dsSV[i].diemTB << "|\n";
    }
    cout << "+=============+=====================+===========+===============+============+===========+==============+========+\n";
}

// Ham xoa thong tin
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

// Ham sua thong tin
void suaThongTinSinhVien(SinhVien dsSV[], int n, string maSV) {
    for (int i = 0; i < n; i++) {
        if (dsSV[i].maSV == maSV) {
            SinhVien sv;
           cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sv.tenSV);
    cout << "Nhap gioi tinh cua sinh vien: ";
   
    getline(cin, sv.gioitinhSV);
    cout << "Nhap que quan cua sinh vien: ";
    
    getline(cin, sv.quequanSV);
    
    cout << "Nhap nghanh hoc cua  sinh vien: ";
    
    getline(cin, sv.nghanhSV);
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

// Ham tim kiem
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
                cout << "Tuoi cua sinh vien: " <<2023 - dsSV[i].namsinh << endl;
                cout << "Dia chi cua sinh vien: " << dsSV[i].quequanSV << endl;
                cout << "Diem trung binh cua sinh vien:" << dsSV[i].diemTB << endl;
                cout << "____________________________________\n";
                timsv = true;
                break; // t�m th?y sinh vi�n r?i n�n d?ng v�ng l?p
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
                cout << "Tuoi cua sinh vien  : " << 2023 - dsSV[i].namsinh << endl;
                cout << "Dia chi cua sinh vien : " << dsSV[i].quequanSV << endl;
                cout << "Diem trung binh cua sinh vien :" << dsSV[i].diemTB << endl;
                cout << "____________________________________\n";
                timsv = true;
                break; // t�m th?y sinh vi�n r?i n�n d?ng v�ng l?p
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

// Ham sap xep
void sapXepDanhSachSinhVien(SinhVien dsSV[], int n) {
    int click;
    cout << "Nhap phuong thuc tim sinh vien:\n";
    cout << "+ 1.Sap xep theo ten sinh vien. " << endl;
    cout << "+ 2.Sap xep theo ma sinh vien. " << endl;
    cout << "+ 3.Sap xep theo diem trung binh. " << endl;
    cin >> click;

    if (click == 1) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dsSV[i].tenSV > dsSV[j].tenSV) {
                    SinhVien temp = dsSV[i];
                    dsSV[i] = dsSV[j];
                    dsSV[j] = temp;
                }
            }
        }
        hienThiDanhSachSinhVien(dsSV,n);
    }
    else if (click == 2) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dsSV[i].maSV > dsSV[j].maSV) {
                    SinhVien temp = dsSV[i];
                    dsSV[i] = dsSV[j];
                    dsSV[j] = temp;
                }
            }
        }
        hienThiDanhSachSinhVien(dsSV,n);
    }
    else if (click == 3) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dsSV[i].diemTB < dsSV[j].diemTB) {
                    SinhVien temp = dsSV[i];
                    dsSV[i] = dsSV[j];
                    dsSV[j] = temp;
                }
            }
        }
       hoclucSV(dsSV, n);
    }
    else {
        cout << "Lua chon khong hop le." << endl;
        return;
    }
  
}

//Ham luu danh sach sinh vien
void ghiFile(SinhVien dsSV[], int n, char fileName[]) {
    ofstream fout(fileName);
    if (!fout.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        fout << dsSV[i].maSV << "-"
            << dsSV[i].tenSV << "-"
            << dsSV[i].lopSV << "-"
            << dsSV[i].nghanhSV << "-"
            << dsSV[i].gioitinhSV << "-"
            << dsSV[i].namsinh << "-"
            << dsSV[i].diemTB << " "
            << dsSV[i].diem1 << " "
            << dsSV[i].diem2 << " "
            << dsSV[i].diem3 << " "       
        << dsSV[i].quequanSV << endl;
        if (fout.fail()) {
            cout << "Ghi du lieu that bai!\n";
            fout.close();
            return;
        }
    }
    fout.close();
}

//Ham xet hoc luc cua sinh vien
void hoclucSV(SinhVien dsSV[], int n) {
    string maSV;

    cout << "Danh sach sinh vien:\n";
    cout << "+=============+=========================+=========+===============+=========+=========+=========+========+==========+===========+\n";
    cout << "|     MaSV    | TenSV                   |  LopSV  |    NghanhSV   | Diem M1 | Diem M2 | diem M3 | DiemTB | Ket qua  | Xep loai  |\n";
    cout << "+=============+=========================+=========+===============+=========+=========+=========+========+==========+===========+\n";
    for (int i = 0; i < n; i++) {

        cout << "| " << left << setw(12) << dsSV[i].maSV << "| ";
        cout << left << setw(24) << dsSV[i].tenSV << "| ";
        cout << left << setw(8) << dsSV[i].lopSV << "| ";
        cout << left << setw(14) << dsSV[i].nghanhSV << "| ";
        if (dsSV[i].diem1 <= 2) {
            cout << left << setw(7) << fixed << setprecision(1) << dsSV[i].diem1 <<"*" << "| ";
        }
        else {
            cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diem1 << "| ";
        }
        if (dsSV[i].diem2 <= 2) {
            cout << left << setw(7) << fixed << setprecision(1) << dsSV[i].diem2 <<"*"<< "| ";
        }
        else {
            cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diem2 << "| ";
        }
        if (dsSV[i].diem3 <= 2) {
            cout << left << setw(7) << fixed << setprecision(1) << dsSV[i].diem3 <<"*"<< "| ";
        }
        else {
            cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diem3 << "| ";
        }

        cout << left << setw(7) << fixed << setprecision(1) << dsSV[i].diemTB << "| ";
        if (dsSV[i].diem1 < 2 || dsSV[i].diem2 < 2 || dsSV[i].diem3 < 2 || dsSV[i].diemTB < 5) {
            cout << left << setw(9) << "Rot" << "| ";
            cout << left << setw(10) << "Kem" << "|" << endl;
        }

        else {
            cout << left << setw(9) << "Do" << "| ";
            if (dsSV[i].diemTB >= 8.5) {
                cout << left << setw(10) << "Gioi" << "|" << endl;
            }
            else if (dsSV[i].diemTB >= 7) {
                cout << left << setw(10) << "Kha" << "|" << endl;
            }
            else if (dsSV[i].diemTB >= 5.5) {
                cout << left << setw(9) << "Trung binh" << "|" << endl;
            }
            else {
                cout << left << setw(10) << "Yeu" << "|" << endl;

            }

        }


       
    }
    cout << "+=============+=========================+=========+===============+=========+=========+=========+========+==========+===========+\n";
}

    
//Ham thong ke sinh vien
void ThongkeSV(SinhVien dsSV[], int n, string tenSV, string quequanSV) {
    int click;
    int dem = 0;
    int nam = 0;
    int nu = 0;
    int phaiSV;
    bool timsv = false;
    cout << "Nhap phuong thuc tim sinh vien:\n";
    cout << "+ 1.Tim kiem va thong ke so sinh vien hoc lai. " << endl;
    cout << "+ 2.Tim kiem theo ten sinh vien. " << endl;
    cout << "+ 3.Thong ke theo que quan." << endl;
    cout << "+ 4.Thong ke theo gioi tinh." << endl;
    cin >> click;
    system("cls");
    if (click == 1) {
        for (int i = 0; i < n; i++) {
            if (dsSV[i].diemTB < 5) {
                dem++;
            }
        }
        cout << "____________________________________________\n";
        cout << endl;
        cout << "So sinh vien hoc lai la: " << dem << endl;
        cout << "So sinh vien do la: " << n - dem << endl;
        cout << "Phan tram so sinh vien hoc lai la: " << (float)dem / n * 100 << "%" << endl;
        cout << "Phan tram so sinh vien do la: " << 100 - ((float)dem / n * 100) << "%" << endl;
        cout << endl;
        timsv = true;
    }
    else if (click == 2) {
        cout << "Nhap ten sinh vien ban muon tim: " << endl;
        cin >> tenSV;
        cout << "Nhung sinh vien co ky tu " << tenSV << " trong ten la : " << endl;
        for (int i = 0; i < n; i++) {
            if (dsSV[i].tenSV.find(tenSV) != string::npos) {
                cout << "-" << dsSV[i].tenSV << endl;
                dem++;
                timsv = true;
            }
        }

        cout << "So sinh vien co ten " << tenSV << " la: " << dem << endl;
        cout << "Phan tram so sinh vien co ten " << tenSV << " la: " << (float)dem / n * 100 << "%" << endl;
    }

    else if (click == 3) {
        cout << "Nhap dia chi sinh vien ban muon tim: " << endl;
        cin.ignore();
        getline(cin, quequanSV);

        cout << "Nhung sinh vien co dia chi " << quequanSV << " la : " << endl;
        for (int i = 0; i < n; i++) {
            if (dsSV[i].quequanSV.find(quequanSV) != string::npos) {
                cout << "-" << dsSV[i].tenSV << endl;
                dem++;
                timsv = true;
            }
        }
        cout << "So sinh vien dia chi  " << quequanSV << " la: " << dem << endl;
        cout << "Phan tram so sinh vien co dia chi " << quequanSV << " la: " << (float)dem / n * 100 << "%" << endl;
    }

    else if (click == 4) {
        cout << "Nhap gioi tinh sinh vien ban muon tim (1-Nam, 2-Nu): " << endl;
        int phaiSV;
        cin >> phaiSV;
        cout << "Nhung sinh vien thuoc gioi tinh ";
        if (phaiSV == 1) {
            cout << "Nam la : " << endl;
            for (int i = 0; i < n; i++) {
                if (dsSV[i].gioitinhSV == "Nam") {
                    cout << " " << dsSV[i].tenSV <<" - "<<"Lop "<<dsSV[i].lopSV<< endl;
                    dem++;
                    timsv = true;
                }
            }
            cout << "So sinh vien gioi tinh Nam la: " << dem << endl;
            cout << "Phan tram so sinh vien gioi tinh Nam la: " << (float)dem / n * 100 << "%" << endl;
        }
        else if (phaiSV == 2) {
            cout << "Nu la : " << endl;
            for (int i = 0; i < n; i++) {
                if (dsSV[i].gioitinhSV == "Nu") {
                   cout << " " << dsSV[i].tenSV <<" - "<<"Lop "<<dsSV[i].lopSV<< endl;
                    dem++;
                    timsv = true;
                }
            }
            cout << "So sinh vien gioi tinh Nu la: " << dem << endl;
            cout << "Phan tram so sinh vien gioi tinh Nu la: " << (float)dem / n * 100 << "%" << endl;
        }
    }
    if (!timsv) {
        cout << "Khong tim thay dia chi sinh vien!" << endl;
    }
}  

//Ham lay danh sach sinh vien tu file
void docDanhSachSinhVienTuFile(SinhVien dsSV[], int& n, char fileName[]) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line) && n < 100) {
            stringstream lineStream(line);
            getline(lineStream, dsSV[n].maSV, '-');
            getline(lineStream, dsSV[n].tenSV, '-');
            getline(lineStream, dsSV[n].lopSV, '-');
            getline(lineStream, dsSV[n].nghanhSV, '-');
            getline(lineStream, dsSV[n].gioitinhSV, '-');
            lineStream  >>dsSV[n].namsinh >> dsSV[n].diemTB >> dsSV[n].diem1 >> dsSV[n].diem2
                >> dsSV[n].diem3 ;
            getline(lineStream, dsSV[n].quequanSV);

            n++;
        }
        file.close();
    }

    hienThiDanhSachSinhVien(dsSV, n);
}
//Ham lua chon (y/n)
void HamtatCT(char c) {
   
    while (true) {
        cout << "Ban muon ve menu hay khong? (y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y') {
            // Quay l?i menu
            break;
        }
        else if (c == 'n' || c == 'N') {
            // K?t th�c chuong tr�nh
            system("cls");
            cout << "Tat chuong trinh!!!\n";
            exit(0);
        }
        else {
            // Th�ng b�o l?i v� y�u c?u nh?p l?i
            system("cls");
            cout << "Nhap khong hop le! Vui long nhap 'y' hoac 'n'.\n";
        }
    }
}
    int main() {
    int n = 0;
    string maSV, tenSV,quequanSV;
    int click;
    char fileName[] = "sinhvien.txt";
    int chon;
    char c;
    system("color 3");
    
    do {
        system("cls");
        cout << "      *******************CHUONG TRINH QUAN LY SINH VIEN C++**********************" << endl;
        cout << "                    *******************o0o****************                     " << endl;
        cout << endl;
        cout << "           " << "========================== MENU =================================" << endl;
        cout << "           " << "**            1. Nhap danh sach sinh vien                      **" << endl;
        cout << "           " << "**            2. Hien thi danh sach sinh vien                  **" << endl;
        cout << "           " << "**            3. Tim kiem sinh vien                            **" << endl;
        cout << "           " << "**            4. Sua thong tin sinh vien                       **" << endl;
        cout << "           " << "**            5. Xoa sinh vien                                 **" << endl;
        cout << "           " << "**            6. Sap xep danh sach sinh vien                   **" << endl;
        cout << "           " << "**            7. Thong ke danh sach                            **" << endl;
        cout << "           " << "**            8. Diem va hoc luc cua sinh vien                 **" << endl;
        cout << "           " << "**            9. Ghi vao file                                  **" << endl;
        cout << "           " << "**            10. Doc file co san                              **" << endl;
        cout << "           " << "**            0. Thoat                                         **" << endl;
        cout << "           " << "=================================================================" << endl;
        cout << "           " << "Nhap lua chon cua ban: ";
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
            HamtatCT(c);
           
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
           
             HamtatCT(c);
            break;
        case 7:
            ThongkeSV(dsSV, n, tenSV, quequanSV);
           HamtatCT(c);
            break;
        case 8:
            hoclucSV(dsSV, n);
           HamtatCT(c);
            break;
        case 9: 
            if (n > 0) {
                cout << "--Ghi danh sach vao file thanh cong--\n";
                ghiFile(dsSV, n, fileName);
            }
            else cout << "Danh sach trong khong the luu file!!!" << endl;
            break;
        case 10:
            docDanhSachSinhVienTuFile(dsSV, n, fileName);
            HamtatCT(c);
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
            break;
        }
    } while (chon != 0);

    return 0;
}

