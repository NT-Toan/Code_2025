#include <iostream>

using namespace std;

// Định nghĩa cấu trúc dữ liệu
struct Term {
    double coefficient; // Hệ số (số thực)
    int exponent;       // Bậc (số nguyên từ 0 đến 100)
};

// Hàm hoán đổi hai phần tử
void swap(Term &a, Term &b) {
    Term temp = a;
    a = b;
    b = temp;
}

// Sắp xếp dãy theo thứ tự tăng dần của bậc bằng Selection Sort
void selectionSort(Term *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].exponent < arr[minIdx].exponent) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Hàm nhập dữ liệu
void inputTerms(Term *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap he so va bac cua so hang thu " << i + 1 << ": ";
        cin >> arr[i].coefficient >> arr[i].exponent;
    }
}

// Hàm xuất dữ liệu
void printTerms(const Term *arr, int n) {
    cout << "Day so hang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i].coefficient << "x^" << arr[i].exponent;
        if (i < n - 1) cout << " + ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so luong so hang: ";
    cin >> n;

    // Cấp phát mảng động
    Term *terms = new Term[n];

    // Nhập và sắp xếp
    inputTerms(terms, n);
    selectionSort(terms, n);

    // Xuất kết quả
    printTerms(terms, n);

    // Giải phóng bộ nhớ
    delete[] terms;

    return 0;
}
