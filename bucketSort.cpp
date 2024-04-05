#include "BucketSort.h"
#include "quickSort.h"

void BucketSort::bucketSort(std::vector<movie>& _tab)
{

    int length = 11;

    std::vector<movie>* bucket = new std::vector<movie>[length]; 

    for (int i = 0; i < _tab.size(); i++)
    {
        bucket[static_cast<int>(_tab.at(i).rating)].push_back(_tab.at(i));
    }

    int a = 0;
    QuickSort quickSort;

    for (int i = 0; i < length; i++)
    {
        int tmpSize = bucket[i].size();
        if (tmpSize > 0)
        {
            quickSort.movieList = bucket[i];
            quickSort.quickSort(quickSort.movieList,0,quickSort.size-1);
            bucket[i] = quickSort.movieList;
            for (int j = 0; j < tmpSize; j++)
            {
                _tab.at(a) = bucket[i][j];
                a++;
            }
        }
    }
}
