#ifndef SEARCHINGFORMINIMUMS_VECTORN_H
#define SEARCHINGFORMINIMUMS_VECTORN_H


class VectorN {
private:
    double * vec;
    int size;
public:
    VectorN(int n);

    ~VectorN();

    double * getTab();

    void setNVal(int n, double val);

    double getNVal(int n);

    int getSize();

    double getNorm()l

};

#endif //SEARCHINGFORMINIMUMS_VECTORN_H
