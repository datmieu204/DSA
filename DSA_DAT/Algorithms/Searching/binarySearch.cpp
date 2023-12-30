#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Nếu target nằm ở giữa mảng
        if (arr[mid] == target) {
            return mid;
        }

        // Nếu target nhỏ hơn giá trị ở vị trí mid, tìm kiếm bên trái
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // Nếu target lớn hơn giá trị ở vị trí mid, tìm kiếm bên phải
        else {
            left = mid + 1;
        }
    }

    // target không tồn tại trong mảng
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1) {
        cout << "Khong tim thay phan tu " << target << " trong mang." << endl;
    } else {
        cout << "Phan tu " << target << " duoc tim thay tai vi tri " << result << endl;
    }

    return 0;
}