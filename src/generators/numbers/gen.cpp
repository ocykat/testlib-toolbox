#include "testlib.h"

#include <climits>
#include <iostream>
#include <random>

int TrulyRandomSeed() {
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);
    return dis(engine);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    rnd.setSeed(TrulyRandomSeed());
    println(rnd.next(1, 10));
    return 0;
}
