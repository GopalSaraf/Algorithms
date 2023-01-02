#pragma once

#include <vector>
#include <array>

// Iterator

// Sort by iterators (begin and end) and custom compare function
template <typename Iterator, typename Compare>
void insertionSort(Iterator begin, Iterator end, Compare cmp) {
    std::swap(*begin, *std::min_element(begin, end, cmp));
    for (Iterator b = begin; ++b < end; begin = b)
        for (Iterator c = b; cmp(*c, *begin); --c, --begin)
            std::swap(*begin, *c);
}

// Sort by iterators (begin and end)
// Sort by std::less function
template <typename Iterator>
void insertionSort(Iterator begin, Iterator end) {
    insertionSort(begin, end, std::less<>());
}

// Sort by iterator begin and size of array
template <typename Iterator>
void insertionSort(Iterator begin, int size) {
    insertionSort(begin, begin + size, std::less<>());
}

// Vector

// Sort vector by custom compare function
template <typename T, typename Compare>
void insertionSort(std::vector<T>& vec, Compare cmp) {
    insertionSort(vec.begin(), vec.end(), cmp);
}

// Sort vector using std::less
template <typename T>
void insertionSort(std::vector<T>& vec) {
    insertionSort(vec, std::less<>());
}

// Array

// Sort array by custom compare function
template <typename T, std::size_t SIZE, typename Compare>
void insertionSort(std::array<T, SIZE>& arr, Compare cmp) {
    insertionSort(arr.begin(), arr.end(), cmp);
}

// Sort array using std::less
template <typename T, std::size_t SIZE>
void insertionSort(std::array<T, SIZE>& arr) {
    insertionSort(arr, std::less<>());
}