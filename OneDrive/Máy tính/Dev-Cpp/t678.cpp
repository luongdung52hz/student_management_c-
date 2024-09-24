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
    string gioitinhSV;
    string nghanhhocSV;
    int namsinh;
    float diem1;
    float diem2;
    float diem3;
    double diemTB;
};

SinhVien dsSV[100];
void ketquaSV(SinhVien dsSV[], int n);
void xetHocLuc(SinhVien dsSV[], int n, string maSV);

void themSinhVien(SinhVien dsSV[], int& n) {
    SinhVien sv;
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sv.tenSV);
    cout << "Gioi tinh cua sinh vien:";
    getline(cin, sv.gioitinhSV);
    cout << "Nam sinh cua sinh vien:";
    cin >> sv.namsinh;
    cout << "Nhap lop cua sinh vien:";
    cin.ignore();
    getline(cin, sv.lopSV);
    cout << "Nhap nghanh hoc cua sinh vien:";
    cin.ignore();
    getline(cin, sv.nghanhhocSV);
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
    cout << "+=============+=====================+===========+===========+======================+============+===========+==========+===========+\n";
    cout << "| MaSV        | TenSV               | LopSV     | Gioi tinh | Nganh hoc            | NamSinh    | DiemTB    | Ket qua  | Xep loai  |\n";
    cout << "+-------------+---------------------+-----------+-----------+----------------------+------------+-----------+----------+-----------+\n";
    for (int i = 0; i < n; i++) {
        dsSV[i].diemTB = (dsSV[i].diem1 + dsSV[i].diem2 + dsSV[i].diem3) / 3.0;
        cout << "| " << left << setw(12) << dsSV[i].maSV << "| ";
        cout << left << setw(20) << dsSV[i].tenSV << "| ";
        cout << left << setw(10) << dsSV[i].lopSV << "| ";
        cout << left << setw(10) << dsSV[i].gioitinhSV << "| ";
        cout << left << setw(21) << dsSV[i].nghanhhocSV << "| ";
        cout << left << setw(11) << dsSV[i].namsinh << "| ";
        cout << fixed << setprecision(2) << left << setw(10) << dsSV[i].diemTB << "|";
        //cout << left << setw(10);
        ketquaSV(dsSV, n);
        cout << "|";
        cout << left << setw(3);
        xetHocLuc(dsSV, n, dsSV[i].maSV);
        
    }
    cout << "+=============+=====================+===========+===========+======================+============+===========+==========+===========+\n";
}




