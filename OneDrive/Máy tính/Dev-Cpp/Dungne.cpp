#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string tenGoi;
    float giaBan;

public:
   void NhapDuLieu() {
        cout << "Nhap ten goi: ";
        cin.ignore();
        getline(cin, tenGoi);
        cout << "Nhap gia ban: ";
        cin >> giaBan;
    }

   void HienThiDuLieu() {
   
        cout << "Ten goi: " << tenGoi << endl;
        cout << "Gia ban: " << giaBan <<"d"<< endl;
    }
};

class Book : public Media {
private:
    int soTrang;
    string tacGia;

public:
    void NhapDuLieu() {
        Media::NhapDuLieu();
        cout << "Nhap so trang: ";
        cin >> soTrang;
        cin.ignore(); 
        cout << "Nhap tac gia: ";
        getline(cin, tacGia);
    }

    void HienThiDuLieu() {
        Media::HienThiDuLieu();
        cout << "So trang: " << soTrang << endl;
        cout << "Tac gia: " << tacGia << endl;
    }
};

class Video : public Media {
private:
    float thoiGianChay;

public:
    void NhapDuLieu() {
        Media::NhapDuLieu();
        cout << "Nhap thoi gian chay (phut): ";
        cin >> thoiGianChay;
    }

    void HienThiDuLieu() {
        Media::HienThiDuLieu();
        cout << "Thoi gian chay: " << thoiGianChay << " phut" << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    Media* danhSachMedia[n];

    for (int i = 0; i < n; i++) {
        int loaiMedia;
     
        cout << "Chon loai media (1- Book, 2- Video): ";
        cin >> loaiMedia;
          
        if (loaiMedia == 1) {
            danhSachMedia[i] = new Book();
        } else if (loaiMedia == 2) {
            danhSachMedia[i] = new Video();
        } else {
            cout << "Loai media khong hop le." << endl;
         
        }

        danhSachMedia[i]->NhapDuLieu();
    } 

    for (int i = 0; i < n; i++) {
        danhSachMedia[i]->HienThiDuLieu();
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete danhSachMedia[i];
    }

    return 0;
}

