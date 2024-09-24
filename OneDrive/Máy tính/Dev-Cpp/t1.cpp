#include <bits/stdc++.h>

using namespace std;

struct sinhvien
{
	string masinhvien, hoten, ngaysinh, lop;
	double diemtb;
	
};

	
	//Hàm in thong tin sinhvien
void in(sinhvien base[], int n){
	for(int i = 0; i<n; i++){
		cout << "------------------------------------------------------------------------" << endl;
		cout << "Ma Sinh Vien : " << base[i].masinhvien << endl;
		cout << "Ho Ten Sinh Vien: " << base[i].hoten << endl;
		cout << "Ngay Sinh: " << base[i].ngaysinh << endl;
		cout << "Lop: " << base[i].lop << endl;
		if(base[i].diemtb != 0.0) {
			cout << "Diem Trung Binh: " << fixed << setprecision(2) << base[i].diemtb << endl;
		} else {
			cout << "Diem Trung Binh: Chua nhap" << endl;
		}
		cout << "------------------------------------------------------------------------" << endl;
	}
}

	//Hàm Nhap Thong Tin Sinh Vien
	void nhap(sinhvien base[], int n){
		cout << "------------------------------------------------------------------------" << endl;
		cout << "Nhap Ma Sinh Vien: "; cin >> base[n].masinhvien;
		cout << "Nhap Ho Ten Sinh Vien: "; cin >> base[n].hoten;
		cin.ignore();
		getline(cin, base[n].hoten);
		cout << "Nhap Ngay Sinh: "; cin >> base[n].ngaysinh;
		cout << "Nhap Lop: "; cin >> base[n].lop;
		cout << "Nhap Diem Trung Binh: "; cin >> base[n].diemtb;
		cout << "Them Thanh Cong Sinh Vien" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
	}


//Ham tim kiem sinh vien theo ma sinh vien
void timkiemsv(sinhvien base[], int n){
	string masv;
	cout << "Nhap Ma Sinh Vien Can Tim: "; cin >> masv;
	for(int i = 0; i < n; i++){
		if(masv == base[i].masinhvien){
			in(base, n);
			break;	
		}
		else
		{
			cout << "Khong tim thay sinh vien nao.";
		}
	}
	
}

//Sua Thong Tin Sinh Vien Theo Ma
void suathongtin(sinhvien base[], int n){
	string masv;
	cout << "Nhap Ma Sinh Vien Can Tim: ";
	cin >> masv;
	for(int i = 0; i < n; i++){
		if(masv == base[i].masinhvien)
		{
			cout << "Nhap Ma Sinh Vien: "; cin >> base[i].masinhvien;
			cout << "Nhap Ho Ten Sinh Vien: "; cin >> base[i].hoten;
			cin.ignore();
			getline(cin, base[i].hoten);
			cout << "Nhap Ngay Sinh: "; cin >> base[i].ngaysinh;
			cout << "Nhap Lop: "; cin >> base[i].lop;
			cout << "Nhap Diem Trung Binh: "; cin >> base[i].diemtb;
		}
		else{
			cout << "Khong tim thay sinh vien co ma sv " + masv << endl;
		}
	}
}


//Ham tim kiem sinh vien theo ten sinh vien
void timkiemsv2(sinhvien base[], int n){
	string hotensv;
	cout << "Nhap Ten Sinh Vien Can Tim: ";cin >> hotensv;
	for(int i = 0; i < n; i++){
		if(hotensv == base[i].hoten){
			in(base, n);
			break;	
		}
		else
		{
			cout << "Khong tim thay sinh vien nao.\n";
		}
	}
}


void nhapDanhSachSinhVien(sinhvien base[], int k, int n) {
    for (int i = 0; i < k; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        nhap(base, n);
    }
}

void sapxep(sinhvien base[], int n)
{
	for(int i = 0; i <n-1; i++){
		for(int j= i + 1;j<n; j++){
			if(base[i].diemtb < base[j].diemtb){
				sinhvien temp = base[i];
				base[i] = base[j];
				base[i] = temp;
			}
		}
	}
	in(base ,n);
}


//Ham xoa sinh vien theo ma sinh vien
void xoasinhvien(sinhvien base[], int n){
	string masv;

	cout << "Nhap Ma Sinh Vien Can Xoa: ";cin >> masv;
	for(int i = 0; i < n; i++){
		if(masv == base[i].masinhvien){
			for(int j = i; j < n; j++){
				base[j] = base[j + 1];
			}
			n--;
			return;
		}
	}
}


int main(){
	sinhvien base[100];
	int n = 0;
	int k;
	int luachon;
	do{
		cout << "--------------------Chuong Trinh Quan Ly Sinh Vien---------------------\n";
		cout << "1. Nhap Thong Tin Sinh Vien.\n";
		cout << "2. Hien Thi Toan Bo Thong Tin Sinh Vien.\n";
		cout << "3. Tim Kiem Sinh Vien Theo Ma Sinh Vien.\n";
		cout << "4. Tim Kiem Sinh Vien Theo Ho Ten.\n";
		cout << "5. Xoa Sinh Vien. \n";
		cout << "6. Sua thong tin sinh vien. \n";
		cout << "7. Sap Xep Sinh Vien Diem Trung Binh \n";
		cout << "0. Thoat \n";
		cout << "-----------------------------------------------------------------------\n";
		cout << "Nhap Lua Chon Cua Ban:";
		 cin >> luachon;
		system("cls");
		switch(luachon)
		{
			case 1:
			{cout << "Nhap"<<endl;
			cin>> k;
				nhapDanhSachSinhVien(base,  k,  n);
				n++;
			
				break;
			}	
			case 2:
			{
			//	system("cls");
				in(base, n);
				break;
			}
			case 3:
			{
				system("cls");
				timkiemsv(base, n);
				break;
			}
			case 4: 
			{
				system("cls");
				timkiemsv2(base, n);
				break;
			}
			case 5:
			{
				system("cls");
				xoasinhvien(base, n);
				break;
			}
			case 6: 
			{
				system("cls");
				suathongtin(base, n);
				break;
			}
			case 7:
			{system("cls");
				sapxep(base, n);
			//	danhsach(base, n);
			}
			case 0:
			{
				break;
			}
			default:
			{
				cout << "Nhap So Tu 1 Toi 7\n";
				break;
			}
		}
	}while (luachon != 0);
	return 0;
}

