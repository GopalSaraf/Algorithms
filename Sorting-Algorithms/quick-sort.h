#pragma once

#include <vector>
#include <array>

// Iterator

// Sort by iterators (begin and end) and custom compare function
template <typename Iterator, typename Compare>
void quickSort(Iterator begin, Iterator end, Compare cmp) {
    if (end <= begin) return;
    Iterator pivot = begin, middle = begin + 1;
    for (Iterator i = begin + 1; i < end; ++i) {
        if (cmp(*i, *pivot)) {
            std::swap(*i, *middle);
            ++middle;
        }
    }
    std::swap(*begin, *(middle - 1));
    quickSort(begin, middle - 1, cmp);
    quickSort(middle, end, cmp);
}

// Sort by iterators (begin and end)
// Sort by std::less function
template <typename Iterator>
void quickSort(Iterator begin, Iterator end) {
    quickSort(begin, end, std::less<>());
}

// Sort by iterator begin and size of array
template <typename Iterator>
void quickSort(Iterator begin, int size) {
    quickSort(begin, begin + size, std::less<>());
}

// Vector

// Sort vector by custom compare function
template <typename T, typename Compare>
void quickSort(std::vector<T>& vec, Compare cmp) {
    quickSort(vec.begin(), vec.end(), cmp);
}

// Sort vector using std::less
template <typename T>
void quickSort(std::vector<T>& vec) {
    quickSort(vec, std::less<>());
}

// Array

// Sort array by custom compare function
template <typename T, std::size_t SIZE, typename Compare>
void quickSort(std::array<T, SIZE>& arr, Compare cmp) {
    quickSort(arr.begin(), arr.end(), cmp);
}

// Sort array using std::less
template <typename T, std::size_t SIZE>
void quickSort(std::array<T, SIZE>& arr) {
    quickSort(arr, std::less<>());
}