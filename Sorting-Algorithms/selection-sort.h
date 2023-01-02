#pragma once

#include <vector>
#include <array>

// Iterator

// Sort by iterators (begin and end) and custom compare function
template <typename Iterator, typename Compare>
void selectionSort(Iterator begin, Iterator end, Compare cmp) {
    for (; begin != end; ++begin) {
        auto min = std::min_element(begin, end, cmp);
        if (cmp(*min, *begin)) {
            std::swap(*min, *begin);
        }
    }
}

// Sort by iterators (begin and end)
// Sort by std::less function
template <typename Iterator>
void selectionSort(Iterator begin, Iterator end) {
    selectionSort(begin, end, std::less<>());
}

// Sort by iterator begin and size of array
template <typename Iterator>
void selectionSort(Iterator begin, int size) {
    selectionSort(begin, begin + size, std::less<>());
}

// Vector

// Sort vector by custom compare function
template <typename T, typename Compare>
void selectionSort(std::vector<T>& vec, Compare cmp) {
    selectionSort(vec.begin(), vec.end(), cmp);
}

// Sort vector using std::less
template <typename T>
void selectionSort(std::vector<T>& vec) {
    selectionSort(vec, std::less<>());
}

// Array

// Sort array by custom compare function
template <typename T, std::size_t SIZE, typename Compare>
void selectionSort(std::array<T, SIZE>& arr, Compare cmp) {
    selectionSort(arr.begin(), arr.end(), cmp);
}

// Sort array using std::less
template <typename T, std::size_t SIZE>
void selectionSort(std::array<T, SIZE>& arr) {
    selectionSort(arr, std::less<>());
}