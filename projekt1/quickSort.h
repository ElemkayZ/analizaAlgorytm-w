#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include "fileScan.h"
class QuickSort: public FileScan
{
public:
	QuickSort() : FileScan() {};
	int spliting(std::vector<movie>&, int , int );
	void quickSort(std::vector<movie>&, int , int );
	int medianOfThree(int a, int b, int c);
	void insertionSort(std::vector<movie>& _tab, int _begin, int _end);
};
#endif 