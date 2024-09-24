#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>


int dem=0;
using namespace std;

struct sinhvien
{
    int mssv;
    char hoten[50];
    char gioitinh[10];
    int tuoi;
    char nganh[15];
    int khoahoc;
    float diemtin1;
    float diemha1;
    float diemsql;

    void Nhap()
    {
        do
        {
        	cout <<"Nhap ma so sinh vien: ";
	        cin >>mssv;
	        
			cout <<"Nhap ho ten sinh vien: ";
	        fflush(stdin);
	        gets(hoten);
	        
			cout <<"Nhap gioi tinh (nam/nu): ";
	        fflush(stdin);
	        gets(gioitinh);
	        
			cout<<"Tuoi: ";        
	        cin>>tuoi;

			cout<<"Nganh: ";
	        fflush(stdin);
	        gets(nganh);
	        
			cout<<"Khoa hoc: ";
	        cin>>khoahoc;
            
			cout <<"Nhap diem tin1: ";
            cin >>diemtin1;
            
			cout <<"Nhap diem ha1: ";
            cin >>diemha1;
            
			cout <<"Nhap diem SQL: ";
            cin >>diemsql;
            if(diemtin1<0||diemha1<0||diemsql<0||diemtin1>10||diemha1>10||diemsql>10|| tuoi <18 || tuoi>22 || khoahoc <0 || mssv < 0 )
                cout <<"Moi ban nhap lai!"<<endl;
        }while(diemtin1<0||diemha1<0||diemsql<0||diemtin1>10||diemha1>10||diemsql>10|| tuoi <18 || tuoi>22 || khoahoc <0 || mssv < 0 );
    }

    float DiemTB()
    {
        return (diemtin1+diemha1+diemsql)/3;
    }

    string HocLuc()
    {
        string hl;
        if(DiemTB()>=9)
            hl = "Xuat sac";
        else if(DiemTB()>=8)
            hl = "Gioi";
        else if(DiemTB()>=6.5)
            hl = "Kha";
        else if(DiemTB()>=5)
            hl = "Trung binh";
        else hl = "Yeu";
        return hl;
    }
    void Xuat()
    {
        cout <<setw(2) <<++dem<<setw(8)<<mssv<<setw(30)<<hoten<<setw(15)<<gioitinh<<setw(12)<<tuoi<<setw(12)<<nganh<<setw(12)<<khoahoc<<setw(12)<<diemtin1<<setw(12);
        cout <<setw(12)<<diemha1<<setw(12)<<diemsql<<setw(12)<<DiemTB()<<setw(12)<<HocLuc()<<endl;
    }
};

typedef sinhvien SV;

void NhapSV(SV sv[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout <<"Nhap thong tin sinh vien thu "<<i+1<<": "<<endl;
        sv[i].Nhap();
    }
}

void TieuDe()
{
    cout<<setw(2)<<"STT"<<setw(8)<<"MSSV"<<setw(29)<<"Ho Ten"<<setw(15)<<"Gioi Tinh"<<setw(12)<<"Tuoi"<<setw(12)<<"Nganh"<<setw(12)<<"KhoaHoc"<<setw(12)<<"Diem Tin1"<<setw(12);
    cout <<setw(12)<<"Diem Ha1"<<setw(12)<<"Diem Sql"<<setw(12)<<"Diem TB"<<setw(12)<<"Hoc luc"<<endl;
}

void XuatSV(SV *sv, int n)
{
    cout <<"Danh sach sinh vien: "<<endl;
    TieuDe();
    for(int i=0;i<n;i++)
    {
        sv[i].Xuat();
    }
}

// ham them 1 sinh vien
void ThemSV(SV sv[], int &n)
{
   int dem = 0;
    n++;
    cout <<"Nhap thong tin sinh vien can them: "<<endl;
    sv[n-1].Nhap();
}
// hàm xóa 1 sinh viên
void XoaSV(SV *sv, int &n)
{
    int so;
    int dem = 0;
    cout <<"Nhap ma so sinh vien cua sinh vien can xoa: ";
    cin >>so;
    for(int i=0; i<n;i++)
    {
        if(sv[i].mssv == so)
        {
           for(int j=i;j<n;j++)
                sv[j] = sv[j+1];
            dem++;
        }
    }
    if(dem == 0)
        cout <<"Ban da nhap ma so sinh vien sai!"<<endl;
    else n--;
}

// hàm c?p nh?t thông tinh sinh viên

void CapNhat(SV *sv, int n)
{
    int so;
    int res = 0;
    cout <<"Nhap ma so sinh vien cua sinh vien can cap nhat: ";
    cin >>so;
    for(int i=0; i<n;i++)
    {
        if(sv[i].mssv == so)
        {
           sv[i].Nhap();
           res++;
        }
    }
    if(res == 0)
        cout <<"Ban da nhap ma so sinh vien sai!"<<endl;
}

// hàm tr? v? di?m cao nh?t

float Max(SV *sv, int n)
{
    float max = sv[0].DiemTB();
    for(int i=1;i<n;i++)
    {
        if(sv[i].DiemTB() >max)
        {
            max = sv[i].DiemTB();
        }
    }
    return max;
}
// ham in ra sinh vien co diem trung binh cao nhat
void InMax(SV *sv, int n)
{
    dem = 0;
    cout <<"Thong tin nhung sinh vien co diem cao nhat: "<<endl;
    TieuDe();
    for(int i=0;i<n;i++)
    {
        if(sv[i].DiemTB() == Max(sv, n) )
        {
            sv[i].Xuat();
        }
    }
}
// hàm tr? v? di?m min
float Min(SV *sv, int n)
{
    float min = sv[0].DiemTB();
    for(int i=1;i<n;i++)
    {
        if(sv[i].DiemTB() <min)
        {
            min= sv[i].DiemTB();
        }
    }
    return min;
}

