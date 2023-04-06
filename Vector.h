//
// Created by aleks on 01.04.2023.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include "Iteratlor.h"
#include <vector>
#include <cstdarg>
#include <initializer_list>
template<typename T>
class myVector: public myIterator<T>{
private:
    int capacity{};
    int size{};
    myIterator<T> head;
    myIterator<T> tail;
    std::allocator<T> allocator;
    void addingItemIssues(){
        if(empty())
            *this = myVector<T>();
        if (isFilled()) DoublemMemory();
    }
    void DoublemMemory(){
        doubleCapacity();
        reallocate();
    }
    void doubleCapacity(){
        capacity *= 2;
    }
    bool isFilled(){
        return size > capacity;
    }
    void constructVector(int _capacity){
        head = allocator.allocate(capacity);
        this->setCurrent(head.operator->());
        tail = head.operator->() + capacity;
    }
    void reallocate(){
    T* temp = head.operator->();
        head = allocator.allocate(capacity);
        for (int i = 0; i < size; ++i)
            head[i] = std::move(temp[i]);
//        allocator.deallocate(temp,size);
        this->setCurrent(head.operator->());
    }
    bool correctIndex(int index){
    return !(index < 0 || head + index > tail);
    }
    int increaseCapacity(int _size){
        capacity = 2;
        while (_size >= capacity){
            doubleCapacity();
        }
        return capacity;
    }
public:

    explicit myVector(int _size) : size(0), myIterator<T>(){
        increaseCapacity(_size);
        constructVector(capacity);
    }
    myVector() : size(0), capacity(16), myIterator<T>() {
        constructVector(16);
    }
    myVector(const std::initializer_list<int> &list): myVector(list.size())
    {
        // Инициализируем наш начальный массив значениями из списка инициализации
        for (auto &element : list)
        {
            head[size++] = element;
        }

    }

    myIterator<T>& begin() {
        return head;
    }
    const myIterator<T>& cbegin() const {
        return head;
    }
    myIterator<T>& end() {
        return head[size];
    }
    const myIterator<T>& cend() const {
        return tail;
    }

    void push_back( T value) {
        addingItemIssues();
        head[size++] = value;
    }
    T& at(int index){
        return head[index];
    }
    void erase(int index, int count = 1){
        size -= count;
        for (int i = index; i < size ; ++i) {
            head[i] = std::move(head[i + count]);
        }
    }  /** Удаление элемента **/
    void Clear(){
        allocator.deallocate(head.operator->(),size);
        size = 0;
        capacity = 0;
    }
    bool empty(){
        return  !size;
    }
    void emplace(T&& _data){
        addingItemIssues();
        head[size++] = std::move(_data);
    }
//    myVector(...):size(count), capacity(count*2), myIterator<T>(){
//        va_list list;
//        va_start(list,count);
//        for(int i = 0; i < count; i++){
//            this->push_back(va_arg(list,T));
//        }
//    }


};
#endif //VECTOR_VECTOR_H
