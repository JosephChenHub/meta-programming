#pragma once

#include <type_traits>
#include <typeinfo>
#include <iostream>

using namespace std;

enum class Op {
    Resize,
    Resize_norm,
    Warp, 
    Warp_norm,
    Unkown
};

template <typename T>
void run1(T t);

template <typename T, typename U>
void run2(T t, U u); 


class Foo {
public:
    template <Op op, typename T>
    static typename std::enable_if<op==Op::Resize>::type run();

    template <Op op, typename T>
    static typename std::enable_if<op==Op::Resize_norm>::type run(); 

};



