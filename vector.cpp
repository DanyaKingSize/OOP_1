#include <cmath>
#include "vector.h"

namespace OOO {
    int OOO::Vector::_id = 0;
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

    bool OOO::Vector::isZero() const {
        return (this->x == 0 && this->y == 0 && this->z == 0);

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

    void Vector::copy(const Vector &Obj1) {
        this->x = Obj1.x;
        this->y = Obj1.y;
        this->z = Obj1.z;
    }


  Vector::summVec(const Vector &Obj1,const Vector &Obj2) {
    return Vector(Obj1.x + Obj2.x, Obj1.y+ Obj2.y,Obj1.z+ Obj2.z);
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
    if (Obj1.isZero() || Obj2.isZero()) {
        exit(-1);
    }
    return (Obj1.getValueX() * Obj2.getValueX() + Obj1.getValueY() * Obj2.getValueY() +
            Obj1.getValueZ() * Obj2.getValueZ()) / (Obj1.getModule() * Obj2.getModule());

}

double OOO::degree(Vector Obj1, Vector Obj2) {
    if (Obj1.isZero() || Obj2.isZero()) {
        exit(-1);
    } else {
        return atan2(myltiVec(Obj1, Obj2).getModule(), skmultiVec(Obj1, Obj2)) * 180 / M_PI;
    }
}

}