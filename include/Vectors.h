
#ifndef VECTORS_H
#define VECTORS_H

template <class T, unsigned int size>
class Vector
{
public:
    Vector(T* set);
    Vector(const T& A); // Sets <size> amount of 'A' (of type T) into Vector; // Like memset???
    Vector(const Vector<T,size>& A);// Big3
    ~Vector();// Big3, Destructor
    Vector<T,size>& operator  = (const Vector<T,size>& RHS); //Big3, Assignment Op. []chk==, []del, []assign
    Vector<T,size>& operator += (const Vector<T,size>& RHS);
    Vector<T,size>& operator -= (const Vector<T,size>& RHS);
    Vector<T,size>  operator  + (const Vector<T,size>& RHS) const; // Vector Translation
    Vector<T,size>  operator  - (const Vector<T,size>& RHS) const; // Vector Translation
    Vector<T,size>  operator  * (const T& C) const; // Scalar mutiplication
    Vector<T,size>& operator *= (const T& C);       // Scalar mutiplication
    T operator * (const Vector<T,size>& RHS) const; // Dot product, This returns a scalar
    friend Vector<T,size> operator *(const T& C, const Vector<T,size>& RHS); // Scalar mutiplication
    T Magnitude(); // return the size of Vector
    Vector<T,size>& operator [](unsigned int index);
    const Vector<T,size>& operator [](unsigned int index) const;
private:
    T* D;
};

template <class T>
class Vector3D:public Vector<T,3>
{
    Vector3D<T> operator ^(const Vector3D<T>& RHS) const; // Cross Product // Can we overload the bitwise exclusive or?
    Vector3D<T>& operator ^=(const Vector3D<T>& RHS);     // Cross

};




#endif // VECTOR_H

