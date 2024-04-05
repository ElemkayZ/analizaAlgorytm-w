#include <iostream>
#include "fileScan.cpp"
#include "quickSort.cpp"
#include "mergeSort.cpp"
#include "BucketSort.cpp"
#include "IntroSort.cpp"
#include "main.h"
#include <chrono>
 
int main(){

    std::cout << "---------------MENU-------------------\n\n";
    std::cout << "ENTER GIVEN NUMBER FROM OPTIONS\n";
    std::cout << "OPTIONS:\n";
    std::cout << "1 - 10 000\n";
    std::cout << "2 - 100 000\n";
    std::cout << "3 - 500 000\n";
    std::cout << "4 - 1 000 000\n";
    std::cout << "5 - ALL\n";
    std::cout << "0 - QUIT\n";
    int userInput= -1;
    FileScan*movieList;
    int count;

    while (userInput != 0 )
    {
        std::cout << "AWAITING INPUT\n";
        std::cout << ">";std::cin>>userInput;std::cout << "\n";
        switch (userInput)
        {
        case 0:
            return 0;
            break;
        case 1:
            count=10000;
            break;
        case 2:
            count=100000;
            break;
        case 3:
            count=500000;
            break;
        case 4:
            count=1000000;
            break;
        case 5:
            count=-1;
            break;
        
        default:
            std::cout << "WRONG OPTION\n";
            return 0;
            break;
        }
    int userInput= -1;

        std::cout << "---------------MENU-------------------\n\n";
        std::cout << "ENTER GIVEN NUMBER FROM OPTIONS\n";
        std::cout << "OPTIONS:\n";
        std::cout << "1 - Merge Sort\n";
        std::cout << "2 - Bucket Sort\n";
        std::cout << "3 - Quick Sort\n";
        std::cout << "4 - Introspect Sort\n";
        std::cout << "5 - ALL\n";
        std::cout << "0 - QUIT\n";
        int innerInput= -1;
        while (innerInput != 0 )
        {

            mainMath mainMath;
            QuickSort quickSort;
            MergeSort mergeSort;
            BucketSort bucketSort;
            IntroSort introSort;
            float mediana;
            float average;
            movieList = new FileScan(count);
            std::cout << "AWAITING INPUT\n";
            std::cout << ">";std::cin>>innerInput;std::cout << "\n";
            auto start = std::chrono::high_resolution_clock::now();
            switch (innerInput)
            {
            case 0:
                return 0;
                break;
            case 1:
                mergeSort.readFile(count);
                mergeSort.mergeSort(mergeSort.movieList, 0, mergeSort.size - 1);
                mediana = mainMath.mediana(mergeSort.movieList);
        
                average = mainMath.average(mergeSort.movieList);

                break;
            case 2:
                bucketSort.readFile(count);
                bucketSort.bucketSort(bucketSort.movieList);

                mediana = mainMath.mediana(bucketSort.movieList);
                average = mainMath.average(bucketSort.movieList);
                break;
            case 3:
                quickSort.readFile(count);
                quickSort.quickSort(quickSort.movieList, 0, quickSort.size - 1);

                mediana = mainMath.mediana(quickSort.movieList);
                average = mainMath.average(quickSort.movieList);
                break;
            case 4:
                introSort.readFile(count);
                introSort.introSort(introSort.movieList, 0, introSort.size - 1);

                mediana = mainMath.mediana(introSort.movieList);
                average = mainMath.average(introSort.movieList);
                break;
            case 5:
                mergeSort.readFile(count);
                mergeSort.mergeSort(mergeSort.movieList, 0, mergeSort.size - 1);

                bucketSort.readFile(count);
                bucketSort.bucketSort(bucketSort.movieList);

                quickSort.readFile(count);
                quickSort.quickSort(quickSort.movieList, 0, quickSort.size - 1);

                introSort.readFile(count);
                introSort.introSort(introSort.movieList, 0, introSort.size - 1);
                
                mediana = mainMath.mediana(introSort.movieList);

                average = mainMath.average(introSort.movieList);
                break;
            default:
                std::cout << "WRONG OPTION\n";
                return 0;
                break;
            }
                
            auto stop = std::chrono::high_resolution_clock::now();
            std::chrono::duration <double, std::milli> d = stop - start;
            std::cout << "Time taken = " << d.count() << std::endl;
            std::cout << "Average = " << average << std::endl;
            std::cout << "Median = " << mediana << std::endl;
        }
    }
    return 0;
}

float mainMath::mediana(std::vector<movie>& _tab) {
    int size = _tab.size();
    if (size == 0) {
        return 0.0f;
    }

    std::sort(_tab.begin(), _tab.end(), [](const movie& a, const movie& b) {
        return a.rating < b.rating;
    });

    float median;
    if (size % 2 == 0) {
        int midIndex1 = size / 2 - 1;
        int midIndex2 = size / 2;
        median = (_tab[midIndex1].rating + _tab[midIndex2].rating) / 2.0f;
    } else {
        int midIndex = size / 2;
        median = _tab[midIndex].rating;
    }

    return median;
}
float mainMath::average(std::vector<movie>& _tab) {
    float sum = 0;
    for (const auto& m : _tab) {
        sum += m.rating;
    }
    return sum / _tab.size();
}