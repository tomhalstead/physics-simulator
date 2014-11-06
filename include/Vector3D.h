#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Vector.h"

namespace Vectors {
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
        friend Vector3D<U> operator^(const Vector3D<U>& LHS, const Vector3D<U>& RHS); // Cross Product
        Vector3D<T>& operator^=(const Vector3D<T>& RHS); // Cross Product w/Assignment
    };

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

}



#endif // VECTOR3D_H



