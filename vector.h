//
// Created by Home on 17.04.2022.
//

#ifndef OOP_LAB_1_TEST_VECTOR_H
#define OOP_LAB_1_TEST_VECTOR_H

#include<iostream>

static int gid = 0;
namespace OOO {


    class Vector {

    private:
        double x, y, z;
        int id;

    public:

        Vector() : Vector(0,0,0) {
            std::cout << "����������� �� ���������" << std::endl;
        }

        Vector(double valueX, double valueY, double valueZ) : x(valueX), y(valueY), z(valueZ), id(gid++) {

            std::cout << "����������� �� ����������" << std::endl;
        }

        Vector(Vector const &Obj1){
            x = Obj1.x;
            y = Obj1.y;
            z = Obj1.z;

        }

        ~Vector(){
            std::cout<<"����� �����������"<<std::endl;
        }

// SetValueX �������� �������� ����������  X
        //void setValueX(double valueX);

       void setValueX(double value);

// SetValueY �������� �������� ����������  Y
        void setValueY(double valueY);

// SetValueZ �������� �������� ����������  Z
        void setValueZ(double valueZ);

//������� ��������  �
        double getValueX() const;

// �������� �������� Y
        double getValueY() const;

// �������� �������� Z
        double getValueZ() const;

        //����� �������
        void print() const;

        //GetModule ��������� ������ �������, �� ������ �������� �����
        double getModule() const;


        void vecSkalar(double value);


        // ������������ �������
        void normalize();

    };

    Vector summVec(Vector Obj1, Vector Obj2);


//�������� �������� A - B = C
    Vector difVec(Vector Obj1, Vector Obj2);

//��������� ������������ A x B = C

    Vector myltiVec(Vector Obj1, Vector Obj2);


// ��������� ����������� �������� A � B
    double skmultiVec(Vector Obj1, Vector Obj2);

    double cosinusVec(Vector Obj1, Vector Obj2);

    double degree(Vector Obj1, Vector Obj2);
}
#endif //OOP_LAB_1_TEST_VECTOR_H
