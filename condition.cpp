#include <iostream>
#include <typeinfo>
#include <type_traits>


using namespace std;


enum class Op {
    Resize, 
    Resize_norm, 
    Warp_norm
};


template <typename T>
void plain(T op) {
    if (op == Op::Resize) {
        cout << "Resize called!" << endl;
    }
    else if (op == Op::Resize_norm) {
        cout << " Resize_norm called!" << endl;
    }
    else if (op == Op::Warp_norm) {
        cout << "Warp_norm called!" << endl;
    }
}


template <typename T1, Op T>
typename std::enable_if<T==Op::Resize>::type
_do() {
    cout << "Resize called!" << endl;
}

template <typename T1, Op T>
typename std::enable_if<T==Op::Resize_norm>::type
_do() {
    cout << "Resize_norm called!" << endl;
}

template <typename T1, Op T>
typename std::enable_if<T==Op::Warp_norm>::type
_do() {
    cout << "Warp_norm called!" << endl;
}





template <typename T1, Op T2>
void imp1() {
    _do<T1, T2>();
}





int main(int argc, char* argv[]) {


    plain(Op::Resize_norm);

    imp1<int, Op::Warp_norm>();
    imp1<float, Op::Resize_norm>();


    return 0;
}
