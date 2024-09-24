#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// nhap vao mang
void nhap(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << "nhap phan tu thu " << i + 1 << " cua mang: ";
        cin >> arr[i];
    }
}

//in ra mang
void in(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// nhap so phan tu
int nhapspt()
{
    int n;
    cout << "Nhap so phan tu cua mang (5 <= n <= 50): ";
    cin >> n;
    while (n < 5 || n > 50) {
        cout << "N khong hop le, moi nhap lai: ";
        cin >> n;
    }
    return n;
}

int themphantu(int arr[], int &n) {
    vector<int> v(arr, arr + n);
    cout << "Nhap phan tu can them vao mang: ";
	int x; 
	cin >>x;
    v.push_back(x);
    cout << "Mang sau khi them phan tu: ";
	for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
}


// tim so lon nhat
int max(int arr[], int n) {
    int max = arr[0]; 
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; 
        }
    }
    cout << "Phan tu lon nhat trong mang la: " << max << endl;
    return max;
}

//xoa ky tu 
void xoa(int arr[], int& n) {
	int x;
	cout <<"Nhap ky tu can xoa";
	cin>> x;
 for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
            return; 
        }
    }
    cout << "Khong tim thay so " << x << endl;
}

//sap xep
void sapxep(int arr[], int n) {
	int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    in(arr, n);
}

bool isnguyento(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

//tim so nguyen to
int nguyento(int arr[], int n)
{
    cout << "Cac so nguyen to trong mang la:\n";
    for (int i = 0; i < n; i++) {
        if (isnguyento(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

//bien doi thanh 0 va 1 
void biendoi(int arr[], int n)
{
	for(int i =0; i<n; i++)
	{
		if(arr[i] > 0)
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		} 
	}
}

int tongchan(int arr[], int n)
{
	int sum = 0;
    for (int i = 1; i < n; i += 2) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    cout << "Tong cac so chan o vi tri le trong mang la: " << sum << endl;
}


// dem so xuat hien trong mang
int demso(int arr[],int n)
{
	int x = 0;
	int so;
	cout << "nhap so can dem";
	cin >> so;
	for (int i = 0; i < n; i++) 
	{
        if(arr[i] == so)
        {
        	x++;
        }
    } 
	cout << "So ky tu xuat hien trong mang : " << x << endl; 
    return x;
}

void timK(int arr[], int n)
{
	int k;
	cout << "Nhap so K: ";
    cin >> k;
    cout << "Vi tri cua K trong mang la:";
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            cout << i << " ";
        }
    }
    cout << endl;
}


int main() {
    int n = nhapspt();
    int arr[n];
    int luachon;	
	do {
		cout << "===================== MENU =====================" << endl;
        cout << "1. Nhap so phan tu mang" << endl;
        cout << "2. Hien thi mang" << endl;
        cout << "3. Tim so lon nhat" << endl;
        cout << "4. Xoa phan tu trong mang" << endl;
        cout << "5. Sap xep phan tu cua mang" << endl;
        cout << "6. Bien Doi" << endl;
        cout << "7. Them phan tu vao mang" << endl;
        cout << "8. Tim so nguyen to" << endl;
        cout << "9. Dem gia tri so xuat hien" << endl;
        cout << "10. Tong cac so chan" << endl;
        cout << "11. Nhap Va tim so K" << endl;
        cout << "0. Thoat" << endl;
        cout << "================================================" << endl;
        cout << "Nhap lua chon cua ban: ";
		cin >> luachon;
		cin.ignore();
		system("cls");
		switch (luachon) {
			case 1:
			{
				nhap(arr, n);
				break;
			}
			case 2: 
			{
				in(arr, n);
			 	break;
			}
			case 3:
			{
				max(arr,n);
				break;
			}
			case 4:
			{
				xoa(arr,  n);
				break;
			}
			case 5:
			{
				sapxep(arr, n);
				break;
			}
			case 6:
			{
				biendoi(arr, n);
				break;
			}
			case 7:
			{
				themphantu(arr, n);
				break;
			}
			case 8:
			{
				nguyento(arr, n);
				break;
			}	
			case 9:
			{
				demso(arr, n);
				break;
			}
			case 10:
			{
				tongchan(arr, n);
				break;
			}
			case 11:
			{
				timK(arr, n);
				break;	
			}
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

