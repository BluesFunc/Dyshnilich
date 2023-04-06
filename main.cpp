#include <iostream>
#include <vector>
#include "memory"
#include "Vector.h"
#include "string"
template<typename A,typename B>
struct Pair{
    A a;
    B b;
    Pair(A _a, B _b):a(_a),b(_b){

    }
};
int main()
{
    int size = 5;
myVector<int> a {1,2,3,4,5};



   // a.Clear();



    for (int i = 0; i < size; i++) {
        std::cout << a.at(i) << ' ';
    }
}