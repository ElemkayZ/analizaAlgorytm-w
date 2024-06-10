#ifndef MERGESORT_H
#define MERGESORT_H
#include "fileScan.h"

class MergeSort: public FileScan
{
public:
	MergeSort() : FileScan() {};
	void merge(std::vector<movie>& _tab, int _begin, int _mid, int _end);
	void mergeSort(std::vector<movie>& _tab, int _begin, int _end);
};
#endif 