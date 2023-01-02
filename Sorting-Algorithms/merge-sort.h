#pragma once

#include <vector>
#include <array>

// Iterator

// Sort by iterators (begin and end) and custom compare function
template <typename Iterator, typename Compare>
void mergeSort(Iterator begin, Iterator end, Compare cmp) {
    if (end <= begin + 1) return;
    Iterator middle = begin + (end - begin) / 2;
    mergeSort(begin, middle, cmp);
    mergeSort(middle, end, cmp);
    std::inplace_merge(begin, middle, end, cmp);
}

// Sort by iterators (begin and end)
// Sort by std::less function
template <typename Iterator>
void mergeSort(Iterator begin, Iterator end) {
    mergeSort(begin, end, std::less<>());
}

// Sort by iterator begin and size of array
template <typename Iterator>
void mergeSort(Iterator begin, int size) {
    mergeSort(begin, begin + size, std::less<>());
}

// Vector

// Sort vector by custom compare function
template <typename T, typename Compare>
void mergeSort(std::vector<T>& vec, Compare cmp) {
    mergeSort(vec.begin(), vec.end(), cmp);
}

// Sort vector using std::less
template <typename T>
void mergeSort(std::vector<T>& vec) {
    mergeSort(vec, std::less<>());
}

// Array

// Sort array by custom compare function
template <typename T, std::size_t SIZE, typename Compare>
void mergeSort(std::array<T, SIZE>& arr, Compare cmp) {
    mergeSort(arr.begin(), arr.end(), cmp);
}

// Sort array using std::less
template <typename T, std::size_t SIZE>
void mergeSort(std::array<T, SIZE>& arr) {
    mergeSort(arr, std::less<>());
}