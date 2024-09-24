#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string ho_ten;
    string ngay_sinh;
    string que_quan;

//ham khoi tao
public:
    Person(string ho_ten, string ngay_sinh, string que_quan)
        : ho_ten(ho_ten), ngay_sinh(ngay_sinh), que_quan(que_quan) {}

    void nhap_thong_tin() {
        cout << "Nhap ho ten: ";
        getline(cin, ho_ten);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngay_sinh);
        cout << "Nhap que quan: ";
        getline(cin, que_quan);
    }

    void xuat_thong_tin() {
        cout << "Ho ten: " << ho_ten << endl;
        cout << "Ngay sinh: " << ngay_sinh << endl;
        cout << "Que quan: " << que_quan << endl;
    }
};

class KySu : public Person {
private:
    string nganh_hoc;
    int nam_tot_nghiep;
    
//hàm khoi tao
public:
    KySu(string ho_ten, string ngay_sinh, string que_quan, string nganh_hoc, int nam_tot_nghiep)
        : Person(ho_ten, ngay_sinh, que_quan), nganh_hoc(nganh_hoc), nam_tot_nghiep(nam_tot_nghiep) {}

    void nhap_thong_tin() {
        Person::nhap_thong_tin();
        cout << "Nhap nganh hoc: ";
        getline(cin, nganh_hoc);
        cout << "Nhap nam tot nghiep: ";
        cin >> nam_tot_nghiep;
        cin.ignore(); 
    }

    void xuat_thong_tin() {
        Person::xuat_thong_tin();
        cout << "Nganh hoc: " << nganh_hoc << endl;
        cout << "Nam tot nghiep: " << nam_tot_nghiep << endl;
    }
	
	//get nam tot nghiep
    int getNamTotNghiep() {
        return nam_tot_nghiep;
    }
};

int main() {
    vector<KySu> danh_sach_kysu;

    int n;
    cout << "Nhap so luong ky su: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin ky su thu " << i + 1 << ":" << endl;
        KySu kysu("", "", "", "", 0);
        kysu.nhap_thong_tin();
        danh_sach_kysu.push_back(kysu);
    }
	
	cout << "--------------------------------" << endl;
    cout << "Danh sach ky su:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Ky su thu " << i + 1 << ":" << endl;
        danh_sach_kysu[i].xuat_thong_tin();
        cout << endl;
    }
    cout << "--------------------------------" << endl;

    // Tim ky su tot nghiep gan day nhat
    int nam_tot_nghiep_max = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (danh_sach_kysu[i].getNamTotNghiep() > nam_tot_nghiep_max) {
            nam_tot_nghiep_max = danh_sach_kysu[i].getNamTotNghiep();
            index = i;
        }
    }

    if (index != -1) {
        cout << "Thong tin ky su tot nghiep gan day nhat:" << endl;
        danh_sach_kysu[index].xuat_thong_tin();
    } else {
        cout << "Khong co ky su nao trong danh sach." << endl;
    }
	
    return 0;
}

