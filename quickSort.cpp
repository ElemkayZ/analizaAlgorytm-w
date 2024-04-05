#include <vector>
#include <algorithm>
#include <iostream>
#include "quickSort.h"

int QuickSort::spliting(std::vector<movie>& _tab, int _begin, int _end) {
    int mid = _begin + (_end - _begin) / 2;
    int a = _tab[_begin].rating;
    int b = _tab[mid].rating;
    int c = _tab[_end].rating;
    
    int pivotRating = medianOfThree(a, b, c);

    int i = _begin - 1; 
    int j = _end + 1;

    while (true) {
        do {
            i++;
        } while (_tab[i].rating < pivotRating);

        do {
            j--;
        } while (_tab[j].rating > pivotRating);

        if (i >= j)
            return j;

        std::swap(_tab[i], _tab[j]);
    }
}

int QuickSort::medianOfThree(int a, int b, int c) {
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    else
        return c;
}

void QuickSort::quickSort(std::vector<movie>& _tab, int _begin, int _end) {
    const int INSERTION_SORT_THRESHOLD = 10; // Threshold for switching to Insertion Sort
    
    if (_begin < _end) {
        if (_end - _begin + 1 <= INSERTION_SORT_THRESHOLD) {
            insertionSort(_tab, _begin, _end);
        } else {
            int pivotIndex = spliting(_tab, _begin, _end);
            quickSort(_tab, _begin, pivotIndex - 1);
            quickSort(_tab, pivotIndex + 1, _end);
        }
    }
}

void QuickSort::insertionSort(std::vector<movie>& _tab, int _begin, int _end) {
    for (int i = _begin + 1; i <= _end; ++i) {
        movie key = _tab[i];
        int j = i - 1;
        
        while (j >= _begin && _tab[j].rating > key.rating) {
            _tab[j + 1] = _tab[j];
            j = j - 1;
        }
        
        _tab[j + 1] = key;
    }
}
