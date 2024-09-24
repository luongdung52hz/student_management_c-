#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

  dsSV[n] = sv;
    n++;
int main() {
    int Luachon1, Luachon2, Luachon3;

    do {
        // Menu 1
    	cout <<"CHAO MUNG DEN VOI CHUONG TRINH QUAN LY SINH VIEN\n";
		cout <<"***********************o0o**********************\n";
		cout <<"+----------------------------------------------+\n";
		cout <<"|                                              |\n";
		cout <<"|                  1. MENU                     |\n";
		cout <<"|                  2. SAVE FILE                |\n";
		cout <<"|                  3. OPEN FILE                |\n";
		cout <<"|                  4. EXIT                     |\n";
		cout <<"|                                              |\n";
		cout <<"+----------------------------------------------+\n";
		cout <<"Lua chon cua ban: ";
		cin >> Luachon1;	
		cin.ignore();
		system("cls");
        switch (Luachon1) {
            case 1:
                do {
                    // Menu 2
                    cout << " BAN DANG O MENU THUC HIEN \n";
       				cout << "*************************oo0oo**************************\n";
        			cout << "**  1. Nhap sinh vien.                                **\n";
        			cout << "**  2. Xem danh sach sinh vien.                       **\n";
        			cout << "**  3. Sap xep danh sach sinh vien.                   **\n";
        			cout << "**  4. Thay doi thong tin sinh vien.                  **\n";
        			cout << "**  5. Xoa danh sach.                                 **\n";
        			cout << "**  6. Tim kiem sinh vien trong danh sach.            **\n";
        			cout << "**  7. Thong ke.                                      **\n";
        			cout << "**  0. Thoat                                          **\n";
        			cout << "********************************************************\n";
        			cout << " Lua chon cua ban:  ";
                    cin >> Luachon2;
                    cin.ignore();
                    system("cls");

                   		 switch (Luachon2) {
                        case 1:
                            // Nhap sinh vien
                            for (int i = 0; i < n; i++) {
                            cout<<" Nhap so luong sinh vien: \n";cin>> Nhapsoluongsinhvien;
                            cout<<"\n";cin>>endl;
                            cout <<" Nhap thong tin sinh vien: \n ";cin>>Nhapthongtinsinhvien;
                            cout <<" Nhap MSSV:  \n";cin>>nhapmssv;
                            cout <<" Nhap ho va ten: \n ";cin>>nhaphovaten;
                            cout <<" Nhap gioi tinh: \n";cin>>gioitinh;
                            cout <<" Nhap tuoi: \n";cin>>Nhaptuoi;
                            cout <<" Nhap nghanh hoc: \n";cin>>nhapnghanhhoc;
                            cout <<" Nhap Khoa hoc: \n";cin>>nhapkhoahoc;
                            cout <<" \n";cin>>endl;
                            cout <<" Nhap thong tin cac mon\n";cin>>nhapthongtincacmon;
                            cout <<" Nhap diem mon tin1: \n";cin>>nhapdiemmontin1;
                            cout <<" Nhap diem mon ha1: \n";cin>>nhapdiemmonha1;
                            cout <<" Nhap diem mon tthcm: \n";cin>>nhapdiemmontthcm;
                            cout <<" Nhap diem mon sql: \n";cin>>nhapdiemmonsql;
                            cout <<" Nhap diem mon vb: \n";cin>>nhapdiemmonvb;
                            cout << endl;
                            break;
                        case 2:// Xem danh sach sinh vien
                             cout << "Danh sach sinh vien:\n";
   							 cout << "+=============+=====================================+=============+=======+============+==========+===========+==========+============+==========+========+========+==========+\n";
 							 cout << "|     MSSV    |            Ho va Ten                |   Gioi tinh | Tuoi  | Nghanh hoc | Khoa hoc | Diem Tin1 | Diem Ha1 | Diem Tthcm | Diem Sql | Diem Vb| DiemTB | Xep loai |\n";
   							 cout << "+=============+=====================================+=============+=======+============+==========+===========+==========+============+==========+========+========+==========+\n";
 							 for (int i = 0; i < n; i++) {
        					 dsSV[i].diemTB = (float)(dsSV[i].diemtin1 + dsSV[i].diemha1 + dsSV[i].diemtthcm + dsSV[i].diemsql + dsSV[i].diemvb) / 5;
            				 cout << "| " << left << setw(12) << dsSV[i].MSSV << "| ";
            				 cout << left << setw(18) << dsSV[i].hovaten << "| ";
          					 cout << left << setw(9) << dsSV[i].gioitinh << "| ";
            				 cout << left << setw(7) << dsSV[i].tuoi << "| ";
           					 cout << left << setw(20) << dsSV[i].nghanh << "| ";
             				 cout << left << setw(7) << dsSV[i].khoa << "| ";
            				 cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diemtin1 << "| ";
            				 cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diemha1 << "| ";
            				 cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diemtthcm<< "| ";
            				 cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diemsql << "| ";
            				 cout << left << setw(8) << fixed << setprecision(1) << dsSV[i].diemvb << "| ";
            				 cout << left << setw(7) << fixed << setprecision(1) << dsSV[i].diemTB << "| ";
              				if (dsSV[i].diemTB>=9){
                		 	 cout << left << setw(9) <<"Xuat Sac" << "|" << endl;
							 }
							else if (dsSV[i].diemTB >= 8) {
                   			 cout << left << setw(9) << "Gioi" << "|" << endl;
              				 }
               			    else if (dsSV[i].diemTB >= 7) {
                             cout << left << setw(9) << "Kha" << "|" << endl;
                             }
                            else if (dsSV[i].diemTB >= 5.5) {
                             cout << left << setw(9) << "Trung Binh" << "|" << endl;
                             }
                            else {
                             cout << left << setw(9) << "Yeu" << "|" << endl;
                              }
                
                             }
							 cout << "+=============+=====================================+=============+=======+============+==========+===========+==========+============+==========+========+========+==========+\n";
                             } 
    
                            break;
                        case 3:
                            // Sap xep danh sach sinh vien
                         for (int j = i + 1; j < n; j++) {
                         if (dsSV[i].diemTB > dsSV[j].diemTB) {
            			 SinhVien temp = dsSV[i];
             		     dsSV[i] = dsSV[j];
              			 dsSV[j] = temp;
           
         				   }
     					}
                            break;   
						case 4:
						// Thay doi thong tin sinh vien	 				
    					vector<SinhVien> dsSV; 
  						  // Thêm sinh viên vào danh sach
 						   SinhVien sv1 = {"k", l};
 						   dsSV.push_back(sv1);
 						   SinhVien sv2 = {"M", h};
  						   dsSV.push_back(sv2);
   						 // In ra danh sach sinh vien
    					   cout << "Danh sach sinh vien:\n";
   						   for (int i = 0; i < dsSV.size(); i++) {
      					   cout << "Sinh vien thu " << i+1 << endl;
      					   printSinhVien(dsSV[i]);
   						 }
					  // Sua thong tin sinh vien
    					dsSV[0].age = l; 
 		  			 // In ra danh sach sinh vien sau khi sua
   					  	 cout << "\nDanh sach sinh vien sau khi sua:\n";
  						  for (int i = 0; i < dsSV.size(); i++) {
      					  cout << "Sinh vien thu " << i+1 << endl;
      					  printSinhVien(dsSV[i]);
  						  }
  						   break;
						case 5:
						void xoaSinhVien(SinhVien danhSachSV[], int& soLuongSV, string tenSV) {
  						  int index = timKiemSinhVien(danhSachSV, soLuongSV, tenSV);
    					if (index != -1) {
       					 // Dich chuyen cac phan tu phia sau ve truoc
      					  for (int i = index; i < soLuongSV-1; i++) {
        				    danhSachSV[i] = danhSachSV[i+1];
      					  }
      					  // Giam so luong sinh vien di 1
     					   soLuongSV--;
     					   cout << " Xoa sinh vien thanh cong! " << tenSV << endl;
   						 } else {
     					   cout << "Khong tim thay sinh vien co ten. Vui long kiem tra lai! " << tenSV << endl;
   						 }
						}
      	    			 break;
      					case 6:// Tim kiem sinh vien trong danh sach				    
   						// Nhap ten sinh vien can tim kiem
   						  cout << "Nhap ten sinh vien can tim: ";
  						  getline(cin, tenSV);
   						 bool timThay = false;
   						 // Duyet qua tung sinh vien trong danh sach de tim kiem
   						 for (int i = 0; i < 5; i++) {
   					     if (danhSachSV[i].ten == tenSV) {
      				      cout << "MSSV: " << danhSachSV[i].mssv << endl;
      				      cout << "Hoten: " << danhSachSV[i].hoten << endl;
     				       cout <<"Nganh: " << danhSachSV[i].nghanh << endl;
     				       timThay = true;
        		   		 break;
     					   }
 					   }
  						  if (!timThay) {
  					      cout << "Khong tim thay sinh vien co ten " << tenSV << endl;
  						  }
      					 break;	
      					case 7;// Thong ke danh sach sinh vien
						   cout<<" Chuc nang cua chuong trinh thong ke \n";
						   cout<<" +-------------------------------------+";
						   cout<<" +                                     +" ;
						   cout<<" +     1: Thong ke theo gioi tinh      +";
						   cout<<""                       
                        case 0:
                            // Back to menu 1
                            cout<< " Tro lai Menu chinh!"
                            return 0;
                        default:
                            cout << "Lua chon khong phu hop. Vui long kiem tra lai!\n";
                            break;
    return 0;
}
