#ifndef INTROSORT_H
#define INTROSORT_H
#include <vector>
#include "fileScan.h"
class IntroSort: public FileScan
{
public:
	IntroSort() : FileScan() {};
	int spliting(std::vector<movie>&, int , int );
	void introSort(std::vector<movie>&, int , int );
    void insertionSort(std::vector<movie>&, int begin, int end);
    void introsortUtil(std::vector<movie>& _tab, int _begin, int _end,int depthLimit);
	int medianOfThree(int a, int b, int c);
};
#endif 