#include<bits/stdc++.h>

using namespace std;

struct SinhVien {
    string tenSV;
    string maSV;
    string tuoiSV;
    string gioitinhSV;
    float diem1;
    float diem2;
    float diem3;
    double diemTB;
};

SinhVien dsSV[100];

void themSinhVien(SinhVien dsSV[], int& n) {
    SinhVien sv;
    cout << "Nhap SBD sinh vien: ";
    cin >> sv.maSV;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sv.tenSV);
    cout << "Nhap gioi tinh sinh vien: ";
    getline(cin, sv.gioitinhSV);
    cout << "Nhap tuoi cua sinh vien:";
    cin >> sv.tuoiSV;
    cout << "Diem mon 1:";
    cin >> sv.diem1;
    cout << "Diem mon 2:";
    cin >> sv.diem2;
    cout << "Diem mon 3:";
    cin >> sv.diem3;
    
    dsSV[n] = sv;
    n++;
    
}

void nhapDanhSachSinhVien(SinhVien dsSV[], int k, int& n) {
    for (int i = 0; i < k; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        themSinhVien(dsSV, n);
    }
}

void hienThiDanhSachSinhVien(SinhVien dsSV[], int n) {
    
       	 
      cout << "Danh sach sinh vien:\n";
    cout << "+=============+===================+===========+=======+=========+=========+=========+========+==========+\n";
    cout << "|     MaSV    | TenSV             | Gioi tinh | Tuoi  | Diem M1 | Diem M2 | diem M3 | DiemTB | Xep loai |\n";
    cout << "+=============+===================+===========+=======+=========+=========+=========+========+==========+\n";
    for (int i = 0; i < n; i++) {
        	  dsSV[i].diemTB = (float)(dsSV[i].diem1 + dsSV[i].diem2 + dsSV[i].diem3) / 3;
            cout << "| " << left << setw(12) << dsSV[i].maSV << "| ";
            cout << left << setw(18) << dsSV[i].tenSV << "| ";
            cout << left << setw(9) << dsSV[i].gioitinhSV << "| ";
            cout << left << setw(7) << dsSV[i].tuoiSV << "| ";
            cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diem1 << "| ";
            cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diem2 << "| ";
            cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diem3 << "| ";
            cout << left << setw(7) << fixed << setprecision(1) << dsSV[i].diemTB << "| ";
                if (dsSV[i].diemTB >= 8.5) {
                    cout << left << setw(9) << "Gioi" << "|" << endl;
                }
                else if (dsSV[i].diemTB >= 7) {
                    cout << left << setw(9) << "Kha" << "|" << endl;
                }
                else if (dsSV[i].diemTB >= 5.5) {
                    cout << left << setw(9) << "Trung binh" << "|" << endl;
                }
                else {
                    cout << left << setw(9) << "Yeu" << "|" << endl;
            
                }
                
            }
        cout << "_____________________________________________" << endl;
    }  

void sapXep(SinhVien dsSV[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsSV[i].diemTB > dsSV[j].diemTB) {
                SinhVien temp = dsSV[i];
                dsSV[i] = dsSV[j];
                dsSV[j] = temp;
           
            }
        }
    }
     hienThiDanhSachSinhVien( dsSV,  n);
   }
      
int main(){
	int n;
int k ;
  
    int luachon;	
	do {
		cout << "===================== MENU =====================" << endl;
        cout << "1. Nhap so phan tu mang" << endl;
        cout << "2. Hien thi mang" << endl;
        cout << "3. Tim so lon nhat" << endl;
        cout << "4. Xoa phan tu trong mang" << endl;
        cout << "5. Sap xep phan tu cua mang" << endl;
        cout << "0. Thoat" << endl;
        cout << "================================================" << endl;
        cout << "Nhap lua chon cua ban: ";
		cin >> luachon;
		cin.ignore();
		system("cls");
		switch (luachon) {
			case 1:
			{
				cout<< "Nhap so sinh ban muon"<<endl;
				cin>>k;
				 nhapDanhSachSinhVien(dsSV,  k,  n);
				break;
			}
			case 2: 
			{
				 hienThiDanhSachSinhVien( dsSV,  n);
			 	break;
			}
			case 3:
			{
				sapXep(dsSV,n);
				break;
			}
		/*	case 4:
		
			{
				nguyento(arr, n);
				break;
		*/	//}	
	
			case 0:
			{
				return 0;
			}
			default:
			{
				cout << "Nhap tu 1 den 3" << endl;
				break;
			}
		}
	} while (luachon != 3);
    return 0;
}

    
