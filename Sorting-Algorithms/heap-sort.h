#pragma once

#include <vector>
#include <array>

// Iterator

// Sort by iterators (begin and end) and custom compare function
template <typename Iterator, typename Compare>
void heapSort(Iterator begin, Iterator end, Compare cmp) {
    while (begin != end) std::pop_heap(begin, end--, cmp);
}

// Sort by iterators (begin and end)
// Sort by std::less function
template <typename Iterator>
void heapSort(Iterator begin, Iterator end) {
    heapSort(begin, end, std::less<>());
}

// Sort by iterator begin and size of array
template <typename Iterator>
void heapSort(Iterator begin, int size) {
    heapSort(begin, begin + size, std::less<>());
}

// Vector

// Sort vector by custom compare function
template <typename T, typename Compare>
void heapSort(std::vector<T>& vec, Compare cmp) {
    heapSort(vec.begin(), vec.end(), cmp);
}

// Sort vector using std::less
template <typename T>
void heapSort(std::vector<T>& vec) {
    heapSort(vec, std::less<>());
}

// Array

// Sort array by custom compare function
template <typename T, std::size_t SIZE, typename Compare>
void heapSort(std::array<T, SIZE>& arr, Compare cmp) {
    heapSort(arr.begin(), arr.end(), cmp);
}

// Sort array using std::less
template <typename T, std::size_t SIZE>
void heapSort(std::array<T, SIZE>& arr) {
    heapSort(arr, std::less<>());
}