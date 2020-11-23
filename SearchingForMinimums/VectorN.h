#ifndef SEARCHINGFORMINIMUMS_VECTORN_H
#define SEARCHINGFORMINIMUMS_VECTORN_H


class VectorN {
private:
    double * vec;
public:
    VectorN(int n);

    ~VectorN();

    double * getTab();

    void setNVal(int n, double val);

    double getNVal(int n);

};

#endif //SEARCHINGFORMINIMUMS_VECTORN_H
