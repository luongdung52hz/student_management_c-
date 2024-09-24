#include<iostream>
#include<string>
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct SinhVien {
    string maSV;
    string tenSV;
    string tenSV1;
    string lopSV;
    string gioitinhSV;
    string quequanSV;
    string nghanhSV;
    int namsinh;
    float diem1;
    float diem2;
    float diem3;
    float diemTB;

};
void hoclucSV(SinhVien dsSV[], int n);
SinhVien dsSV[100];

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

    cout << "Nhap nghanh hoc cua sinh vien: ";

    getline(cin, sv.nghanhSV);
    cout << "Nhap lop cua sinh vien: ";

    getline(cin, sv.lopSV);
    cout << "Nam sinh cua sinh vien: ";
    cin >> sv.namsinh;
    cout << "Nhap diem mon 1: ";
    cin >> sv.diem1;
    cout << "Nhap diem mon 2: ";
    cin >> sv.diem2;
    cout << "Nhap diem mon 3: ";
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
    
    cout << right << setw(70) << "++DANH SACH SINH VIEN++" << endl;
    cout << endl;


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
    int click;
    bool exit = false;
    cout << "           " << "==================== XOA DANH SACH ==================" << endl;
    cout << "           " << "**            1. Xoa theo ma sinh vien             **" << endl;
    cout << "           " << "**            2. Xoa toan bo danh sach sinh vien   **" << endl;
    cout << "           " << "**            0. Thoat                              **" << endl;
    cout << "           " << "=====================================================" << endl;
    cout << "           " << "Nhap lua chon cua ban: ";
    cin >> click;

    switch (click) {
        case 0:
            exit = true;
            break;
        case 1:
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSV;
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
            break;
        case 2:
            n = 0;
            cout << right << setw(60) << "Da xoa toan bo du lieu sinh vien!!!" << endl;
            cout << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
    }

    if (exit) {
      
        return;
    }
}


