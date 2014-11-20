#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
namespace Vectors {
    typedef std::size_t size_type;


    template <typename T, size_type size>
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

        Vector<T,size>& operator[](size_type index);
        const Vector<T,size>& operator[](size_type index) const;

        Vector<T,size>& operator+=(const Vector<T,size> &RHS);
        Vector<T,size>& operator-=(const Vector<T,size> &RHS);

        Vector<T,size> operator+(const Vector<T,size> &RHS) const;
        Vector<T,size> operator-(const Vector<T,size> &RHS) const;

        T operator*(const Vector<T,size>& RHS) const;
        // Dot Product

        Vector<T,size> operator*(const T& scalar);
        // Scalar Multiplication

        template <typename U, size_type sz>
        friend Vector<U,sz> operator*(const U& scalar, const Vector<U,sz>& vector);
        // Scalar mutiplication

        Vector<T,size>& operator*=(const T& RHS);
        // Scalar mutiplication


    private:
        T* storage;
    };

    template <class T, size_type size>
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





    template <class T, size_type size>
    Vector<T, size>::Vector(const T& A)
    {
        // CONSTRUCTOR



        storage = new T[size];
        for(size_type i = 0; i < size; i++)
            storage[i] = A;   // A is a value of type T

    }




    template <class T, size_type size>
    Vector<T, size>::Vector(const Vector<T,size>& A)
    {
        // COPY CONSTRUCTOR

        storage = new T[size]; // ensuring correct size of Vector values
        for (int i = 0; i < size; i++)
        {
            this->storage[i] = A.storage[i];
        }


    }

    template <class T, size_type size>
    Vector<T, size> &Vector<T, size>::operator=(const Vector<T, size> &RHS)
    {
        // ASSIGNMENT OPERATOR
        if (this == RHS)
            return *this;
        if (this->storage)
            delete [] this; // we are assuming size > 0
        storage = new T[size]; // ensuring correct size of Vector values
        for (int i = 0; i < size; i++)
        {
            this->storage[i] = RHS.storage[i];
        }
        return *this;

    }



    template <class T, size_type size>
    Vector<T, size>::~Vector()
    {
        // DESTRUCTOR
        if (storage)
        {
            delete [] storage; // is there a destroy PointMass callback?
        }


    }




    template <class T, size_type size>
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


    template <typename T, size_t size>
    T Vector<T,size>::operator*(const Vector<T,size>& RHS) const
    {


        T sum = 0;
        for (size_type i = 0; i < size; i++)
        {
            sum = (storage[i] * RHS.storage[i] ) + sum;
        }
        return sum;


    }

    template <class T, size_type size>
    Vector<T, size> &Vector<T, size>::operator[](size_type index)
    {


        return storage[index];
    }




    template <class T, size_type size>
    const Vector<T, size> &Vector<T, size>::operator[](size_type index) const
    {







        return storage[index];

    }




    template <class T, size_type size>
    Vector<T, size> &Vector<T, size>::operator+=(const Vector<T, size> &RHS)
    {



        for (int n = 0; n < size; ++n)
            storage[n] += RHS.storage[n];
        return *this;




    }



    template <class T, size_type size>
    Vector<T, size> &Vector<T, size>::operator-=(const Vector<T, size> &RHS)
    {

        for (int n = 0; n < size; ++n)
            storage[n] -= RHS.storage[n];
        return *this;







    }




    template <class T, size_type size>
    Vector<T, size> &Vector<T, size>::operator*=(const T &RHS)
    {


        for (int n = 0; n < size; ++n)
            storage[n] *= RHS.storage[n];
        return *this;





    }




    template<typename T, size_type size>
    Vector<T, size> Vector<T,size>::operator+(const Vector<T, size> &RHS) const
    {






    }





    template <typename T, size_type size>
    Vector<T, size> Vector<T,size>::operator-(const Vector<T, size> &RHS) const
    {






    }




    template <typename T, size_type size>
    Vector<T, size> Vector<T,size>::operator*(const T &theScalar)
    {
        Vector<T,size> temp;
        for (size_type i = 0; i < size; i++)
        {
            temp[i] = theScalar * storage[i];
        }
        return temp;


    }



    template <typename T, size_type size>
    Vector<T, size> operator*(const T &theScalar, const Vector<T, size> &theVector)
    {
        Vector<T,size> temp;
        for (size_type i = 0; i <size; i++)
        {
            temp[i] = theScalar * theVector[i];
        }
        return temp;

    }
}

#endif // VECTOR_H



