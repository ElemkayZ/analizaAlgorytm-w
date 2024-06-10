#ifndef FILESCAN_H
#define FILESCAN_H
#include <vector>
#include <string>

class FileScan
{
protected:
    struct movie
    {
        int idx;
        std::string name;
        float rating;

         bool operator<(const movie& other) const {
            return rating < other.rating;
        }
    };
public:
    std::vector<movie> movieList;
    int size = 0;
    FileScan(int);
    FileScan();
    void readFile();
    void readFile(int);
    void show();
};


#endif