#include <iostream>
#include <vector>
#include <cmath>

int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int jumpSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();
    int jump = sqrt(n);
    int prev = 0;
    while (arr[std::min(jump, n) - 1] < target) {
        prev = jump;
        jump += sqrt(n);
        if (prev >= n) return -1;
    }
    while (arr[prev] < target) prev++;
    if (arr[prev] == target) return prev;
    return -1;
}

int exponentialSearch(const std::vector<int>& arr, int target) {
    if (arr[0] == target) return 0;
    int i = 1;
    while (i < arr.size() && arr[i] <= target) i *= 2;
    return binarySearch(std::vector<int>(arr.begin(), arr.begin() + std::min(i, (int)arr.size())), target);
}

int interpolationSearh(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int ternarySearch(const std::vector<int>& arr, int target, int left, int right) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;
        if (target < arr[mid1]) return ternarySearch(arr, target, left, mid1 - 1);
        else if (target > arr[mid2]) return ternarySearch(arr, target, mid2 + 1, right);
        else return ternarySearch(arr, target, mid1 + 1, mid2 - 1);
    }
    return -1;
}