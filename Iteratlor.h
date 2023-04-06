//
// Created by aleks on 02.04.2023.
//

#ifndef VECTOR_ITERATLOR_H
#define VECTOR_ITERATLOR_H
#include "iostream"

#include <iterator>
#include "memory"
#include "utility"
#include <array>
#include <tuple>
#include <iostream>
#include <vector>
#include <map>


template<typename Type>
class myIterator {
    Type *current;
public:
    Type* setCurrent(Type *curr){
        current = curr;
        return curr;
    }

    using difference_type=std::ptrdiff_t;
    using value_type = Type;
    using pointer = Type*;
    using reference = Type&;


    myIterator():current(nullptr){
    }
      myIterator(Type* _current) : current(_current) {}





    pointer operator ->() const {
        return current;
    }
    reference operator*() const {
        return *current;
    }
    reference operator[](int index)  const {
        return current[index] ;
    }
    myIterator<Type>  operator++() {
        ++current;
        return *this;
    }
    myIterator operator++(int){
        current++;
        return *this;
    }
    myIterator& operator--() {
        current--;
        return *this;
    }
    myIterator operator--(int) {
        return *(--this);
    }
    myIterator& operator+=(int num) {
        return myIterator(current += num);
    }

    myIterator& operator-=(int num) {
        return myIterator(current -= num);;
    }

    friend auto operator<=>(myIterator, myIterator) = default;
//    friend int operator-(myIterator, myIterator);
    friend myIterator operator+(myIterator ptr, int num){
        return ptr.operator->() + num;
    }


//    friend myIterator operator-(myIterator, int);

};




#endif //VECTOR_ITERATLOR_H
