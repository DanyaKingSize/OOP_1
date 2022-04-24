#include <iostream>
#include <cmath>
#include "vector.h"




using namespace std;
int main() {
    setlocale(LC_ALL, "Rus");
    cout << "____PART 1____" << endl;
    cout << "1) Reading  and writes " << endl << "Reading:" << endl;
    OOO::Vector Vec1(-10, -44, 0);
    Vec1.print();
    cout << "Writes:" << endl;

    Vec1.setValueY(37);
    Vec1.setValueZ(10);
    Vec1.print();

    cout << "2) Vector modulus: ";
    cout << Vec1.getModule();

    cout << "\n4) multiplication of a vector by a scalar: " << endl;
    Vec1.vecSkalar(6);

    cout << "5) Vector normalization :" << endl;
    Vec1.normalize();


    cout << endl << endl << endl << "____PART 2____" << endl;

    OOO::Vector VecA(15, 10, 61);
    OOO::Vector VecB(20, 10, 31);

    // Сумма векторов
    cout << "1)  Sum of vectors: " << endl;
    OOO::Vector VecSumm = summVec(VecA, VecB);
    VecSumm.print();


    // Разность векторов
    cout << "2) vector difference" << endl;
    OOO::Vector VecDif = difVec(VecA, VecB);
    VecDif.print();

    // Умножение векторов
    cout << "3) vector vector multiplication:" << endl;
    OOO::Vector multyVec = myltiVec(VecA, VecB);
    multyVec.print();

    //Скалярнео умножение двух векторов
    double skmulty = skmultiVec(VecA, VecB);
    cout << "4) Scalar multiplication of two vectors: " << skmulty << endl;

    // Косиенус
    double cosVec = cosinusVec(VecA, VecB);
    if (cosVec > 360) {
        cosVec = cosVec - 360;
        cout << "5) Cosinus between vectors: " << cosVec << endl;
    } else {
        cout << "5) Cosinus between vectors: " << cosVec << endl;
        cout << "Sinus between vectors: " << sqrt(1 - (cosVec * cosVec)) << endl << "Degree =  " << cosVec * 180 / M_PI
             << endl;
    }
    cout << "Govno: " << OOO::degree(VecA, VecB) << std::endl;
}

