#ifndef BUCKETSORT_H
#define BUCKETSORT_H
#include "fileScan.h"
#include <vector>
class BucketSort : public FileScan
{
public:
	BucketSort() : FileScan() {};
	void bucketSort(std::vector<movie>&);
};
#endif 