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