// Hàm xoá sinh viên theo mã sinh viên
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
// Hàm s?a thông tin sinh viên
void suaThongTinSinhVien(SinhVien dsSV[], int n, string maSV) {
    for (int i = 0; i < n; i++) {
        if (dsSV[i].maSV == maSV) {
            SinhVien sv;
            cout << "Nhap ten sinh vien: ";
            cin.ignore();
            getline(cin, sv.tenSV);
            cout << "Nhap diem mon HA1: ";
            cin >> sv.diem1;
            cout << "Nhap diem C++: ";
            cin >> sv.diem2;
            cout << "Nhap diem QTCSDL: ";
            cin >> sv.diem3;
            dsSV[i] = sv;
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ma so " << maSV << endl;
}
// Hàm tím ki?m sinh viên theo mã sinh viên
void timKiemSinhVien(SinhVien dsSV[], int n, string maSV, string tenSV) {
    int click;
    cout << "Nhap phuong thuc tim sinh vien:\n";
    cout << "+ 1.Tim kiem theo ma sinh vien. " << endl;
    cout << "+ 2.Tim kiem theo ten sinh vien. " << endl;
    cin >> click;
    bool found = false; // bi?n ki?m tra xem dã tìm th?y sinh viên hay chua
    if (click == 1) {
        cout << "Nhap ma sinh vien ban muon tim: " << endl;
        cin >> maSV;
        for (int i = 0; i < n; i++) {
            if (dsSV[i].maSV == maSV) {
                hienThiDanhSachSinhVien(dsSV, n);
                /*cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
                cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
                cout << "Diem mon HA1 : " << dsSV[i].diem1 << endl;
                cout << "Diem mon C++ : " << dsSV[i].diem2 << endl;
                cout << "Diem mon QTCSDL :" << dsSV[i].diem3 << endl;*/
                found = true;
                break; // tìm th?y sinh viên r?i nên d?ng vòng l?p
            }
        }
        if (!found) {
            cout << "Khong tim thay ma sinh vien " << maSV << " trong danh sach" << endl;
        }
    }
    else if (click == 2) {
        cout << "Nhap ten sinh vien ban muon tim: " << endl;
        cin.ignore();
        getline(cin, tenSV);
        for (int i = 0; i < n; i++) {
            if (dsSV[i].tenSV == tenSV) {
                hienThiDanhSachSinhVien(dsSV, n);
               /* cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
                cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
                cout << "Diem mon HA1: " << dsSV[i].diem1 << endl;
                cout << "Diem mon C++: " << dsSV[i].diem2 << endl;
                cout << "Diem mon QTCSDL:" << dsSV[i].diem3 << endl;*/
                found = true;
                break; // tìm th?y sinh viên r?i nên d?ng vòng l?p
            }
        }
        if (!found) {
            cout << "Khong tim thay ten sinh vien " << tenSV << " trong danh sach" << endl;
        }
    }
    else {
        cout << "Phuong thuc tim khong hop le" << endl;
    }
}
// Hàm s?p x?p sinh viên theo di?m trung bình
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
    hienThiDanhSachSinhVien(dsSV,  n);
}
void ghiFile(SinhVien dsSV[], int n, char fileName[]) {
    ofstream fout(fileName);
    if (!fout.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        fout << setw(5) << dsSV[i].maSV << setw(30) << dsSV[i].tenSV << setw(5) << dsSV[i].lopSV << setw(5)
            << dsSV[i].namsinh << setw(10) << dsSV[i].diemTB << endl;
        if (fout.fail()) {
            cout << "Ghi du lieu that bai!\n";
            fout.close();
            return;
        }
    }
    fout.close();
}
int docFile(SinhVien dsSV[], string fileName) {
    ifstream fileIn(fileName.c_str());
    int i = 0;
    cout << "Chuan bi doc file: " << fileName << endl;
    // doc thong tin sinh vien
    while (fileIn >> dsSV[i].maSV >> dsSV[i].tenSV >> dsSV[i].lopSV >> dsSV[i].namsinh >> dsSV[i].diemTB) {
        i++;
        cout << "Doc ban ghi thu: " << i << endl;
    }
    cout << "So luong sinh vien co san trong file la: " << i << endl;
    cout << endl;
    // tra ve so luong sinh vien duoc doc tu file
    fileIn.close();
    return i;
}
/*void Mofile(string fileName) {
    ifstream fileIn(fileName.c_str());
    string line;
    if (fileIn.is_open()) {
        while (getline(fileIn, line)) {
            cout << line << endl;
        }
        fileIn.close();
    } 
    else {
        cout << "Unable to open file" << endl;
    }
}*/
void ketquaSV(SinhVien dsSV[], int n) {
    for (int i = 0; i < n; i++) {
        if (dsSV[i].diemTB > 5) {
            cout << " Do";
        }
        else {
            cout << " Rot";
        }
    }
}

//Hàm xét h?c l?c c?a sinh viên
void xetHocLuc(SinhVien dsSV[], int n, string maSV) {
  //  for (int i = 0; i < n; i++) {
        //  if (dsSV[i].maSV == maSV) {

        if (dsSV[n].diemTB >= 0 && dsSV[n].diemTB < 5) {
            cout << "  F\n";
        }
        else if (dsSV[n].diemTB >= 5 && dsSV[n].diemTB < 5.5) {
            cout <<  "  D+\n";
        }
        else if (dsSV[n].diemTB >= 5.5 && dsSV[n].diemTB < 6.5) {
            cout << "  C\n";
        }
        else if (dsSV[n].diemTB >= 6.5 && dsSV[n].diemTB < 7) {
            cout << "  C+\n";
        }
        else if (dsSV[n].diemTB >= 7 && dsSV[n].diemTB < 8) {
            cout <<  "  B\n";
        }
        else if (dsSV[n].diemTB >= 8 && dsSV[n].diemTB < 8.5) {
            cout << "  B + \n";
        }
        else if (dsSV[n].diemTB >= 8.5 && dsSV[n].diemTB <= 10) {
            cout << "  A\n";

        }

    
        }
//    }


int main() {
    int n = 0;
    string maSV,tenSV;
    int click;
    char fileName[] = "sinhvien.txt";
    int chon;
    do {
        cout << "===================== MENU =====================" << endl;
        cout << "1. Nhap danh sach sinh vien" << endl;
        cout << "2. Hien thi danh sach sinh vien" << endl;
        cout << "3. Tim kiem sinh vien" << endl;
        cout << "4. Sua thong tin sinh vien" << endl;
        cout << "5. Xoa sinh vien" << endl;
        cout << "6. Danh sach sinh vien theo diem TB giam dan" << endl;
        cout << "7. Ghi vao file" << endl;
        cout << "8. Doc file da ghi" << endl;
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
            docFile(dsSV, fileName);
            break;
       
         //   Mofile( fileName );
         //   break;  
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
            break;
        }
    } while (chon != 0);

    return 0;
}
/*/
void doiMauChu(){
    int a;
  cout << "Nhap mau ban muon doi\n";
  cout << "1.Do\n";
  cout << "2.Vang\n";
  cout << "3.Tim\n";
  cin >> a;
  if (a == 1) {
      system("color 2");
  }

  else if (a == 2) {
      system("color 3");
  }
  else if (a == 3 ){
  system("color 4"); }
  else { cout << "Khong co lua chon do" << endl; }
  }*/
