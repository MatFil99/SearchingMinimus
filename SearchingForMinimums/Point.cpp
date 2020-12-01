#include "Point.h"


bool Point::operator==(const Point &point) {
    return this->getVectorN()==point.getValue() && this->getValue()==point.getValue();
}

Point::Point(VectorN vectorN, double val) {
    point = new VectorN(vectorN);
    this->value = val;
}

Point::Point(Point const &point) {
    this->point = new VectorN(point.getVectorN());
    value = point.getValue();
}

Point::~Point(){
    if(point!= nullptr) delete point;
}

VectorN Point::getVectorN() const { return *point; }

double Point::getValue()const{
    return this->value;
}

Point& Point::operator=(const Point &pPoint) {
    delete point;
    point= new VectorN(pPoint.getVectorN());
    value = pPoint.getValue();
    return *this;
}

bool Point::isNull() {
    return point == nullptr;
}

Point::Point() {
    point = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Point& dt)
{
    if(dt.getPointPointer()!= nullptr){
        os << *dt.getPointPointer();
        os << "\n" << "value = " << dt.getValue() << "\n";
    }else os << "Pusty punkt";
    return os;
}