#include<bits/stdc++.h>
using namespace std;

struct SinhVien {
    string maSV;
    string tenSV;
    string lopSV;
    float diem1;
    float diem2;
    float diem3;
};

void themSinhVien(SinhVien dsSV[] , int n) {
    SinhVien sv;
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sv.tenSV);
    cout << "Nhap lop cua sinh vien: ";
    getline(cin, sv.lopSV);
    cout << "Nhap diem 1: ";
    cin >> sv.diem1;
    cout << "Nhap diem 2: ";
    cin >> sv.diem2;
    cout << "Nhap diem 3: ";
    cin >> sv.diem3;
n++;

void nhapDanhSachSinhVien(SinhVien dsSV[], int n) {
    int k;
    cout << "Nhap so luong sinh vien can them: ";
    cin >> k;
    for (int i = 0; i < k; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        themSinhVien(dsSV);
    }
}}
void HienDanhsach(SinhVien dsSV[], int n){
  for(i = 0 ; i < n ; i++){
  cout << "Ma Sinh Vien"<< dsSV[i].maSV<<endl;
  cout << "Ten Sinh Vien"<< dsSV[i].tenSV<<endl;
  cout << "Lop Sinh Vien"<< dsSV[i].lopSV<<endl;
  cout << "Diem 1 Sinh Vien"<< dsSV[i].diem1<<endl;
  
  }



}
int main() {
 int n;
    nhapDanhSachSinhVien(dsSV, n); 
    HienDanhSach(dsSV, n);
    return 0;
}
