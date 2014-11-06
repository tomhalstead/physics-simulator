#ifndef VECTOR2D_H
#define VECTOR2D_H
#include "Vector.h"

namespace Vectors {

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
}


#endif // VECTOR2D_H



