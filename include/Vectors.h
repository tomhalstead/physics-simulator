#ifndef VECTORS_H
#define VECTORS_H
#include <cmath>

template <typename T, unsigned int size>
class Vector
        // 'Vector' objects store 'size' elements (a 'size'-dimensional vector), with type 'T' variables to be stored
        // in each element. If 'T' is a pointer type all data that the elements point to will be deleted
        // upon destruction of the Vector object.
        //
        // Examples of usage:
        //
        // Vector<double, 3> position;
        // position[0] = 3;
        // position[1] = 4.3;
        // position[2] = -2.11;
        //
        // double velocityData[] = {4,5,6};
        // Vector<double, 3> velocity(positionData);
        //
        // double time = 4;
        // Vector<double, 3> newPosition = position + velocity * time;
        // cout << "Distance from origin = " << newPosition.magnitude() << endl;
        //
        // In practice this class is a little inconvenient to initialize, so most likely 'Vector2D' or 'Vector3D' will be used

{
public:

    /* Constructors */

    Vector(T* set);
    Vector(const T& defaultValue = T());
    // This overloaded constructor creates a vector with 'size' elements,
    // with each element being assigned initial value of 'defaultValue'

    /* Big 3 */

    Vector(const Vector<T,size> &other);
    Vector<T,size>& operator=(const Vector<T,size> &RHS);
    virtual ~Vector();

    /* Utility functionss */

    double magnitude() const;

    Vector<T,size>& operator[](unsigned int index);
    const Vector<T,size>& operator[](unsigned int index) const;

    Vector<T,size>& operator+=(const Vector<T,size>& RHS);
    Vector<T,size>& operator-=(const Vector<T,size>& RHS);

    template <typename U>
    friend Vector<U,size> operator+(const Vector<U,size>& RHS, const Vector<U,size>& RHS);

    template <typename U>
    friend Vector<U,size> operator-(const Vector<U,size>& RHS, const Vector<U,size>& RHS);

    template <typename U>
    friend U operator*(const Vector<U,size>& LHS, const Vector<U,size>& RHS);
    // Dot Product

    template <typename U>
    friend Vector<U,size> operator*(const Vector<U,size>& theVector, const U& theScalar);
    // Scalar Multiplication

    template <typename U>
    friend Vector<U,size> operator*(const U& theScalar, const Vector<U,size>& theVector);
    // Scalar mutiplication

    Vector<T,size>& operator*=(const T& RHS);
    // Scalar mutiplication


private:
    T* storage;
};

template <typename T>
class Vector2D : public Vector<T,2>
        // 'Vector2D' class inherits the functionality of 'Vector'. It's purpose is to add an additional constructor,
        // which allows values to be added upon creation of the 'Vector' object.
        //
        // The new constructor allows this constructor call:  Vector2D newVector(3.2, 4.5);
        // This can be useful when we need to pass a vector to a function, but don't have one already:
        //
        // moveObject( Vector2D(3.2, 4.5) );
        //
        // 'Vector2D' is easier to initialize than 'Vector' and is handy for representing 2-D quantities such as
        // position, velocity, force, etc.
{
    Vector2D(T* set);
    Vector2D(const T& defaultValue = T());
    Vector2D(const T& value1, const T& value2);
};

template <typename T>
class Vector3D : public Vector<T,3>
        // 'Vector3D' class inherits the functionality of 'Vector'. It's purpose is to add an additional constructor,
        // which allows values to be added upon creation of the 'Vector' object ( i.e. Vector3D(3.2, 4.5, -2.2) ),
        // and to allow for cross product to be calculated for 3D vectors using the '^' and '^=' operators.
        //
        // The new Constructor allows this constructor call:  Vector3D newVector(3.2, 4.5, -9);
        // This can be useful when we need to pass a vector to a function, but don't have one already:
        //
        // moveObject( Vector3D(3.2, 4.5, -9) );
        //
        // 'Vector3D' is easier to initialize than 'Vector' and is handy for representing 3-D quantities such as
        // position, velocity, force, etc.
{
    Vector3D(T* set);
    Vector3D(const T& defaultValue = T());
    Vector3D(const T& value1, const T& value2, const T &value3);

    template <typename U>
    friend Vector3D<U> operator^(const Vector3D<U>& LHS, const Vector3D<U>& RHS);
    // Cross Product

    Vector3D<T>& operator^=(const Vector3D<T>& RHS);
    // Cross Product
};

template <class T, unsigned int size>
Vector<T, size>::Vector(T* set)
{
    // CONSTRUCTOR
    storage = new T[size]; // dynamic memory allocation of T type sequential memory
    for (int i=0; i < size; i++)
    {
        // size is set with the template invocation as the number of elements of type T
        storage[i] = set[i]; // storage is the private member variable of the Vector class
    }


}





template <class T, unsigned int size>
Vector<T, size>::Vector(const T& A)
{
    // CONSTRUCTOR



    storage = new T[size];
    for(i = 0; i < size; i++)
        storage[i] = A;   // A is a value of type T



}




template <class T, unsigned int size>
Vector<T, size>::Vector(const Vector<T,size>& A)
{
    // COPY CONSTRUCTOR

    storage = new T[size]; // ensuring correct size of Vector values
    for (int i = 0; i < size; i++)
    {
        this->storage[i] = A.storage[i];
    }


}


Vector<T, size> &Vector<T, size>::operator=(const Vector<T, size> &RHS)
{
    // ASSIGNMENT OPERATOR
    if (this == RHS)
        return *this;
    if (this->storage != NULL)
        delete [] this; // we are assuming size > 0
    storage = new T[size]; // ensuring correct size of Vector values
    for (int i = 0; i < size; i++)
    {
        this->storage[i] = RHS.storage[i];
    }
    return *this;

}



