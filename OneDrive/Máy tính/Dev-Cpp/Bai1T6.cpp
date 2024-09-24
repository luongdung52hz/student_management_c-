#include<bits/stdc++.h>

using namespace std;

struct SinhVien {
    string maSV;
    string tenSV;
    string lopSV;
    string gioitinhSV;
    string diachiSV;
    int namsinh;
    
    double diemTB;
};

SinhVien dsSV[100];

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
    
    cout << "Nhap diem TB mon:";
    cin >> sv.diemTB;

    dsSV[n] = sv;
    n++;
}

void nhapDanhSachSinhVien(SinhVien dsSV[], int k, int& n) {
    for (int i = 0; i < k; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        themSinhVien(dsSV, n);
    }
}
 int max (SinhVien dsSV[] , int n)   { 
    int max = dsSV[0].diemTB; 
    for (int i = 1; i < n; i++) {
        if (dsSV[i].diemTB > max) {
            max = dsSV[i].diemTB;
			
        }
        cout << "Sinh vien co diem TB lon nhat la:" << dsSV[i].tenSV << "-"<<max<<" diem" << endl;
      }
     
      return max;
	}


void hienThiDanhSachSinhVien(SinhVien dsSV[], int n) {
	for ( int i = 0 ; i < n ; i++){
	cout<<"_____________________________________________"<<endl;
	cout << endl;
	cout <<"Ma sinh vien la:"<<  dsSV[i].maSV << endl;
        cout <<"Ten sinh vien la:"<< dsSV[i].tenSV << endl;
        cout <<"Lop cua sinh vien la:" <<dsSV[i].lopSV << endl;
        cout <<"Gioi tinh cua sinh vien la:"<<  dsSV[i].gioitinhSV << endl;
        cout<<"Tuoi cua sinh vien la:" << 2023 - dsSV[i].namsinh << endl;
        cout <<"Dia chi sinh la:"<<  dsSV[i].diachiSV << endl;
        cout <<"Diem TB cua sinh vien:"<<  dsSV[i].diemTB << endl;
    
	     }
	     
	     cout<<"_____________________________________________"<<endl;
	     max(dsSV , n);
	}
      
int main(){
	int n ;
	int k;
	cout << "Nhap so luong sinh vien :"<<endl;
	cin >> k;
	nhapDanhSachSinhVien( dsSV, k, n);
	system("cls");
	
	hienThiDanhSachSinhVien(dsSV,  n);

	}  
