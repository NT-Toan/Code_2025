#include <iostream>
using namespace std;

// Hàm hoán đổi hai phần tử
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// **1. Sắp xếp nhanh (Quick Sort)**
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// **2. Sắp xếp trộn (Merge Sort)**
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// **3. Sắp xếp cây (Heap Sort)**
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    int arr[] = {8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr1[n], arr2[n], arr3[n];
    copy(arr, arr + n, arr1);
    copy(arr, arr + n, arr2);
    copy(arr, arr + n, arr3);

    cout << "Mang ban dau: ";
    printArray(arr, n);

    quickSort(arr1, 0, n - 1);
    cout << "Sau Quick Sort: ";
    printArray(arr1, n);

    mergeSort(arr2, 0, n - 1);
    cout << "Sau Merge Sort: ";
    printArray(arr2, n);

    heapSort(arr3, n);
    cout << "Sau Heap Sort: ";
    printArray(arr3, n);

    return 0;
}
