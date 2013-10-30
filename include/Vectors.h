#ifndef VECTORS_H
#define Vectors_H

template <class T, unsigned int size>;
class Vector
{
public:
    Vector(T* set);
    Vector(const Vector& A);
    ~Vector();
    Vector& operator = (const Vector& RHS);
    Vector& operator += (const Vector& RHS);
    Vector& operator -= (const Vector& RHS);
    Vector& operator *= (const Vector& RHS);
//    Vector& operator ^= (const Vector& RHS);
    Vector operator + (const Vector& RHS) const;
    Vector operator - (const Vector& RHS) const;
    Vector operator * (const Vector& RHS) const;
//    Vector operator ^ (const Vector& RHS) const;
    Vector operator * (int C) const;
    friend Vector operator *(int C, const RHS);
    double Magnitude();
    Vector& operator [](unsigned int index);
    const Vector& operator [](unsigned int index) const;
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
