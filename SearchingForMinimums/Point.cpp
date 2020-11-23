#include "Point.h"

bool Point::operator==(const Point &point) {
    return this->getVectorN()==point.getValue() && this->getValue()==point.getValue();
}

VectorN Point::getVectorN() const { return point; }

double Point::getValue()const{
    return this->value;
}

Point::Point(Point * point) {
    this->point = VectorN(point->getVectorN());
    value = point->getValue();
}

Point::Point(VectorN & vectorN, double value){
}

std::ostream& operator<<(std::ostream& os, const Point& dt)
{
    VectorN vect(dt.getVectorN());
    for( int i =0; i<vect.getSize(); i++){

    }
    os << " ";
    return os;
}