// Ham sua thong tin
void suaThongTinSinhVien(SinhVien dsSV[], int n, string maSV) {
    int c;
      bool exit = false;
    for (int i = 0; i < n; i++) {
        if (dsSV[i].maSV == maSV) {
            SinhVien sv;
            sv.maSV = maSV;
            cout << "           " << "======================= Sua Thong Tin ====================" << endl;
            cout << "           " << "**            1. Chinh sua ho va ten                    **" << endl;
            cout << "           " << "**            2. Chinh cua nam sinh                     **" << endl;
            cout << "           " << "**            3. Chinh sua lop sinh vien                **" << endl;
            cout << "           " << "**            4. Chinh sua nghanh hoc sinh vien         **" << endl;
            cout << "           " << "**            5. Chinh sua diem M1                      **" << endl;
            cout << "           " << "**            6. Chinh sua diem M2                      **" << endl;
            cout << "           " << "**            7. Chinh sua diem M3                      **" << endl;
            cout << "           " << "**            0. Thoat                                  **" << endl;
            cout << "           " << "==========================================================" << endl;
            cout << "           " << "Nhap lua chon cua ban: ";
            cin >> c;
            switch (c) {
           	case 0:
                    exit = true;
                    break;
            case 1: {
                cout << "Nhap ten sinh vien: ";
                cin.ignore();
                getline(cin, sv.tenSV);
                sv.gioitinhSV = dsSV[i].gioitinhSV;
                sv.quequanSV = dsSV[i].quequanSV;
                sv.nghanhSV = dsSV[i].nghanhSV;
                sv.lopSV = dsSV[i].lopSV;
                sv.namsinh = dsSV[i].namsinh;
                sv.diem1 = dsSV[i].diem1;
                sv.diem2 = dsSV[i].diem2;
                sv.diem3 = dsSV[i].diem3;
                cout << "Ban da sua ten " << dsSV[i].tenSV << " thanh cong!!" << endl;
                break;
            }
            case 2: {

                cout << "Nam sinh cua sinh vien:";
                cin >> sv.namsinh;
                sv.tenSV = dsSV[i].tenSV;
                sv.gioitinhSV = dsSV[i].gioitinhSV;
                sv.quequanSV = dsSV[i].quequanSV;
                sv.lopSV = dsSV[i].lopSV;
                sv.nghanhSV = dsSV[i].nghanhSV;
                sv.diem1 = dsSV[i].diem1;
                sv.diem2 = dsSV[i].diem2;
                sv.diem3 = dsSV[i].diem3;
                break;
            }
            case 3: {
                cout << "Nhap lop cua sinh vien:";

                getline(cin, sv.lopSV);
                sv.tenSV = dsSV[i].tenSV;
                sv.gioitinhSV = dsSV[i].gioitinhSV;
                sv.quequanSV = dsSV[i].quequanSV;
                sv.nghanhSV = dsSV[i].nghanhSV;
                sv.namsinh = dsSV[i].namsinh;
                sv.diem1 = dsSV[i].diem1;
                sv.diem2 = dsSV[i].diem2;
                sv.diem3 = dsSV[i].diem3;
                break;
            }
            case 4: {
                cout << "Nhap nghanh hoc cua  sinh vien: ";

                getline(cin, sv.nghanhSV);
                sv.tenSV = dsSV[i].tenSV;
                sv.gioitinhSV = dsSV[i].gioitinhSV;
                sv.quequanSV = dsSV[i].quequanSV;
                sv.lopSV = dsSV[i].lopSV;
                sv.namsinh = dsSV[i].namsinh;
                sv.diem1 = dsSV[i].diem1;
                sv.diem2 = dsSV[i].diem2;
                sv.diem3 = dsSV[i].diem3;
                break;
            }
            case 5: {
                cout << "Nhap diem mon 1:";
                cin >> sv.diem1;
                sv.tenSV = dsSV[i].tenSV;
                sv.gioitinhSV = dsSV[i].gioitinhSV;
                sv.quequanSV = dsSV[i].quequanSV;
                sv.nghanhSV = dsSV[i].nghanhSV;
                sv.lopSV = dsSV[i].lopSV;
                sv.namsinh = dsSV[i].namsinh;
                sv.diem2 = dsSV[i].diem2;
                sv.diem3 = dsSV[i].diem3;
                break;
            }
            case 6: {
                cout << "Nhap diem mon 2:";
                cin >> sv.diem1;
                sv.tenSV = dsSV[i].tenSV;
                sv.gioitinhSV = dsSV[i].gioitinhSV;
                sv.quequanSV = dsSV[i].quequanSV;
                sv.nghanhSV = dsSV[i].nghanhSV;
                sv.lopSV = dsSV[i].lopSV;
                sv.namsinh = dsSV[i].namsinh;
                sv.diem2 = dsSV[i].diem1;
                sv.diem3 = dsSV[i].diem3;
                break;
            }
            case 7: {
                cout << "Nhap diem mon 3:";
                cin >> sv.diem1;
                sv.tenSV = dsSV[i].tenSV;
                sv.gioitinhSV = dsSV[i].gioitinhSV;
                sv.quequanSV = dsSV[i].quequanSV;
                sv.nghanhSV = dsSV[i].nghanhSV;
                sv.lopSV = dsSV[i].lopSV;
                sv.namsinh = dsSV[i].namsinh;
                sv.diem2 = dsSV[i].diem2;
                sv.diem3 = dsSV[i].diem1;
                break;
            }
            default: {
                break;

                cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
                break;
            }
            }
            dsSV[i] = sv;

            return;
        }

    }

}



// Ham tim kiem
void timKiemSinhVien(SinhVien dsSV[], int n, string maSV, string tenSV) {
    int click;
    bool exit = false;

    while (!exit) {
        cout << "Nhap phuong thuc tim sinh vien:\n";
        cout << "+ 1.Tim kiem theo ma sinh vien. " << endl;
        cout << "+ 2.Tim kiem theo ten sinh vien. " << endl;
        cout << "+ 0.Thoat. " << endl;
        cin >> click;

        switch (click) {
            case 0:
                exit = true;
                break;
            case 1: {
                cout << "Nhap ma sinh vien ban muon tim: " << endl;
                cin >> maSV;

                bool timsv = false; // bien kiem tra xem da tim thay sinh vien chua

                for (int i = 0; i < n; i++) {
                    if (dsSV[i].maSV == maSV) {
                        cout << "____________________________________\n" << endl;

                        cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
                        cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
                        cout << "Tuoi cua sinh vien: " << 2023 - dsSV[i].namsinh << endl;
                        cout << "Dia chi cua sinh vien: " << dsSV[i].quequanSV << endl;
                        cout << "Diem trung binh cua sinh vien: " << dsSV[i].diemTB << endl;

                        cout << "____________________________________\n";
                        timsv = true;
                        break; // tim thay sinh vien len dung vong lap
                    }
                }
                if (!timsv) {
                    cout << "Khong tim thay ma sinh vien " << maSV << " trong danh sach" << endl;
                }
                break;
            }
            case 2: {
                cout << "Nhap ten sinh vien ban muon tim: " << endl;
                cin.ignore();
                getline(cin, tenSV);

                bool timsv = false; // bien kiem tra xem da tim thay sinh vien chua

                for (int i = 0; i < n; i++) {
                    if (dsSV[i].tenSV == tenSV) {
                        cout << "____________________________________\n" << endl;

                        cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
                        cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
                        cout << "Tuoi cua sinh vien: " << 2023 - dsSV[i].namsinh << endl;
                        cout << "Dia chi cua sinh vien: " << dsSV[i].quequanSV << endl;
                        cout << "Diem trung binh cua sinh vien: " << dsSV[i].diemTB << endl;

                        cout << "____________________________________\n";
                        timsv = true;
                        break; // tim thay sinh vien len dung vong lap
                    }
                }
                if (!timsv) {
                    cout << "Khong tim thay ten sinh vien " << tenSV << " trong danh sach" << endl;
                }
                break;
            }
            default:
                cout << "Phuong thuc tim khong hop le" << endl;
                break;
        }
    }
}

