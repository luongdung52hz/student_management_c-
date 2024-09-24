#include <iostream>

int main() {
    const int DAN_SO_HIEN_TAI = 5000000;
    double ty_le_tang_dan_so = 0.02;
    int so_nam;
    std::cout << "Nhap so nam can tinh: ";
    std::cin >> so_nam;
    double dan_so_sau_n_nam = DAN_SO_HIEN_TAI;
    for (int i = 1; i <= so_nam; i++) {
        dan_so_sau_n_nam += dan_so_sau_n_nam * ty_le_tang_dan_so;
    }
    std::cout << "Dan so cua thanh pho sau " << so_nam << " nam la: " << dan_so_sau_n_nam << " nguoi" << std::endl;
    return 0;
}
