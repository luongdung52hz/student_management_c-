#include <iostream>
using namespace std;

void Nhap(int n[], int k){
    for (int i = 1; i <= k; i++){
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> n[i];
    }
}

void Xuat(int n[], int k){
    for (int i = 1; i <= k; i++){
        cout << n[i] << " ";
    }
    cout << endl;
}

int Timx(int n[], int k, int x){
    int dem = 0;
    for (int i = 1; i <= k; i++){
        if (n[i] == x){
            dem++;
        }
    }
    return dem;
}

void SapXepTangDan(int n[], int k){
    for (int i = 1; i < k; i++){
        int t = n[i];
        int j = i - 1;
        while (j >= 0 && n[j] > t){
            n[j + 1] = n[j];
            j = j - 1;
        }
        n[j + 1] = t;
    }
    cout << "Mang sap xep tang dan: ";
    for (int i = 0; i < k; i++){
        cout << n[i] << " ";
    }
    cout << endl;
}

int LonNhat(int n[], int k){
    int m = n[1];
    for (int i = 2; i <= k; i++){
        if (n[i] > m){
            m = n[i];
        }
    }
    return m;
}

int Chiahetcho3(int n[], int k){
    int d = 0;
    for (int i = 1; i <= k; i++){
        if (n[i] % 3 == 0){
            cout << i << " ";
            d++;
        }
    }
    cout << endl;
    return d;
}
int DemSoChan(int n[], int k){
    int dem = 0;
    for (int i = 1; i <= k; i++){
        if (n[i] % 2 == 0){
            dem++;
        }
    }
    return dem;
}

int DemSoLe(int n[], int k){
    int dem = 0;
    for (int i = 1; i <= k; i++){
        if (n[i] % 2 != 0){
            dem++;
        }
    }
    return dem;
}


int main(){
    int n[100], k, x;

    cout << "Nhap so phan tu: ";
    cin >> k;
    Nhap(n, k);
    Xuat(n, k);
    cout << "-So lon nhat la: " << LonNhat(n, k) << endl;
    cout << "-So chia het cho 3 la: " << Chiahetcho3(n, k) << endl;
    SapXepTangDan(n, k);
    cout << "Nhap so x can tim: ";
    cin >> x;
    cout << "-So lan xuat hien cua " << x << " la: " << Timx(n, k, x) << endl;
    cout << "-So luong so chan la " << DemSoChan(n, k) <<endl;
    cout << "-So luong so le la " << DemSoLe(n, k) <<endl;
    return 0;
}