// Ham sap xep
void sapXepDanhSachSinhVien(SinhVien dsSV[], int n) {
    int click;
    while (true) {
        cout << "           " << "====================== Sap xep DS SV =====================" << endl;
        cout << "           " << "**            1. Sap xep theo ten sinh vien             **" << endl;
        cout << "           " << "**            2. Sap xep theo ma sinh vien              **" << endl;
        cout << "           " << "**            3. Sap xep theo diem trung binh           **" << endl;
        cout << "           " << "**            4. Thoat                                   **" << endl;
        cout << "           " << "==========================================================" << endl;
        cout << "           " << "Nhap lua chon cua ban: ";
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
       
            hienThiDanhSachSinhVien(dsSV, n);
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
            hienThiDanhSachSinhVien(dsSV, n);
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
        else if (click == 4) {
            cout << "Thoat chuong trinh." << endl;
            break;
        }
        else {
            cout << "Lua chon khong hop le." << endl;
        }
    }
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
            cout << left << setw(7) << fixed << setprecision(1) << dsSV[i].diem1 << "*" << "| ";
        }
        else {
            cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diem1 << "| ";
        }
        if (dsSV[i].diem2 <= 2) {
            cout << left << setw(7) << fixed << setprecision(1) << dsSV[i].diem2 << "*" << "| ";
        }
        else {
            cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diem2 << "| ";
        }
        if (dsSV[i].diem3 <= 2) {
            cout << left << setw(7) << fixed << setprecision(1) << dsSV[i].diem3 << "*" << "| ";
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
    while (true) {
        cout << "           " << "======================= Thong Ke SV ======================" << endl;
        cout << "           " << "**        1. Tim kiem va thong ke so sinh vien          **" << endl;
        cout << "           " << "**        2. Tim kiem theo ten sinh vien                **" << endl;
        cout << "           " << "**        3. Thong ke theo que quan                     **" << endl;
        cout << "           " << "**        4. Thong ke theo gioi tinh                    **" << endl;
        cout << "           " << "**        5. Thoat                                       **" << endl;
        cout << "           " << "==========================================================" << endl;
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
            cin >> phaiSV;
            cout << "Nhung sinh vien thuoc gioi tinh ";
            if (phaiSV == 1) {
                cout << "Nam la : " << endl;
                for (int i = 0; i < n; i++) {
                    if (dsSV[i].gioitinhSV == "Nam") {
                        cout << " " << dsSV[i].tenSV << " - " << "Lop " << dsSV[i].lopSV << endl;
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
                        cout << " " << dsSV[i].tenSV << " - " << "Lop " << dsSV[i].lopSV << endl;
                        dem++;
                        timsv = true;
                    }
                }
                cout << "So sinh vien gioi tinh Nu la: " << dem << endl;
                cout << "Phan tram so sinh vien gioi tinh Nu la: " << (float)dem / n * 100 << "%" << endl;
            }
        } 
        else if (click == 5) {
            cout << "Thoat chuong trinh." << endl;
            break;
        }
        else {
            cout << "Lua chon khong hop le." << endl;
        }
    }
    if (!timsv) {
        cout << "Khong tim thay dia chi sinh vien!" << endl;
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
            lineStream >> dsSV[n].namsinh >> dsSV[n].diemTB >> dsSV[n].diem1 >> dsSV[n].diem2
                >> dsSV[n].diem3;
            getline(lineStream, dsSV[n].quequanSV);

            n++;
        }
        file.close();
    }

}

