#include "mergeSort.h"
#include <iostream>

void MergeSort::merge(std::vector<movie>& _tab, int _begin, int _mid, int _end) {
    int a = _mid - _begin + 1;
    int b = _end - _mid;
    std::vector<movie> Left(a), Right(b);
    for (int i = 0; i < a; i++) {
        Left[i] = _tab[_begin + i];
    }
    for (int j = 0; j < b; j++) {
        Right[j] = _tab[_mid + 1 + j];
    }
    int i = 0, j = 0, k = _begin;
    while (i < a && j < b) {
        if (Left[i].rating <= Right[j].rating) {
            _tab[k] = Left[i];
            i++;
        }
        else {
            _tab[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < a) {
        _tab[k] = Left[i];
        i++;
        k++;
    }
    while (j < b) {
        _tab[k] = Right[j];
        j++;
        k++;
    }
}

void MergeSort::mergeSort(std::vector<movie>& _tab, int _begin, int _end) {
    if (_begin < _end) {
        int _mid = _begin + (_end - _begin) / 2;
        mergeSort(_tab, _begin, _mid);
        mergeSort(_tab, _mid + 1, _end);
        merge(_tab, _begin, _mid, _end);
    }
}