#include <iostream>
using namespace std;

// Hàm hoán đổi 2 phần tử
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Sắp xếp đổi chỗ trực tiếp (Interchange Sort)
void interchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Sắp xếp chọn trực tiếp (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Sắp xếp chèn trực tiếp (Insertion Sort)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr1[n], arr2[n], arr3[n], arr4[n];
    copy(arr, arr + n, arr1);
    copy(arr, arr + n, arr2);
    copy(arr, arr + n, arr3);
    copy(arr, arr + n, arr4);

    cout << "Mang ban dau: ";
    printArray(arr, n);

    interchangeSort(arr1, n);
    cout << "Sau Interchange Sort: ";
    printArray(arr1, n);

    selectionSort(arr2, n);
    cout << "Sau Selection Sort: ";
    printArray(arr2, n);

    insertionSort(arr3, n);
    cout << "Sau Insertion Sort: ";
    printArray(arr3, n);

    bubbleSort(arr4, n);
    cout << "Sau Bubble Sort: ";
    printArray(arr4, n);

    return 0;
}
