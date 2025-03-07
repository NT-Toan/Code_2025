#include <iostream>
#include <algorithm>

using namespace std;

// Hàm tính tổng các chữ số của một số
int tongChuSo(int num) {
    int tong = 0;
    while (num != 0) {
        tong += num % 10;
        num /= 10;
    }
    return tong;
}

// Hàm kiểm tra một số có phải số nguyên tố hay không
bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm vị trí của k phần tử lớn nhất
void timKPhanTuLonNhat(int arr[], int n, int k) {
    int* index = new int[n];
    for (int i = 0; i < n; i++) index[i] = i;

    sort(index, index + n, [&](int a, int b) {
        return arr[a] > arr[b]; // Sắp xếp giảm dần theo giá trị
    });

    cout << "Vi tri " << k << " phan tu lon nhat: ";
    for (int i = 0; i < k; i++) {
        cout << index[i] << " ";
    }
    cout << endl;
    delete[] index;
}

// Hàm sắp xếp theo tổng chữ số
void sapXepTheoTongChuSo(int arr[], int n) {
    sort(arr, arr + n, [&](int a, int b) {
        return tongChuSo(a) < tongChuSo(b);
    });
}

// Hàm xóa các số nguyên tố trong mảng
int xoaSoNguyenTo(int arr[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (!laSoNguyenTo(arr[i])) {
            arr[j++] = arr[i];
        }
    }
    return j; // Trả về số phần tử mới sau khi xóa
}

int main() {
    int n, k;
    cout << "Nhap so phan tu: ";
    cin >> n;
    int* arr = new int[n];

    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Nhap k: ";
    cin >> k;

    // a. Tìm vị trí k phần tử lớn nhất
    timKPhanTuLonNhat(arr, n, k);

    // b. Sắp xếp theo tổng chữ số
    sapXepTheoTongChuSo(arr, n);
    cout << "Day sau khi sap xep theo tong chu so: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // c. Xóa số nguyên tố
    n = xoaSoNguyenTo(arr, n);
    cout << "Day sau khi xoa cac so nguyen to: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
