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
            std::cout << "Конструктор по умолчанию" << std::endl;
        }

        Vector(double valueX, double valueY, double valueZ) : x(valueX), y(valueY), z(valueZ), id(gid++) {

            std::cout << "Конструктор со значениями" << std::endl;
        }

        Vector(Vector const &Obj1){
            x = Obj1.x;
            y = Obj1.y;
            z = Obj1.z;

        }

        ~Vector(){
            std::cout<<"Вызов дестркутора"<<std::endl;
        }

// SetValueX Придание значения координате  X
        //void setValueX(double valueX);

       void setValueX(double value);

// SetValueY Придание значения координате  Y
        void setValueY(double valueY);

// SetValueZ Придание значения координате  Z
        void setValueZ(double valueZ);

//Выводим значение  Х
        double getValueX() const;

// Получаем значение Y
        double getValueY() const;

// Получаем значение Z
        double getValueZ() const;

        //Вывод вектора
        void print() const;

        //GetModule Получение модуля вектора, на выводе получаем число
        double getModule() const;


        void vecSkalar(double value);


        // Нормирование вектора
        void normalize();

    };

    Vector summVec(Vector Obj1, Vector Obj2);


//Разность векторов A - B = C
    Vector difVec(Vector Obj1, Vector Obj2);

//Векторное произведение A x B = C

    Vector myltiVec(Vector Obj1, Vector Obj2);


// Скалярное произвдеине векторов A и B
    double skmultiVec(Vector Obj1, Vector Obj2);

    double cosinusVec(Vector Obj1, Vector Obj2);

    double degree(Vector Obj1, Vector Obj2);
}
#endif //OOP_LAB_1_TEST_VECTOR_H
