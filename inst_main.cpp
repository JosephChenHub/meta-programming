#include "instantiation.h"


int main(int argc, char* argv[]) {

    int a = 5;
    float b = 3;
    run1<int>(a);
    run1<float>(b);

    run2(a, b);
    run2(b, a);

    Foo::run<Op::Resize, int>();
    Foo::run<Op::Resize_norm, float>();

    return 0;
}
