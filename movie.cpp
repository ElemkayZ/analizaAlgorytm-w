#include <string>

class movie
{
private:
    std::string title;
    double rating;
public:
    movie(std::string,double);
    ~movie();
    std::string getTitle();
    double getRating(double _rating);
    void changeTitle(std::string _title);
    void changeRating(double _rating);

};

movie::movie(std::string _title,double _rating)
{
    this->title = _title;
    this->rating = _rating;
}

movie::~movie()
{
}

std::string movie::getTitle(){
    return this->title;
}
double movie::getRating(double _rating){
    return this->rating;
}

void movie::changeTitle(std::string _title){
    this->title = _title;
}
    
void movie::changeRating(double _rating){
    this->rating = _rating;
}