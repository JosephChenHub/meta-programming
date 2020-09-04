#include <iostream>


using namespace std;


template <size_t n>
class factorial {
public:
    enum {
        value = n * factorial<n-1>::value
    };
};

template <>
class factorial<0> {
public:
    enum {
        value = 1
    };
};

// executed in compile time not run time
constexpr size_t factorial2(size_t n) {
    return (n == 0) ? 1 : n * factorial2(n - 1);
}



int main(int argc, char* argv[]) {


    cout << factorial<7>::value << endl; // equals to cout << 7! << endl;

    // error : num is not constant
    //int num = 3;
    //cout << factorial<num>::value << endl; 

    const int num = 10;
    cout << factorial<num>::value << endl; // equals to cout << 10! << endl;

    cout << factorial2(10) << endl;

    int a = 10;
    cout << factorial2(a) << endl;
    int arr[factorial2(a)];

    return 0;
}
