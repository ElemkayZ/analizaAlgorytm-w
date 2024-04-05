#include "fileScan.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

FileScan::FileScan(int _size){
    this->size = _size;
    readFile();
}
FileScan::FileScan(){
}
void FileScan::readFile(int _size){
    this->size = _size;
    readFile();

}
void FileScan::readFile(){
    std::ifstream file;
    file.open("dane.csv");
    if(file.is_open()){
        std::string line;
        std::string idx;
        std::string name;
        std::string rating;
        bool fullFile = (this->size==-1);
        
        while (std::getline(file,line))
        {
            if(fullFile){
                size++;
            }
            else{
                if(this->movieList.size()==this->size)
                break;
            }
            
            std::stringstream splitLine(line);
            std::getline(splitLine,idx,',');
            std::getline(splitLine,name,',');
            while (name.front() == '"')
			{
				std::string tmpName;
				if (name.back() == '"') break;
				std::getline(splitLine,tmpName, ',');
				name = name + ',' + tmpName;
			}
            std::getline(splitLine, rating, ',');
			if (!rating.empty()) {
				this->movieList.push_back({stoi(idx), name, stof(rating)});
			}
            else{
                size--;
            }
        }
        
    }
	file.close();

}

void FileScan::show()
{
	for (int i = 0; i < this->movieList.size(); i++) {
		std::cout << this->movieList.at(i).idx << " " << this->movieList.at(i).name << " " << this->movieList.at(i).rating << std::endl;
	}
}