template <class T, unsigned int size>
Vector<T, size>::~Vector()
{
    // DESTRUCTOR
    while (storage != NULL && size > 0)
    {
        delete [] storage; // is there a destroy PointMass callback?
    }


}




template <class T, unsigned int size>
double Vector<T, size>::magnitude() const
{
    double sum = 0;

    for (int i = 0; i<size; i++)
    {
        sum += pow(storage[i],2);
    }
    return sqrt(sum);

    // leave space.
}


// dot product ****************************** we need to return a type U.
template <typename U>
friend U operator*(const Vector<U,size>& LHS, const Vector<U,size>& RHS)
{


    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = (LHS.storage[i] * RHS.storage[i] ) + sum;
    }
    return sum;


}

template <class T, unsigned int size>
Vector<T, size> &Vector<T, size>::operator[](unsigned int index)
{


    return storage[index];
}




template <class T, unsigned int size>
const Vector<T, size> &Vector<T, size>::operator[](unsigned int index) const
{







    return storage[index];

}




template <class T, unsigned int size>
Vector<T, size> &Vector<T, size>::operator+=(const Vector<T, size> &RHS)
{



    for (int n = 0; n < size; ++n)
        storage[n] += RHS.storage[n];
    return *this;




}



template <class T, unsigned int size>
Vector<T, size> &Vector<T, size>::operator-=(const Vector<T, size> &RHS)
{

    for (int n = 0; n < size; ++n)
        storage[n] -= RHS.storage[n];
    return *this;







}




template <class T, unsigned int size>
Vector<T, size> &Vector<T, size>::operator*=(const T &RHS)
{


    for (int n = 0; n < size; ++n)
        storage[n] *= RHS.storage[n];
    return *this;





}




template <typename U>
Vector<U, size> operator+(const Vector<U, size> &RHS, const Vector<U, size> &RHS)
{






}





template <typename U>
Vector<U, size> operator-(const Vector<U, size> &RHS, const Vector<U, size> &RHS)
{






}





template <typename U>
Vector<U> operator*(const Vector<U, size> &LHS, const Vector<U, size> &RHS)
{






}





template <typename U>
Vector<U, size> operator*(const Vector<U, size> &theVector, const U &theScalar)
{
    Vector<U,size> temp;
    for (int i = 0; i < size; i++)
    {
        temp[0] = theScalar * theVector[i];
    }
    return temp;


}



template <typename U>
Vector<U, size> operator*(const U &theScalar, const Vector<U, size> &theVector)
{
    Vector<U,size> temp;
    for (int i = 0; i <size; i++)
    {
        temp[i] = theScalar * theVector[i];
    }
    return temp;

}


///////////////////////
// 2D and 3D Derived Vector Classes
//////////////////////

template <typename T>
Vector2D<T>::Vector2D(T *set): Vector<T, 2>(T* set)
{
    // Intentionally Left Blank, call for parent constructor above
}

template <typename T>
Vector2D::Vector2D(const T &defaultValue) : Vector<T>( defaultValue )
{
    // Intentionally Left Blank, call for parent constructor above
}

template <typename T>
Vector2D::Vector2D(const T &value1, const T &value2): Vector<T,2>()
{

    (*this)[0] = value1;
    (*this)[1] = value2; // because (*ptr) derefencing must happen before []

    // SOMEONE FIGURE OUT HOW TO INITIALIZE THE MEMBER POINTER OF Vector with 2 or 3 items
}




template <typename T>
Vector3D::Vector3D(T *set): Vector(T* set)
{
    // Intentionally Left Blank, call for parent constructor above
}

template <typename T>
Vector3D::Vector3D(const T &defaultValue): Vector<T, 3>( defaultValue )
{


    // Intentionally Left Blank, call for parent constructor above
}



template <typename T>
Vector3D::Vector3D(const T &value1, const T &value2, const T &value3)
{


    (*this)[0] = value1;
    (*this)[1] = value1;
    (*this)[2] = value3; // because (*ptr) derefencing must happen before []
    // SOMEONE FIGURE OUT HOW TO INITIALIZE THE MEMBER POINTER OF Vector with 2 or 3 items

}



template <typename T>
Vector3D<T> &Vector3D::operator^=(const Vector3D<T> &RHS)
{
    // a = axb
    Vector3D<T> temp(*this);  // assuming we have copy constructor for vector 3d
    // AxB = (AyBz - AzBy)i + (AzBx - AxBz)j + (AxBy - AyBx)k
    (*this)[0] = (temp[1] * RHS[2]) - (temp[2] * RHS[1]);
    (*this)[0] = (temp[2] * RHS[0]) - (temp[0] * RHS[2]);
    (*this)[0] = (temp[0] * RHS[1]) - (temp[1] * RHS[0]);
    return(*this);


}




template <typename U>
Vector3D<U> operator^(const Vector3D<U> &LHS, const Vector3D<U> &RHS)
{
    //c = axb
    Vector3D<U> temp;
    // AxB = (AyBz - AzBy)i + (AzBx - AxBz)j + (AxBy - AyBx)k
    temp[0] = (LHS[1] * RHS[2]) - (LHS[2] * RHS[1]);
    temp[1] = (LHS[2] * RHS[0]) - (LHS[0] * RHS[2]);
    temp[2] = (LHS[0] * RHS[1]) - (LHS[1] * RHS[0]);
    return temp;



}



#endif // VECTOR_H



