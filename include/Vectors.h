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
    Vector<T,size>& operator  = (const Vector<T,size>& RHS);
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
    T* D; // Data
};

template <class T>
class Vector3D:public Vector<T,3>
{
    Vector3D<T> operator ^(const Vector3D<T>& RHS) const; // Cross Product // Can we overload the bitwise exclusive or?
    Vector3D<T>& operator ^=(const Vector3D<T>& RHS);     // Cross

};




//
// TRY NOT TO CHANGE THE NUMBER OF LINES IN THE FUNCTIONS. WE NEED TO KEEP TRACK OF LINES!
//

template <class T, unsigned int size>
Vector::Vector(T* set)
{
    // CONSTRUCTOR







}





template <class T, unsigned int size>
Vector::Vector(const T& A)
{
    // CONSTRUCTOR






}




template <class T, unsigned int size>
Vector::Vector(const Vector<T,size>& A)
{
    // COPY CONSTRUCTOR







}





template <class T, unsigned int size>
Vector::~Vector()
{
    // DESTRUCTOR







}




template <class T, unsigned int size>
Vector<T, size> &Vector::operator =(const Vector<T, size> &RHS)
{
    // 1. Check ==,
    if (RHS == this)
        return *this;
    // 2. Delete,
    for (int i = 0; i < size; i++)
        RHS[i]=0; // Reset to 0
    // 3. Reassign... from RHS to this, assured same T, size
    for (int i = 0; i < size; i++)
        this[i] = RHS[i];

    return *this;
}




template <class T, unsigned int size>
Vector<T, size> &Vector::operator +=(const Vector<T, size> &RHS)
{
    // += Member Function








}





template <class T, unsigned int size>
Vector<T, size> &Vector::operator -=(const Vector<T, size> &RHS)
{
    // -= Member Function








}




template <class T, unsigned int size>
Vector<T, size> Vector::operator +(const Vector<T, size> &RHS) const
{
    //








}




template <class T, unsigned int size>
Vector<T, size> Vector::operator -(const Vector<T, size> &RHS) const
{









}




template <class T, unsigned int size>
Vector<T, size> Vector::operator *(const T &C) const
{









}




template <class T, unsigned int size>
T Vector::Magnitude()
{







}

template <class T, unsigned int size>
Vector<T, size> &Vector::operator [](unsigned int index)
{







}

template <class T, unsigned int size>
const Vector<T, size> &Vector::operator [](unsigned int index) const
{







}




template <class T, unsigned int size>
Vector<T, size> &Vector::operator *=(const T &C)
{









}





template <class T, unsigned int size>
T Vector::operator *(const Vector<T, size> &RHS) const
{








}





// FRIEND!
template <class T, unsigned int size>
Vector<T, size> operator *(const T &C, const Vector<T, size> &RHS)
{







}





// 3D Vector!!!!!
template <class T>
Vector3D<T> Vector3D::operator ^(const Vector3D<T> &RHS) const
{








}






template <class T>
Vector3D<T> &Vector3D::operator ^=(const Vector3D<T> &RHS)
{








}

#endif // VECTOR_H


