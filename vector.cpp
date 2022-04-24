#include <cmath>
#include "vector.h"


 //SetValueX �������� �������� ���������� X

void OOO::Vector::setValueX(double valueX) {
    x = valueX;
}


// SetValueY �������� �������� ����������  Y
void OOO::Vector::setValueY(double valueY) {
    y = valueY;
}

// SetValueZ �������� �������� ����������  Z
void OOO::Vector::setValueZ(double valueZ) {
    z = valueZ;
}

//������� ��������  �
double OOO::Vector::getValueX() const {
    return x;
}

// �������� �������� Y
double OOO::Vector::getValueY() const {
    return y;
}

// �������� �������� Z
double OOO::Vector::getValueZ() const {
    return z;
}

//����� �������
void OOO::Vector::print() const {
    std::cout << "( " << x << "; " << y << "; " << z << "; )" << std::endl;
}

//GetModule ��������� ������ �������, �� ������ �������� �����
double OOO::Vector::getModule() const {
    return sqrt(x * x + y * y + z * z);

}

//����������� �������
//Vector copy();

//��������� ������� �� ������

void OOO::Vector::vecSkalar(double value) {
    x = x * value;
    y = y * value;
    z = z * value;
    std::cout << "( " << x << "; " << y << "; " << z << "; )" << std::endl;
}


// ������������ �������
void OOO::Vector::normalize() {
    double length = this->getModule();
    if (length > 0) {
        this->vecSkalar(1.f / length);
    }
}


OOO::Vector OOO::summVec(Vector Obj1, Vector Obj2) {
    return Vector(Obj1.getValueX() + Obj2.getValueX(), Obj1.getValueY() + Obj2.getValueY(),
                  Obj1.getValueZ() + Obj2.getValueZ());
}

//�������� �������� A - B = C
OOO::Vector OOO::difVec(Vector Obj1, Vector Obj2) {
    return Vector(Obj1.getValueX() - Obj2.getValueX(), Obj1.getValueY() - Obj2.getValueY(),
                  Obj1.getValueZ() - Obj2.getValueZ());
}

//��������� ������������ A x B = C

OOO::Vector OOO::myltiVec(Vector Obj1, Vector Obj2) {
    return Vector((Obj1.getValueY() * Obj2.getValueZ()) - (Obj1.getValueZ() * Obj2.getValueY()),
                  (Obj1.getValueZ() * Obj2.getValueX()) - (Obj1.getValueX() * Obj2.getValueZ()),
                  (Obj1.getValueX() * Obj2.getValueY()) - (Obj1.getValueY() * Obj2.getValueX()));
}


// ��������� ����������� �������� A � B
double OOO::skmultiVec(Vector Obj1, Vector Obj2) {

    return Obj1.getValueX() * Obj2.getValueX() + Obj1.getValueY() * Obj2.getValueY() +
           Obj1.getValueZ() * Obj2.getValueZ();

}

double OOO::cosinusVec(Vector Obj1, Vector Obj2) {
    return (Obj1.getValueX() * Obj2.getValueX() + Obj1.getValueY() * Obj2.getValueY() +
            Obj1.getValueZ() * Obj2.getValueZ()) / (Obj1.getModule() * Obj2.getModule());

}
double OOO::degree(Vector Obj1, Vector Obj2) {
    return atan2(myltiVec(Obj1,Obj2).getModule(),skmultiVec(Obj1,Obj2))*180/M_PI;

}