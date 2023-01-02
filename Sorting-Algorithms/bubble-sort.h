#pragma once

#include <vector>
#include <array>

// Iterator

// Sort by iterators (begin and end) and custom compare function
template <typename Iterator, typename Compare>
void bubbleSort(Iterator begin, Iterator end, Compare cmp) {
    for (Iterator i = begin; i != end; i++)
        for (Iterator j = begin; j < i; j++)
            if (cmp(*i, *j)) std::swap(*i, *j);
}

// Sort by iterators (begin and end)
// Sort by std::less function
template <typename Iterator>
void bubbleSort(Iterator begin, Iterator end) {
    bubbleSort(begin, end, std::less<>());
}

// Sort by iterator begin and size of array
template <typename Iterator>
void bubbleSort(Iterator begin, int size) {
    bubbleSort(begin, begin + size, std::less<>());
}

// Vector

// Sort vector by custom compare function
template <typename T, typename Compare>
void bubbleSort(std::vector<T>& vec, Compare cmp) {
    bubbleSort(vec.begin(), vec.end(), cmp);
}

// Sort vector using std::less
template <typename T>
void bubbleSort(std::vector<T>& vec) {
    bubbleSort(vec, std::less<>());
}

// Array

// Sort array by custom compare function
template <typename T, std::size_t SIZE, typename Compare>
void bubbleSort(std::array<T, SIZE>& arr, Compare cmp) {
    bubbleSort(arr.begin(), arr.end(), cmp);
}

// Sort array using std::less
template <typename T, std::size_t SIZE>
void bubbleSort(std::array<T, SIZE>& arr) {
    bubbleSort(arr, std::less<>());
}