#ifndef VECTORS_H
#define Vectors_H

template <class T, unsigned int size>;
class Vector
{
public:
    Vector(T* set);
    Vector(const Vector& A);
    ~Vector();
    Vector<T,size>& operator = (const Vector<T,size>& RHS);
    Vector<T,size>& operator += (const Vector<T,size>& RHS);
    Vector<T,size>& operator -= (const Vector<T,size>& RHS);
//    Vector& operator ^= (const Vector& RHS);
    Vector<T,size> operator + (const Vector<T,size>& RHS) const;
    Vector<T,size> operator - (const Vector<T,size>& RHS) const;
    T operator * (const Vector<T,size>& RHS) const;
//    Vector operator ^ (const Vector& RHS) const;
    Vector<T,size>& operator *=(T C);
    friend Vector<T,size> operator *(T C, const Vector<T,size>& RHS);
    T Magnitude();
    Vector<T,size>& operator [](unsigned int index);
    const Vector<T,size>& operator [](unsigned int index) const;
private:
    T* D;
};

template <class T>
class Vector3D:public Vector<T,3>
{
    Vector3D operator ^(const Vector3D& RHS) const;
    Vector3D& operator ^=(const Vector3D& RHS);

};




#endif // VECTOR_H

