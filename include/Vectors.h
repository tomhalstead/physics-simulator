
#ifndef VECTORS_H
#define VECTORS_H

template <class T, unsigned int size>
class Vector
{
public:
    Vector(T* set);
    Vector(const T& A); // set <size> amount of 'A' in type T to Vector;
    Vector(const Vector<T,size>& A);// Big3
    ~Vector();// Big3
    Vector<T,size>& operator = (const Vector<T,size>& RHS); // Big3
    Vector<T,size>& operator += (const Vector<T,size>& RHS);
    Vector<T,size>& operator -= (const Vector<T,size>& RHS);
    Vector<T,size> operator + (const Vector<T,size>& RHS) const;
    Vector<T,size> operator - (const Vector<T,size>& RHS) const;
    T operator * (const Vector<T,size>& RHS) const; // Dot product, return a scalar
    Vector<T,size> operator * (const T& C) const; // scalar mutiplication
    Vector<T,size>& operator *=(const T& C); // Scalar mutiplication
    friend Vector<T,size> operator *(const T& C, const Vector<T,size>& RHS); // scalar mutiplication
    T Magnitude(); // return the size of Vector
    Vector<T,size>& operator [](unsigned int index);
    const Vector<T,size>& operator [](unsigned int index) const;
private:
    T* D;
};

template <class T>
class Vector3D:public Vector<T,3>
{
    Vector3D<T> operator ^(const Vector3D<T>& RHS) const; // cross product
    Vector3D<T>& operator ^=(const Vector3D<T>& RHS);

};




#endif // VECTOR_H

