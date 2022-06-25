// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <type_traits>
#include <xutility>
#include <iterator>

// should be used for vectors
template <typename T, std::enable_if_t<std::is_same<typename T::iterator_category, std::random_access_iterator_tag>::value, bool> = true>
    int my_distance(T a, T b) {
    std::cout << "std::is_same\n";
    return b - a;
}

// should be used for raw pointers
template <typename T>
int my_distance(T* a, T* b) {
    std::cout << "pointer\n";
    return b - a;
}

// should be used for lists
template <typename T, std::enable_if_t<!std::is_same<typename T::iterator_category, std::random_access_iterator_tag>::value, bool> = true>
int my_distance(T a, T b) {
    std::cout << "!std::is_same\n";
    int ctr = 0;
    for (T i = a; i != b; i++, ctr++);
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
