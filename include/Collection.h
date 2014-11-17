#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>
#include "CollectionIterators.h"

template <typename T> class Collection;

template <class T>//, class Iterator>
struct CollectionParent {
    friend class Collection<T>;
private:
    /* Returning false from any of these functions will cancel
     * modification of the collection */
    virtual bool ItemAdded(Collection<T>* origin, const T& item)=0;
    virtual bool ItemRemoved(Collection<T>* origin, const Collection_iterator<T>& position)=0;
};

template <typename T>
class Collection {
public:
    Collection(CollectionParent<T>* initParent = NULL): parent(initParent) {}
    typedef Collection_iterator<T>                  iterator;
    typedef Collection_iterator<const T>            const_iterator;
    typedef Collection_reverse_iterator<T>          reverse_iterator;
    typedef Collection_reverse_iterator<const T>    const_reverse_iterator;
    typedef std::size_t                             size_type;
    typedef T                                       value_type;
    typedef value_type&                             reference;
    typedef const value_type&                       const_reference;

    const_reference at(size_type index) const { return items[index];}
    const_reference operator[](size_type index) const { return items[index]; }
    const_reference front() const { return items.front(); }
    const_reference back() const { return items.back(); }

    reference at(size_type index) { return items[index]; }
    reference operator[](size_type index) { return items[index]; }
    reference front() { return items.front(); }
    reference back() { return items.back(); }

    bool empty() const { return items.empty(); }
    size_type size() const { return items.size(); }

    iterator begin() { return iterator(&items,0); }
    const_iterator begin() const { return const_iterator(&items,0); }
    iterator end() { return iterator(&items,items.size()); }
    const_iterator end() const { return const_iterator(&items,items.size()); }
    reverse_iterator rbegin() { return reverse_iterator(&items,items.size()-1); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(&items,items.size()-1); }
    reverse_iterator rend() { return reverse_iterator(&items, reverse_iterator::reverse_end); }
    const_reverse_iterator rend() const { return const_reverse_iterator(&items, reverse_iterator::reverse_end); }

    void clear() {
        if(!parent)
            items.clear();
        else
            erase(begin(),end());

    }
    void erase(const iterator& position) {
        if(!parent || parent->ItemRemoved(this,position))
            std::vector<T>::erase(items.begin()+ position.index);
    }
    void erase(const iterator& first, const iterator& last) {
        for(iterator it = first; it != last; ++it)
            erase(it);
    }
    void push_back(const reference val) {
        if(!parent || parent->ItemAdded(this,val))
            items.push_back(val);
    }
    void pop_back() {
        if(!parent || parent->ItemRemoved(this,rbegin()))
            items.pop_back();
    }
    iterator insert(iterator position, const reference value) {
        if(!parent || parent->ItemAdded(this,value))
            items.insert(items.begin()+position.index,value);
        return position;
    }
    iterator insert(iterator position, size_type n, const value_type& value) {
        for(size_type i = 0; i < n; ++i)
            insert(position,value);
    }
    template <typename InputIterator>
    iterator insert(iterator position, InputIterator first, InputIterator last) {
        for(InputIterator it = first; it != last; ++it,++position)
            insert(position,*it);
        return position;
    }
private:
    CollectionParent<T>* parent;
    std::vector<T> items;
};





#endif // COLLECTION_H
