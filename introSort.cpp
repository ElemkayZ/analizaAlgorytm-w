#include <algorithm>
#include <iostream>
#include "introSort.h"
#include <cmath>

void IntroSort::insertionSort(std::vector<movie>& _tab, int _begin, int _end) {
    for (int i = _begin + 1; i <= _end; i++) {
        movie key = _tab[i];
        int j = i - 1;
        while (j >= _begin && _tab[j].rating > key.rating) {
            _tab[j + 1] = _tab[j];
            j = j - 1;
        }
        _tab[j + 1] = key;
    }
}

int IntroSort::spliting(std::vector<movie>& _tab, int _begin, int _end) {
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

int IntroSort::medianOfThree(int a, int b, int c) {
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    else
        return c;
}

void IntroSort::introsortUtil(std::vector<movie>& _tab, int _begin, int _end, int depthLimit) {
    int size = _end - _begin + 1;
    if (size < 16) {
        insertionSort(_tab, _begin, _end);
        return;
    }
    if (depthLimit == 0) {
        std::make_heap(_tab.begin() + _begin, _tab.begin() + _end + 1);
        std::sort_heap(_tab.begin() + _begin, _tab.begin() + _end + 1);
        return;
    }

    int pivotIndex = spliting(_tab, _begin, _end);
    introsortUtil(_tab, _begin, pivotIndex - 1, depthLimit - 1);
    introsortUtil(_tab, pivotIndex + 1, _end, depthLimit - 1);
}

void IntroSort::introSort(std::vector<movie>& _tab, int _begin, int _end) {
    int depthLimit = 2 * std::log(_end - _begin + 1);
    introsortUtil(_tab, _begin, _end, depthLimit);
}
