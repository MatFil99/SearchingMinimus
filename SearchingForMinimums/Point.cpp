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
    delete point;
}

VectorN Point::getVectorN() const { return *point; }

double Point::getValue()const{
    return this->value;
}

std::ostream& operator<<(std::ostream& os, const Point& dt)
{
    const VectorN & vector = dt.getVectorN();
    for( int i =0; i<vector.getSize(); i++){
        os << vector.getNVal(i) << ", ";
    }
    os << "\n" << "value = " << dt.getValue() << "\n";
    return os;
}