#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
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

void themSinhVien(SinhVien dsSV[], int &n) {
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
    cout << "Nhap diem 1: ";
    cin >> sv.diem1;
    cout << "Nhap diem 2: ";
    cin >> sv.diem2;
    cout << "Nhap diem 3: ";
    cin >> sv.diem3;
    
    dsSV[n] = sv;
    n++;
}

void nhapDanhSachSinhVien(SinhVien dsSV[], int k, int &n) {
    for (int i = 0; i < k; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        themSinhVien(dsSV, n);
    }
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

void suaThongTinSinhVien(SinhVien dsSV[], int n, string maSV) {
    for (int i = 0; i < n; i++) {
        if (dsSV[i].maSV == maSV) {
        	cout << "Nhap ma sinh vien ban muon xoa: "<< endl;
            SinhVien sv;
            cout << "Nhap ten sinh vien: ";
            cin.ignore();
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

void timKiemSinhVien(SinhVien dsSV[], int n, string maSV,string tenSV,int click) {
	cout << "Nhap phuong thuc tim sinh vien:\n";
    cout << "+ 1.Tim kiem theo ma sinh vien. " << endl;
    cout << "+ 2.Tim kiem theo ten sinh vien. "<< endl;
	cin >> click;
    for (int i = 0; i < n; i++) {
	if ( click == 1){
	    cout << "Nhap ma sinh vien ban muon tim: "<< endl;
		cin >> maSV;	
        if (dsSV[i].maSV == maSV) {
            cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
            cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
            cout << "Diem toan: " << dsSV[i].diem1 << endl;
            cout << "Diem ly: " << dsSV[i].diem2 << endl;
            cout << "Diem hoa:"<< dsSV[i].diem3 << endl;
            return; }
           else cout << "Khong tim thay ma sinh vien"<< maSV <<"trong danh sach"<<endl; 
        }
        else if( click == 2){
		    cout << "Nhap ten sinh vien ban muon tim: "<< endl;
		    cin >> tenSV;	
        if (dsSV[i].tenSV == tenSV) {
            cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
            cout << "Ten sinh vien: " << dsSV[i].tenSV << endl;
            cout << "Diem toan: " << dsSV[i].diem1 << endl;
            cout << "Diem ly: " << dsSV[i].diem2 << endl;
            cout << "Diem hoa:"<< dsSV[i].diem3 << endl;
            return; }
            else cout << "Khong tim thay ten sinh vien"<< tenSV <<"trong danh sach"<<endl; 
	       }
	     
		   
        }
        
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
    }
    hienThiDanhSachSinhVien(dsSV, n);
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
    while (fileIn >> dsSV[i].maSV >> dsSV[i].tenSV >> dsSV[i].lopSV >>  dsSV[i].namsinh >>dsSV[i].diemTB) {
        i++;
        cout << "Doc ban ghi thu: " << i << endl;
    }
    cout << "So luong sinh vien co san trong file la: " << i << endl;
    cout << endl;
    // tra ve so luong sinh vien duoc doc tu file
    fileIn.close();
    return i;
}
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
        cout << "6. Danh sach sinh vien theo diem TB" << endl;
        cout << "7. Ghi vao file" << endl;
        cout << "0. Thoat" << endl;
        cout << "================================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        switch (chon) {
            case 0:
                break;
            case 1:
                int k;
                cout << "Nhap so luong sinh vien: ";
                cin >> k;
                nhapDanhSachSinhVien(dsSV, k, n);
                break;
            case 2:
                hienThiDanhSachSinhVien(dsSV, n);
                break;
            case 3:
                timKiemSinhVien(dsSV, n, maSV,tenSV,click);
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
                break;
            case 6:
            	
    sapXepDanhSachSinhVien(dsSV, n);
    for (int i = 0; i < n; i++) {
        cout << dsSV[i].tenSV << " - " << dsSV[i].diemTB << endl;
    }
    break;
         case 7:
         	ghiFile( dsSV,  n, fileName);
         	break;
         	
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
                break;
        }
    } while (chon != 0);

    return 0;
}

