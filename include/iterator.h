#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

template <class T>  
class Iterator       //built for dynamic arrays filled with pointers (our template is for the object however, not the object pointers)
{
	Iterator(); //must be set by a operator = afterwards to be useful
	Iterator(Iterator<T>& CopyThis);
	Iterator(std::vector<T>& Myvector);  //should only be used in the original Iterator which has access to the private std::vector

//these add or remove items to our dynamic array
	void Append(const T* AddThis); //append AddThis to the end of the dynamic array  
	void Delete(T* const DeleteThis);   //remove the object from our dynamic array, and delete the memory allocation to it.
	void Delete(const Iterator<T>& DeleteThis);  //by other methods
	void Delete(unsigned int Element);
	void Clear();   //remove all elements from our dynamic array
//deleting a pointmass can affect connections...  when we have connections we'll need to make a child class for PointMasses

//these access the object we hold - as the vector holds pointers a further dereference(*) is needed to access the actual object (the pointers returned are const, but the object they point to are not)
//both these will do a try/catch with a NULL being returned if a throw was caught.  *** No internal error checking ***
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
	//if our internal pointing is moved out of range, it can be reset by one of these three or a operator = 
	Iterator<T>& SetTo(unsigned int Element); //sets our internal pointer to the number of passed element
	Iterator<T>& SetToFirst(); //sets our internal pointer to the first element [0]
	Iterator<T>& SetToLast(); //sets our internal pointer to the last element [*myvector.size]

//these do not change the internal pointing of this Iterator , nor the vector itself (if derefrenced, the items pointed to in returned pointers to can however be modified):
	Iterator<T> operator + (int Rhs)const;  //returns
	Iterator<T> operator - (int Rhs)const;
	Iterator<T> First()const;  //returns a Iterator<t> set to first element 
	Iterator<T> Last()const;  //returns a Iterator<t> set to last element 
	unsigned int Element()const;  //returns the element number we are pointing to
	int Find(const T* FindThis);   //returns the element number for the object sent - returns -1 if not found
private:
	std::vector<T*>* myvector;  //the vector we track and access
	unsigned int i; //our internal pointing value
};


#endif // PHYSICSENGINE_H
