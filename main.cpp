 #include <iostream>
#include <cmath>
using namespace std;

class Vector
{
// Список методов используемых в классе
private:
    double x, y, z, module; //Скрываем компоненты векторов

// список методов доступных другим функциям и объектам программы
public:

//Конструктор вектора, который имеет 3 координаты x y z
    Vector (double valueX, double valueY, double valueZ)
    {
        x = valueX;
        y = valueY;
        z = valueZ;
    }

// SetValueX Придание значения координате X
    void setValueX(double valueX)
    {
        x = valueX;
    }

// SetValueY Придание значения координате  Y
    void setValueY(double valueY)
    {
        y = valueY;
    }

// SetValueZ Придание значения координате  Z
    void setValueZ(double valueZ)
    {
        z = valueZ;
    }

//Выводим значение  Х
     double getValueX() const
    {
        return x;
    }

// Получаем значение Y
     double getValueY() const
    {
        return y;
    }

// Получаем значение Z
     double getValueZ() const
    {
        return z;
    }

    //Вывод вектора
    void  print() const
    {
        cout <<"( "<<x<<"; "<<y << "; "<<z<< "; )"<<endl;
    }

   //GetModule Получение модуля вектора, на выводе получаем число
double getModule() const
    {
        double module;
        //module = sqrt(pow(obj1.getValueX(),2) + pow(obj1.getValueY(),2) + pow(obj1.getValueZ(),2);
        module = sqrt(x*x + y*y + z*z);
        return module;
    }

//Копирование вектора
    //Vector copy();

//Умножение вектора на скаляр

    void  vecSkalar (double value)
    {
        x = x*value;
        y = y*value;
        z = z*value;
        cout <<"( "<<x<<"; "<<y << "; "<<z<< "; )"<<endl;
    }

// Get Norm Получение нормы ( Длинны вектора и его направления ), на выходе число
   // const double GetNorm();

// Нормирование вектора
    void normalize ()
    {
        double length = this->getModule();
            if (length > 0 ){
                this->vecSkalar( 1.f / length );
            }
        }
};

//Внешние функции

//Сумма векторов A + B = C

Vector summVec(Vector Obj1,Vector Obj2)
{
    return Vector(Obj1.getValueX() + Obj2.getValueX(),Obj1.getValueY() + Obj2.getValueY(),Obj1.getValueZ() + Obj2.getValueZ());
}

//Разность векторов A - B = C
Vector difVec(Vector Obj1, Vector Obj2)
{
    return Vector(Obj1.getValueX() - Obj2.getValueX(),Obj1.getValueY() - Obj2.getValueY(),Obj1.getValueZ() - Obj2.getValueZ());
}

//Векторное произведение A x B = C

Vector myltiVec(Vector Obj1, Vector Obj2)
{
    return Vector((Obj1.getValueY() * Obj2.getValueZ()) - (Obj1.getValueZ() * Obj2.getValueY()),(Obj1.getValueZ() * Obj2.getValueX()) - (Obj1.getValueX() * Obj2.getValueZ()),(Obj1.getValueX() * Obj2.getValueY()) - (Obj1.getValueY() * Obj2.getValueX()));
}


// Скалярное произвдеине векторов A и B
 double skmultiVec (Vector Obj1, Vector Obj2)
{
    double skmV = Obj1.getValueX() * Obj2.getValueX() + Obj1.getValueY() * Obj2.getValueY() + Obj1.getValueZ()*Obj2.getValueZ();
    return skmV;
}

double  cosinusVec ( Vector Obj1, Vector Obj2)
{
    double cosinus = (Obj1.getValueX() * Obj2.getValueX() + Obj1.getValueY() * Obj2.getValueY() + Obj1.getValueZ()*Obj2.getValueZ()) / ( Obj1.getModule() * Obj2.getModule() );
    return cosinus;
}




int main() {
    cout<<"____PART 1____"<<endl;
    cout << "1) Reading  and writes "<< endl <<"Reading:" << endl;
    Vector Vec1(10,44,0);
    Vec1.print();

    cout << "Writes:" << endl;
    Vec1.setValueX(13);
    Vec1.setValueY(37);
    Vec1.setValueZ(10);
    Vec1.print();

    cout <<"2) Vector modulus: ";
    cout << Vec1.getModule();

    cout<<"\n4) multiplication of a vector by a scalar: "<< endl;
    Vec1.vecSkalar(6);

    cout << "5) Vector normalization :" <<endl;
    Vec1.normalize();


    cout<<endl << endl << endl<<"____PART 2____"<<endl;

    Vector VecA(15,10,61);
    Vector VecB(20,10,31);

    // Сумма векторов
    cout<< "1)  Sum of vectors: "<< endl;
    Vector VecSumm = summVec(VecA,VecB);
    VecSumm.print();


    // Разность векторов
    cout<<"2) vector difference"<< endl;
    Vector VecDif = difVec(VecA,VecB);
    VecDif.print();

    // Умножение векторов
    cout<<"3) vector vector multiplication:"<< endl;
    Vector multyVec = myltiVec(VecA,VecB);
    multyVec.print();

    //Скалярнео умножение двух векторов
   double skmulty = skmultiVec(VecA,VecB);
    cout << "4) Scalar multiplication of two vectors: " <<skmulty<<endl;

    // Косиенус
    double cosVec = cosinusVec( VecA,VecB);
    if (cosVec > 360)
    {
        cosVec = cosVec - 360;
        cout << "5) Cosinus between vectors: " <<cosVec<<endl;
    }
    else
    {
        cout << "5) Cosinus between vectors: " <<cosVec<<endl;
        cout << "Sinus between vectors: " <<sqrt(1-(cosVec*cosVec))<<endl<< "Degree =  "<< cosVec*180/M_PI<<endl;
    }

}

