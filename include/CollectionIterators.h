#ifndef COLLECTIONITERATORS_H
#define COLLECTIONITERATORS_H

#include "Collection.h"
#include <iterator>

template <typename T> class Collection;

template <typename T>
class Collection_iterator: public std::iterator<std::random_access_iterator_tag, T> {
    friend class Collection<T>;
public:
    T& operator*() { return data->at(index); }
    T& operator[](std::size_t i) { return data->at(i); }
    const T& operator[](std::size_t i) const { return data->at(i); }
    Collection_iterator<T>& operator++() {
        ++index;
        return *this;
    }
    const Collection_iterator<T> operator++(int) {
        Collection_iterator<T> temp = *this;
        ++index;
        return temp;
    }
    Collection_iterator<T>& operator--() {
        --index;
        return *this;
    }
    const Collection_iterator<T>& operator--(int) {
        Collection_iterator<T> temp = *this;
        --index;
        return temp;
    }
    Collection_iterator<T> operator+(const std::size_t RHS) const{
        return Collection_iterator<T>(data,index+RHS);
    }
    friend Collection_iterator<T> operator+(const std::size_t LHS, const Collection_iterator<T>& RHS) {
        return RHS + LHS;
    }

    Collection_iterator<T> operator-(const std::size_t RHS) const{
        return Collection_iterator<T>(data,index-RHS);
    }
    friend Collection_iterator<T> operator-(const std::size_t LHS, const Collection_iterator<T>& RHS) {
        return RHS - LHS;
    }

    Collection_iterator<T>& operator+=(const std::size_t RHS) {
        index += RHS;
        return *this;
    }
    Collection_iterator<T>& operator-=(const std::size_t RHS) {
        index -= RHS;
        return *this;
    }
    std::size_t operator-(const Collection_iterator<T>& RHS) const{
        return index-RHS.index;
    }
    bool operator!=(const Collection_iterator<T>& RHS) const {
        return index != RHS.index;
    }
    bool operator==(const Collection_iterator<T>& RHS) const {
        return index == RHS.index;
    }
    bool operator<=(const Collection_iterator<T>& RHS) const {
        return index <= RHS.index;
    }
    bool operator<(const Collection_iterator<T>& RHS) const {
        return index < RHS.index;
    }
    bool operator>=(const Collection_iterator<T>& RHS) const {
        return index <= RHS.index;
    }
    bool operator>(const Collection_iterator<T>& RHS) const {
        return index < RHS.index;
    }
protected:
    std::size_t index;
    std::vector<T>* data;
    Collection_iterator(std::vector<T>* data, std::size_t index): index(index), data(data) {}
};

template <typename T>
class Collection_reverse_iterator: public Collection_iterator<T> {
    friend class Collection<T>;
public:
    Collection_reverse_iterator<T>& operator++() {
        Collection_iterator<T>::operator--();
        return *this;
    }
    const Collection_reverse_iterator<T> operator++(int) {
        Collection_reverse_iterator<T> temp = *this;
        Collection_iterator<T>::operator --();
        return temp;
    }
    Collection_reverse_iterator<T>& operator--() {
        Collection_iterator<T>::operator++();
        return *this;
    }
    const Collection_reverse_iterator<T>& operator--(int) {
        Collection_reverse_iterator<T> temp = *this;
        Collection_iterator<T>::operator ++();
        return temp;
    }
    Collection_reverse_iterator<T> operator+(const std::size_t RHS) const{
        Collection_reverse_iterator<T> temp = *this;
        temp += RHS;
        return temp;
    }
    friend Collection_reverse_iterator<T> operator+(const std::size_t LHS, const Collection_reverse_iterator<T>& RHS) {
        return RHS - LHS;
    }

    Collection_reverse_iterator<T> operator-(const std::size_t RHS) const{
        Collection_reverse_iterator<T> temp = *this;
        temp -= RHS;
        return temp;
    }

    friend Collection_reverse_iterator<T> operator-(const std::size_t LHS, const Collection_reverse_iterator<T>& RHS) {
        return RHS + LHS;
    }

    Collection_reverse_iterator<T>& operator+=(const std::size_t RHS) {
        Collection_iterator<T>::operator -=(RHS);
        return *this;
    }
    Collection_reverse_iterator<T>& operator-=(const std::size_t RHS) {
        Collection_iterator<T>::operator+=(RHS);
        return *this;
    }
    std::size_t operator-(const Collection_reverse_iterator<T>& RHS) const{
        Collection_iterator<T>::validate_comparison(RHS);
        return RHS.index - this->index;
    }
    bool operator<=(const Collection_reverse_iterator<T>& RHS) const {
        return Collection_iterator<T>::operator>=(RHS);
    }
    bool operator<(const Collection_reverse_iterator<T>& RHS) const {
        return Collection_iterator<T>::operator>(RHS);
    }
    bool operator>=(const Collection_reverse_iterator<T>& RHS) const {
        return Collection_iterator<T>::operator<=(RHS);
    }
    bool operator>(const Collection_reverse_iterator<T>& RHS) const {
        return Collection_iterator<T>::operator<(RHS);
    }
private:
    static const std::size_t reverse_end = ~0;
    Collection_reverse_iterator(std::vector<T>* data, std::size_t index): Collection_iterator<T>(data,index) {}
    Collection_reverse_iterator(const Collection_iterator<T>& it) {
        this->data = it.data;
        this->index = it.index-1;
    }
};


#endif // COLLECTIONITERATORS_H
