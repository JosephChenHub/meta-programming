#include "instantiation.h"

template <typename T>
void run1(T t) {
    cout << "run1 called!"
        << ", type: " << typeid(t).name()
        <<endl;
}


template <typename T, typename U>
void run2(T t, U u) {
    cout << "run2 called, type-T:"
        << typeid(t).name() 
        << " type-U:" << typeid(u).name()
        << endl;
}


template <Op op, typename T>
typename std::enable_if<op==Op::Resize_norm>::type Foo::run() {
    cout << "Resize_norm called!" << endl;
}

template <Op op, typename T>
typename std::enable_if<op==Op::Resize>::type Foo::run() {
    cout << "Resize called!" << endl;
}


// ok, explict instantiation 
template void run1<int>(int t);
template void run1<float>(float t);


// wrong!
//template <typename U> void run2<int, U>(int, U);

// ok 
template void run2<float, float>(float, float);
template void run2<int, float>(int, float);
template void run2<float, int>(float, int);


// ok
template void Foo::run<Op::Resize, int>();
template void Foo::run<Op::Resize_norm, float>();