//Ham lua chon (y/n)
void HamtatCT(char c) {

    while (true) {
        cout << "Ban muon ve menu hay khong? (y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y') {
            // Quay lai menu
            break;
        }
        else if (c == 'n' || c == 'N') {
            // Ket thuc chuong trinh
            system("cls");
            cout << "Tat chuong trinh!!!\n";
            exit(0);
        }
        else {
            // Thong bao yeu cau nhap lai
            system("cls");
            cout << "Nhap khong hop le! Vui long nhap 'y' hoac 'n'.\n";
        }
    }
}
//Ham giao dien Menu
void Menu(){
	 
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
        cout << "           " << "**            0. Thoat                                         **" << endl;
        cout << "           " << "=================================================================" << endl;
        cout << "           " << "Nhap lua chon cua ban: ";
}
// Ham chuc nang cua Menu
void Menuchon(){
	  int n = 0;
    string maSV, tenSV, quequanSV;
    int click;
    char fileName[] = "sinhvien.txt";
    int chon;
    char c = 0;
    int Choice;
    system("color 3");
      docDanhSachSinhVienTuFile(dsSV, n, fileName);
    Menu();
	 do {
            cin >> chon;
            system("cls");
            switch (chon) {
                case 0:
                    HamtatCT(c);
                    system("cls");
                    Menu();
                    break;
                case 1:
                    int k;
                    cout << "Nhap so luong sinh vien: ";
                    cin >> k;
                    nhapDanhSachSinhVien(dsSV, k, n);
                    HamtatCT(c);
	      			 system("cls");
                          Menu();
                   
                    break;
                case 2:
                    hienThiDanhSachSinhVien(dsSV, n);
                    HamtatCT(c);
					 system("cls");
                    Menu();
                   
                    break;
                case 3:
                    timKiemSinhVien(dsSV, n, maSV, tenSV);
                        Menu();
                    break;
                case 4:
                    cout << "Nhap ma sinh vien can sua thong tin: ";
                    cin >> maSV;
                    suaThongTinSinhVien(dsSV, n, maSV);
                        Menu();
                    break;
                case 5:
                    xoaSinhVien(dsSV, n, maSV);
                        Menu();
                    break;
                case 6:
                    sapXepDanhSachSinhVien(dsSV, n);
                        Menu();
                    break;
                case 7:
                	system("cls");
                    ThongkeSV(dsSV, n, tenSV, quequanSV);
                   // HamtatCT(c);
                    //system("cls");
                     Menu();
                    break;
                case 8:    
				  
                    hoclucSV(dsSV, n);
                HamtatCT(c);
					 system("cls");
                        Menu();
                    break;
                case 9:
                    if (n > 0) {
                        cout << right << setw(60) << "--Ghi danh sach vao file thanh cong--" << endl;
                        cout << endl;
                        ghiFile(dsSV, n, fileName);
                    } else {
                        cout << right << setw(60) << "Danh sach trong khong the luu file!!!" << endl;
                        cout << endl;
                    }
                    Menu();
                    break;
            }
        } while (chon < 10);
}
int main() {
    int n = 0;
    string maSV, tenSV, quequanSV;
    int click;
    char fileName[] = "sinhvien.txt";
    int chon;
    char c = 0;
    int Choice;
    system("color 3");
   
cout << "+=========================================================+\n";
cout << "+     CHAO MUNG DEN VOI CHUONG TRINH QUAN LI SINH VIEN    +\n";
cout << "+=========================================================+\n";
cout << "|                       1. MENU                           |\n";
cout << "|                       2. OPEN FILE                      |\n";
cout << "|                       3. EXIT                           |\n";
cout << "+=========================================================+\n";
cout << "\n";
cout << "MOI BAN NHAP LUA CHON: ";
cin >> Choice;
system("cls");

switch (Choice) {
    // CHON MUC 1: MENU
    case 1: {
       Menuchon();
        break;
    }
    // CHON MUC 2: OPEN FILE
    case 2: {  

   	Menuchon();
      docDanhSachSinhVienTuFile(dsSV, n, fileName);
       
       break;
    }
    // CHON MUC 3: EXIT
    case 3: {
       
        break;
    }
  
    default: {
       
        break;
    }
}

return 0;


}

