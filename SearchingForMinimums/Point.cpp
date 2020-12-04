#include "Point.h"


bool Point::operator==(const Point &point) {
    return this->getVectorN()==point.getValue() && this->getValue()==point.getValue();
}

Point::Point(VectorN vectorN, double val) {
    point = new VectorN(vectorN);
    this->value = val;
}

Point::Point(Point const &pPoint) {
    if( pPoint.isNull() ){
        this->point=nullptr;
        value=0;
    }else{
        this->point = new VectorN(pPoint.getVectorN());
        value = pPoint.getValue();
    }
}

Point::~Point(){
    if(point!= nullptr) delete point;
}

VectorN Point::getVectorN() const { 
    if( point!=nullptr ) 
        return *point;
    else return VectorN();//pusty wektor
}

double Point::getValue()const{
    return this->value;
}

Point& Point::operator=(const Point &pPoint) {
    if( point!=nullptr) delete point;
    if(pPoint.isNull()){
        point = nullptr;
        value=0;
    }else{
        point = new VectorN(pPoint.getVectorN());
        value = pPoint.getValue();
    }
    return *this;
}

bool Point::isNull()const {
    return point == nullptr;
}

Point::Point() {
    point = nullptr;
    value=0;
}

std::ostream& operator<<(std::ostream& os, const Point& dt)
{
    if(dt.getPointPointer()!= nullptr){
        os << *dt.getPointPointer();
        os << "\n" << "value = " << dt.getValue() << "\n";
    }else os << "Pusty punkt";
    return os;
}