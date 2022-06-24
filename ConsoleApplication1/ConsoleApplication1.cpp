// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <list>

// should be used for vectors
template <typename T>
int my_distance(typename std::vector<T>::iterator a, typename std::vector<T>::iterator b) {
    return b - a;
}

// should be used for raw pointers
template <typename T>
int my_distance(T* a, T* b) {
    return b - a;
}

// should be used for lists
template <typename T>
int my_distance(typename std::list<T>::iterator a, typename std::list<T>::iterator b) {
    int ctr = 0;
    for (typename std::list<T>::iterator i = a; i != b; i = i.next(), ctr++);
    return ctr;
}

int main()
{
    std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

    std::list<int> list = { 1,2,3,4,5,6,7,8,9 };

    int b[9] = { 1,2,3,4,5,6,7,8,9 };

    std::cout << my_distance(&b[0], &b[8]) << std::endl <<
        my_distance(std::next(vec.begin(), 0), std::next(vec.begin(), 8)) << std::endl <<
        my_distance(std::next(list.begin(), 0), std::next(list.begin(), 8)) << std::endl;
}
