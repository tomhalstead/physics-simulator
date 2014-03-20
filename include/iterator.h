#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

#include "Vectors.h"
#include "PointMass.h"
#include "CollisionEngine.h"
#include "Connection.h"

class PhysicsEngine;

template <class T>
class PhysicsEngine::Iterator       //built for vectors filled with pointers
{
    Iterator(); //must be set by a operator = to be useful
    Iterator(Iterator<T>& CopyThis);
    Iterator(std::vector<T>& Myvector);  //only physicsEngine can use this one (as only physics engine has access to the vectors)

//these add or remove items to our vector
    void Append(const T* AddThis); //append AddThis to the end of the vector
    void Delete(T* const DeleteThis);   //remove the object from our vector, inform connections of it's removal and delete the memory allocation to it.
    void Delete(const Iterator<T>& DeleteThis);
    void Delete(unsigned int Element);

//these access the object we hold - as the vector holds pointers a further dereference(*) is needed to access the actual object (the pointers returned are const, but the object they point to are not)
    T* operator * ()const;  //dereference to currently selected element - returns a pointer or NULL if out of range
    T* operator [] (unsigned int Element)const; //returns the Element'th element without changing our internal pointing, if out of range we return NULL

//these change the interal pointing of this iterator but do not modify the vector (if dereferenced, the items pointed to in returned pointers to can however be modified):
    Iterator<T>& operator = (const Iterator<T>& Rhs);  //set to the same as another Iterator (of same type)
    Iterator<T>& operator ++ ();    //increment our internal pointing
    Iterator<T> operator ++ (int);
    Iterator<T>& operator -- ();    //decrement our internal pointing
    Iterator<T> operator -- (int);
    Iterator<T>& operator += (int Rhs); //change our pointing by the int sent
    Iterator<T>& operator -= (int Rhs);
    //if our internal pointing is moved out of range, dereference will only return NULL until reset by one of these three or a operator =
    Iterator<T>& SetTo(unsigned int Element); //sets our internal pointer to the number of passed element
    Iterator<T>& SetToFirst(); //sets our internal pointer to the first element [0]
    Iterator<T>& SetToLast(); //sets our internal pointer to the last element [*myvector.size]

//these do not change the internal pointing of this Iterator , nor the vector itself (if derefrenced, the items pointed to in returned pointers to can however be modified):
    Iterator<T> operator + (int Rhs)const;  //returns
    Iterator<T> operator - (int Rhs)const;
    Iterator<T> First()const;  //returns a Iterator<t> set to first element
    Iterator<T> Last()const;  //returns a Iterator<t> set to last element

private:
    std::vector<T*>* myvector;  //the vector we track and access
    unsigned int i; //if moved out of valid range it must be reset by a SetTo or operator =. Until then the iterator will only return NULL
};


#endif // PHYSICSENGINE_H
