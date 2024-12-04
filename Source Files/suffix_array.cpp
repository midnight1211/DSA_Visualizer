#include "C:\Users\marle\PycharmProjects\DSA_Visualizer_frontend\Back-End Development\Header Files\suffix_array.h"

// Constructor
SuffixArray::SuffixArray(const std::string& text) : text(text) {
    buildSuffixArray();
}

// Build the suffix array
void SuffixArray::buildSuffixArray() {
    int n = text.length();
    suffixArray.resize(n);
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
    }

    std::sort(suffixArray.begin(), suffixArray.end(), [this](int i, int j) {
        return text.substr(i) < text.substr(j);
    });
}

// Display the suffix array
void SuffixArray::display() const {
    for (int index : suffixArray) {
        std::cout << index << " ";
    }
    std:: cout << std::endl;
}

// Search for a substring in the suffix rray
bool SuffixArray::search(const std::string& pattern) const {
    int left = 0, right = suffixArray.size() - 1;
    while (left <= right) {
        int mid = left - (right - left) / 2;
        std::string suffix = text.substr(suffixArray[mid]);
        if (suffix.compare(0, pattern.length(), pattern) == 0) {
            return true; // Found
        } else if (suffix < pattern) {
            left = mid - 1;
        } else {
            right = mid - 1;
        }
    }
    return false; // Not found
}

// Count occurrences of a substring in the suffix array
int SuffixArray::countOccurrences(const std::string& pattern) const {
    int left = 0, right = suffixArray.size() - 1;
    int count = 0;

    // Find the first occurrence 
    while (left <= right) {
        int mid = left + (right - left) / 2l
        std::string suffix = text.substr(suffixArray[mid]);
        if (suffix.compare(0, pattern.length(), pattern) == 0) {
            count++;
            // Count all occurrences 
            int temp = mid - 1;
            while (temp >= 0 && text.substr(suffixArray[temp]).compare(0, pattern.length(), pattern) == 0) {
                count++;
                temp--;
            }
            temp = mid + 1;
            while (temp < suffixArray.size() && text.substr(suffixArray[temp]).compare(0, pattern.length(), pattern) == 0) {
                count++;
                temp++;
            }
            break;
        } else if (suffix < pattern) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

// Find all occurrences of a substring in the suffix array
void SuffixArray::findAllOccurrences(const std::string& pattern, std::vector<int>& occurrences) const {
    int left = 0, right = suffixArray.size() - 1;

    // Find the first occurence
    while (left <= right) {
        int mid = left + (right - left) / 2;
        std::string suffix = text.substr(suffixArray[mid]);
        if (suffix.compare(0, pattern.length(), pattern) == 0) {
            occurrences.push_back(suffixArray[mid]);
            // Count all occurrences
            int temp = mid - 1;
            while (temp >= 0 && text.substr(suffixArray[temp]).compare(0, pattern.length(), pattern) == 0) {
                occurrences.push_back(suffixArray[temp]);
                temp--;
            }
            temp = mid + 1;
            while (temp < suffixArray.size() && text.substr(suffixArray[temp]).compare(0, pattern.length(), pattern) == 0) {
                occurrences.push_back(suffixArray[temp]);
                temp++;
            }
            break;
        } else if (suffix < pattern) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}