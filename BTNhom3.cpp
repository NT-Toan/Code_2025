#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Hàm tạo mảng ngẫu nhiên
void generateArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Giá trị ngẫu nhiên từ 0 đến 99
    }
}

// Hàm in mảng
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort (Sắp xếp nổi bọt)
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Nếu phần tử trước lớn hơn phần tử sau
                swap(arr[j], arr[j + 1]); // Đổi chỗ hai phần tử
            }
        }
    }
}

// Selection Sort (Sắp xếp chọn)
void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i; // Giả sử phần tử đầu tiên là nhỏ nhất
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j; // Tìm vị trí phần tử nhỏ nhất
            }
        }
        swap(arr[i], arr[minIdx]); // Đưa phần tử nhỏ nhất về đầu
    }
}

// Quick Sort (Sắp xếp nhanh)
int partition(int *arr, int left, int right) {
    int pivot = arr[right]; // Chọn phần tử cuối làm chốt
    int i = left - 1; // Vị trí phần tử nhỏ hơn chốt
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) { // Nếu phần tử nhỏ hơn chốt
            i++;
            swap(arr[i], arr[j]); // Đổi chỗ
        }
    }
    swap(arr[i + 1], arr[right]); // Đưa chốt về đúng vị trí
    return i + 1;
}

void quickSort(int *arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1); // Sắp xếp bên trái chốt
        quickSort(arr, pivotIndex + 1, right); // Sắp xếp bên phải chốt
    }
}

// Merge Sort (Sắp xếp trộn)
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    srand(time(0)); // Sinh số ngẫu nhiên

    int n;
    cout << "Nhập số phần tử mảng: ";
    cin >> n;

    int *arr = new int[n]; // Cấp phát mảng động
    generateArray(arr, n);

    cout << "Mảng ban đầu: ";
    printArray(arr, n);

    int *arrBubble = new int[n];
    int *arrSelection = new int[n];
    int *arrQuick = new int[n];
    int *arrMerge = new int[n];

    // Sao chép dữ liệu để mỗi thuật toán chạy độc lập
    for (int i = 0; i < n; i++) {
        arrBubble[i] = arr[i];
        arrSelection[i] = arr[i];
        arrQuick[i] = arr[i];
        arrMerge[i] = arr[i];
    }

    // Thử nghiệm từng thuật toán
    bubbleSort(arrBubble, n);
    cout << "Bubble Sort: ";
    printArray(arrBubble, n);

    selectionSort(arrSelection, n);
    cout << "Selection Sort: ";
    printArray(arrSelection, n);

    quickSort(arrQuick, 0, n - 1);
    cout << "Quick Sort: ";
    printArray(arrQuick, n);

    mergeSort(arrMerge, 0, n - 1);
    cout << "Merge Sort: ";
    printArray(arrMerge, n);

    // Giải phóng bộ nhớ động
    delete[] arr;
    delete[] arrBubble;
    delete[] arrSelection;
    delete[] arrQuick;
    delete[] arrMerge;

    return 0;
}