// ham in ra sinh vien co diem trung binh thap nhat
void InMin(SV *sv, int n)
{
    dem = 0;
    cout <<"Thong tin nhung sinh vien co diem thap nhat: "<<endl;
    TieuDe();
    for(int i=0;i<n;i++)
    {
        if(sv[i].DiemTB() == Min(sv, n) )
        {
            sv[i].Xuat();
        }
    }
}

// hàm s?p x?p sinh viên theo mã s? sinh viên
void SapXepMSSV(SV *sv, int n)
{
    dem=0;    
    TieuDe();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(sv[i].mssv > sv[j].mssv )
            {
                swap(sv[i], sv[j]);
            }
        }
    }
    XuatSV(sv, n);
}



// ham nhap so luong sinh vien
void NhapSL(int &n)
{
    do
    {
        cout <<"Nhap so luong sinh vien: ";
        cin >>n;
        if(n<0)
            cout <<"Moi ban nhap lai!"<<endl;
    }while(n<0);
}

// tim kiem sinh vien thong qua ma so sinh vien
void TimKiem(SV *sv, int n)
{
    int ms,res=0;
    cout <<"Nhap ma so cua sinh vien can tim kiem: ";
    cin >>ms;
    for(int i=0;i<n;i++)
    {
        if(sv[i].mssv == ms)
        {
            sv[i].Xuat();
            res++;
        }
    }
    if(res == 0)
        cout <<"Ma so sinh vien khong co trong danh sach!"<<endl;
}

// s?p x?p danh sách h?c sinh theo abc
void SapxepTen(SV *sv,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		   if(strcmp(sv[i].hoten,sv[j].hoten)>0)
		  {
              swap(sv[i], sv[j]);
		  }
		}
	} 
    XuatSV(sv, n);
}
void Menu(){
    cout<<"+===========================================================================================+\n";
    cout<<"+                                              MENU                                         +\n";
    cout<<"+===========================================================================================+\n";
    cout<<"|         1. Nhap danh sach sinh vien                                                       |\n";
    cout<<"|         2. Hien thi danh sach sinh vien                                                   |\n";
    cout<<"|         3. Them thong tin 1 sinh vien                                                     |\n";
    cout<<"|         4. Xoa thong tin 1 sinh vien                                                      |\n";
    cout<<"|         5. Hien thi thong tin nhung sinh vien co diem trung binh cao nhat                 |\n";
    cout<<"|         6. Hien thi thong tin nhung sinh vien co diem trung binh thap nhat                |\n"; 
    cout<<"|         7. Tim sinh vien boi ma so sinh vien                                              |\n"; 
    cout<<"|         8. Sap xep danh sach sinh vien theo ma so sinh vien tang dan                      |\n"; 
    cout<<"|         9. Sap xep danh sach sinh vien theo ten                                           |\n";
    cout<<"|         0. Thoat                                                                          |\n";
    cout<<"+===========================================================================================+\n";
	
}

void Press()
{
    system("pause");
    system("cls");
}


int main() {
    int n = 0;
    char chon;
    int luachon;
    SV* sv;
    sv = new SV[n];
    int Choice;

    cout << "+=========================================================+\n";
    cout << "+     CHAO MUNG DEN VOI CHUONG TRINH QUAN LI SINH VIEN    +\n";
    cout << "+=========================================================+\n";
    cout << "|                       1. MENU                           |\n";
    cout << "|                       2. OPEN FILE                      |\n";
    cout << "|                       3. SAVE FILE                      |\n";
    cout << "|                       4. EXIT                           |\n";
    cout << "+=========================================================+\n";
    cout << "\n";
    cout << "MOI BAN NHAP LUA CHON: ";
    cin >> Choice;
    system("cls");

    switch (Choice) {
        // CH?N M?C 1: MENU
        case 1: {
            do {
                Menu();
                cout << "Moi ban nhap lua chon: ";
                cin >> luachon;
                switch (luachon) {
                    case 1:
                        NhapSL(n);
                        NhapSV(sv, n);
                        Press();
                        break;
                    case 2:
                        XuatSV(sv, n);
                        Press();
                        break;
                    case 3:
                        ThemSV(sv, n);
                        Press();
                        break;
                    case 4:
                        XoaSV(sv, n);
                        Press();
                        break;
                    case 5:
                        InMax(sv, n);
                        Press();
                        break;
                    case 6:
                        InMin(sv, n);
                        Press();
                        break;
                    case 7:
                        TimKiem(sv, n);
                        Press();
                        break;
                    case 8:
                        SapXepMSSV(sv, n);
                        Press();
                        break;
                    case 9:
                        SapxepTen(sv, n);
                        Press();
                        break;
                    default:
                        cout << "Ban da nhap sai lua chon!" << endl;
                        Press();
                        break;
                }
                cout << "Ban co muon lua chon tiep khong (y/n): ";
                cin >> chon;
                if (chon == 'n')
                    cout << "Tam biet ban\n";
            } while (chon == 'y' || chon == 'Y');

            delete[] sv;
            break;
        }

        // CH?N M?C 2: OPEN FILE
        case 2: {
            // Code for opening a file
            break;
        }

        // CH?N M?C 3: SAVE FILE
        case 3: {
            // Code for saving a file
            break;
        }

        // CH?N M?C 4: EXIT
        case 4: {
            // Code for exiting the program
            break;
        }

        // CH?N M?C KHÔNG N?M TRONG 4 M?C
        default: {
            // Code for handling invalid choice
            break;
        }
    }

    return 0;
}
//Please note that the revised code assumes that you have defined the missing functions (Menu(), Press(), NhapSL(), NhapSV(), etc.) elsewhere in your code or have placeholders for them.








