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

Point::Point() {
    point = nullptr;
    value = 0;
}

Point::~Point(){
    delete point;
}

VectorN Point::getVectorN() const { return *point; }

double Point::getValue()const{
    return this->value;
}

Point& Point::operator=(const Point &pPoint) {
    VectorN v(pPoint.getVectorN());
    Point p(v, pPoint.getValue());
    return p;
}

std::ostream& operator<<(std::ostream& os, const Point& dt)
{
    const VectorN vectorN = dt.getVectorN();
    os << vectorN;
    os << "\n" << "value = " << dt.getValue() << "\n";
    return os;
}